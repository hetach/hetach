/*
 * Copyright (C) 2016 Gracjan Orzechowski
 *
 * This file is part of Hetach
 *
 * Hetach is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Hetach; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include <regex>
#include <sstream>
#include <vector>
#include <iostream>

#include "router/router.h"
#include "router/params.h"
#include "router/resourcenotfoundexception.h"

using namespace std;
using namespace Hetach::Router;

Router::Router()
{
    this->m_compiler = new RouteCompiler();
}

void Router::addRoute(Route *route)
{
    this->m_routes.insert(make_pair(route, this->m_compiler->compile(route)));
}

Resource* Router::match(string path)
{
    vector<string> parts;

    stringstream ss;
    ss.str(path);

    string item;

    while(getline(ss, item, '/')) {
        if(item.size() == 0) {
            continue;
        }

        parts.push_back(item);
    }

    for(map<Route*, CompiledRoute*>::iterator it = this->m_routes.begin(); it != this->m_routes.end(); ++it) {
        Route *route = it->first;
        CompiledRoute *compiled = it->second;
        map<string, string> routeParams;

        if(path == route->path()) {
            return new Resource(route, compiled, new Params(routeParams));
        }

        if(parts.size() != compiled->parts()->size()) {
            continue;
        }

        string pathPart, routePart;
        char first, last;

        for(int i = 0; i < parts.size(); i++) {
            pathPart = parts.at(i);
            routePart = compiled->parts()->at(i);

            first = routePart.front();
            last = routePart.back();

            if(pathPart != routePart && first != '{' && last != '}') {
                routeParams.clear();
                break;
            }

            if(first == '{' && last == '}') {
                routeParams.insert(make_pair(routePart.substr(1, routePart.size() - 2), pathPart));
            }
        }

        if(routeParams.size() == 0) {
            continue;
        }

        return new Resource(route, compiled, new Params(routeParams));
    }

    throw ResourceNotFoundException();
}

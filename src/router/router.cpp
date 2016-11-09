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
    for(map<Route*, CompiledRoute*>::iterator it = this->m_routes.begin(); it != this->m_routes.end(); ++it) {
        Route *route = it->first;
        CompiledRoute *compiled = it->second;
        map<string, string> routeParams;

        if(path == route->path()) {
            return new Resource(route, compiled, new Params(routeParams));
        }

        smatch sm;
        regex reg(compiled->pattern());
        regex_match(path, sm, reg);

        if(sm.size() < 1) {
            continue;
        }

        for(int i = 1; i < sm.size(); i++) {
            string name = compiled->pathVariables()[i - 1];
            string value = sm[i];

            routeParams.insert(make_pair(name, value));
        }

        return new Resource(route, compiled, new Params(routeParams));
    }

    throw ResourceNotFoundException();
}

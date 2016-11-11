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
#include <iterator>

#include "router/routecompiler.h"

using namespace std;
using namespace Hetach::Router;

RouteCompiler::RouteCompiler()
{

}

CompiledRoute* RouteCompiler::compile(Route *route)
{
    vector<string> *pathVariables = new vector<string>();

    vector<string> *parts = new vector<string>();

    stringstream ss;
    ss.str(route->path());

    string item;

    char first, last;

    while(getline(ss, item, '/')) {
        if(item.size() == 0) {
            continue;
        }

        parts->push_back(item);

        first = item.front();
        last = item.back();

        if(first == '{' && last == '}') {
            pathVariables->push_back(item.substr(1, item.size() - 2));
        }
    }

    return new CompiledRoute(pathVariables, parts, route->path());
}

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
#include <iterator>

#include "router/routecompiler.h"

using namespace std;
using namespace Hetach::Router;

RouteCompiler::RouteCompiler()
{

}

CompiledRoute* RouteCompiler::compile(Route *route)
{
    vector<string> pathVariables;

    string pattern = "^";

    smatch res;
    string s = route->path();
    regex reg("(?:\\{[a-zA-Z]+\\})");
    string parsed = regex_replace(s, reg, RouteCompiler::paramRegex());

    while(regex_search(s, res, reg)) {
        for(string match:res) {
            pathVariables.push_back(match.substr(1, match.size() - 2));
        }

        s = res.suffix().str();
    }

    pattern.append(parsed);

    pattern.append("$");

    return new CompiledRoute(pathVariables, pattern, route->path());
}

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

#include <string>
#include <vector>

#include "hetach/router/routecompiler.h"
#include "hetach/router/routepart.h"

using namespace std;
using namespace Hetach::Router;

RouteCompiler::RouteCompiler()
{

}

CompiledRoute* RouteCompiler::compile(Route *route)
{
    vector<string> *pathVariables = new vector<string>();

    vector<RoutePart*> *parts = new vector<RoutePart*>();

    for(int i = 0; i < route->parts().size(); i++) {
        RoutePart routePart = route->parts().at(i);

        RoutePart *part = new RoutePart(routePart.name(), routePart.isParameter());

        parts->push_back(part);

        if(part->isParameter()) {
            pathVariables->push_back(part->name());
        }
    }

    return new CompiledRoute(pathVariables, parts, route->path());
}

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

#include "router/fixtures/routecompilerfixture.h"

using namespace std;
using namespace Hetach::Router;

TEST_F(RouteCompilerFixture, testCompileRoute)
{
    for(map<Route*, CompiledRoute*>::iterator it = routes.begin(); it != routes.end(); ++it) {
        Route *route = dynamic_cast<Route*>(it->first);
        CompiledRoute *expectedCompiledRoute = dynamic_cast<CompiledRoute*>(it->second);
        CompiledRoute *compiledRoute = routeCompiler->compile(route);

        for(int i = 0; i < expectedCompiledRoute->parts()->size(); i++) {
            RoutePart *expectedPart = expectedCompiledRoute->parts()->at(i);
            RoutePart *routePart = compiledRoute->parts()->at(i);

            EXPECT_EQ(expectedPart->name(), routePart->name());
            EXPECT_EQ(expectedPart->isParameter(), routePart->isParameter());
        }

        EXPECT_EQ(*expectedCompiledRoute->pathVariables(), *compiledRoute->pathVariables());
    }
}

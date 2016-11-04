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

#ifndef ROUTER_FIXTURES_COMPILEDROUTEFIXTURE_H
#define ROUTER_FIXTURES_COMPILEDROUTEFIXTURE_H

#include <list>

#include "gtest/gtest.h"
#include "router/compiledroute.h"

class CompiledRouteFixture: public testing::Test
{
public:
    Hetach::Router::CompiledRoute *compiledRoute;
    std::string pattern;
    std::string rawPath;
    std::vector<std::string> pathVariables;

    CompiledRouteFixture()
    {
        pattern = "/some/route/(.*)";
        rawPath = "/some/route/{param}";
        pathVariables = {
            "name"
        };

        compiledRoute = new Hetach::Router::CompiledRoute(pathVariables, pattern, rawPath);
    }

    ~CompiledRouteFixture()
    {
        delete compiledRoute;
    }
};

#endif // ROUTER_FIXTURES_COMPILEDROUTEFIXTURE_H

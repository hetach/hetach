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

#ifndef ROUTER_FIXTURES_ROUTECOMPILERFIXTURE_H
#define ROUTER_FIXTURES_ROUTECOMPILERFIXTURE_H

#include "gtest/gtest.h"
#include "router/routecompiler.h"

class RouteCompilerFixture: public testing::Test
{
public:
    Hetach::Router::RouteCompiler *routeCompiler;
    std::map<Hetach::Router::Route*, Hetach::Router::CompiledRoute*> routes;

    RouteCompilerFixture()
    {
        routeCompiler = new Hetach::Router::RouteCompiler();
        
        routes.insert(std::make_pair(
            new Hetach::Router::Route("/some/path"),
            new Hetach::Router::CompiledRoute(std::vector<std::string>(), "^/some/path$", "/some/path")
        ));
        
        routes.insert(std::make_pair(
            new Hetach::Router::Route("/some/path/{name}"),
            new Hetach::Router::CompiledRoute(
              std::vector<std::string>({"name"}),
              "^/some/path/" + Hetach::Router::RouteCompiler::paramRegex() + "$",
              "/some/path/{name}"
            )
        ));

        routes.insert(std::make_pair(
            new Hetach::Router::Route("/some/path/{name}/{param}"),
            new Hetach::Router::CompiledRoute(
              std::vector<std::string>({"name", "param"}),
              "^/some/path/" + Hetach::Router::RouteCompiler::paramRegex() + "/" + Hetach::Router::RouteCompiler::paramRegex() + "$",
              "/some/path/{name}/{param}"
            )
        ));

        routes.insert(std::make_pair(
            new Hetach::Router::Route("/some/{name}/path/{param}"),
            new Hetach::Router::CompiledRoute(
              std::vector<std::string>({"name", "param"}),
              "^/some/" + Hetach::Router::RouteCompiler::paramRegex() + "/path/" + Hetach::Router::RouteCompiler::paramRegex() + "$",
              "/some/{name}/path/{param}"
            )
        ));
    }

    ~RouteCompilerFixture()
    {
        routes.clear();
        delete routeCompiler;
    }
};

#endif // ROUTER_FIXTURES_ROUTECOMPILERFIXTURE_H

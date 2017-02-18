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

#ifndef ROUTER_FIXTURES_RESOURCEFIXTURE_H
#define ROUTER_FIXTURES_RESOURCEFIXTURE_H

#include "gtest/gtest.h"
#include "router/fixtures/compiledroutefixture.h"
#include "hetach/router/resource.h"

class ResourceFixture: public CompiledRouteFixture
{
public:
    Hetach::Router::Resource *resource;

    ResourceFixture(): CompiledRouteFixture()
    {
        resource = new Hetach::Router::Resource(
            new Hetach::Router::Route(rawPath),
            compiledRoute,
            new Hetach::Router::Params(std::map<std::string, std::string>({std::make_pair("param", "value")}))
        );
    }

    ~ResourceFixture()
    {
        delete resource;
    }
};

#endif // ROUTER_FIXTURES_RESOURCEFIXTURE_H

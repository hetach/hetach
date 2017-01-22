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

#include "router/paramnotfoundexception.h"
#include "router/fixtures/resourcefixture.h"

TEST_F(ResourceFixture, testGetRoute)
{
    EXPECT_EQ(rawPath, resource->route()->path());
}

TEST_F(ResourceFixture, testGetCompiledRoute)
{
    EXPECT_EQ(compiledRoute, resource->compiledRoute());
}

TEST_F(ResourceFixture, testGetRouteParams)
{
    EXPECT_EQ("value", resource->routeParams()->value("param"));
}

TEST_F(ResourceFixture, testThrowExceptionWhenRouteParamNotFound)
{
    EXPECT_THROW(resource->routeParams()->value("param2"), Hetach::Router::ParamNotFoundException);
}

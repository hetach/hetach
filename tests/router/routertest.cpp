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

#include "router/resourcenotfoundexception.h"
#include "router/fixtures/routerfixture.h"

using namespace std;
using namespace Hetach::Router;

TEST_F(RouterFixture, testRouteNotMatched)
{
    EXPECT_THROW(router->match("/user"), ResourceNotFoundException);
}

TEST_F(RouterFixture, testSimpleRouteMatched)
{
    Resource *resource = router->match("/users");

    vector<string> pathVariables;

    string rawPath = "/users";

    EXPECT_EQ(rawPath, resource->route()->path());
    EXPECT_EQ(pathVariables, *resource->compiledRoute()->pathVariables());
}

TEST_F(RouterFixture, testParametrizedRouteMatched)
{
    Resource *resource = router->match("/users/123");

    vector<string> pathVariables = {"id"};

    string rawPath = "/users/{id}";

    EXPECT_EQ(rawPath, resource->route()->path());
    EXPECT_EQ(pathVariables, *resource->compiledRoute()->pathVariables());
    EXPECT_EQ("123", resource->routeParams()->value("id"));

    resource = router->match("/companies/1000/users/123");

    pathVariables = {"companyId", "userId"};

    rawPath = "/companies/{companyId}/users/{userId}";

    EXPECT_EQ(rawPath, resource->route()->path());
    EXPECT_EQ(pathVariables, *resource->compiledRoute()->pathVariables());
    EXPECT_EQ("1000", resource->routeParams()->value("companyId"));
    EXPECT_EQ("123", resource->routeParams()->value("userId"));
}

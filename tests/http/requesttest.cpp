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

#include "http/fixtures/requestfixture.h"
#include "http/header.h"

using namespace std;
using namespace Hetach::Http;

TEST_F(RequestFixture, testGetMethod)
{
    EXPECT_EQ(Request::METHOD_GET, noContentRequest->method());
    EXPECT_EQ(Request::METHOD_GET, contentRequest->method());
}

TEST_F(RequestFixture, testGetPath)
{
    EXPECT_EQ(path, noContentRequest->path());
    EXPECT_EQ(path, contentRequest->path());
}

TEST_F(RequestFixture, testGetContent)
{
    EXPECT_EQ("", noContentRequest->content());
    EXPECT_EQ(content, contentRequest->content());
}

TEST_F(RequestFixture, testMethodFromString)
{
    for(map<string, int>::iterator it = methods.begin(); it != methods.end(); ++it) {
        string methodString = static_cast<string>(it->first);
        int method = static_cast<int>(it->second);

        EXPECT_EQ(method, Request::methodFromString(methodString));
    }
}

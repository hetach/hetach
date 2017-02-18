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

#include "http/fixtures/responsefixture.h"
#include "hetach/http/header.h"

#include "gtest/gtest.h"

using namespace std;
using namespace Hetach::Http;

TEST_F(ResponseFixture, testDefaultHeaders)
{
    vector<Header> headers = response->headers();

    Header first = static_cast<Header>(headers.front());

    EXPECT_EQ(1, headers.size());
    EXPECT_EQ(contentType->name(), first.name());
    EXPECT_EQ(contentType->value(), first.value());
}

TEST_F(ResponseFixture, testDefaultContent)
{
    EXPECT_EQ("", response->content());
}

TEST_F(ResponseFixture, testDefaultStatusCode)
{
    EXPECT_EQ(200, response->statusCode());
}

TEST_F(ResponseFixture, testSetStatusCode)
{
    response->setStatusCode(500);

    EXPECT_EQ(500, response->statusCode());
}

TEST_F(ResponseFixture, testAddHeader)
{
    response->addHeader(*customHeader);

    Header last = static_cast<Header>(response->headers().back());

    EXPECT_EQ(2, response->headers().size());
    EXPECT_EQ(customHeader->name(), last.name());
    EXPECT_EQ(customHeader->value(), last.value());
}

TEST_F(ResponseFixture, testReplaceHeader)
{
    response->addHeader(Header(contentType->name(), "test"));

    Header first = static_cast<Header>(response->headers().front());

    EXPECT_EQ(1, response->headers().size());
    EXPECT_EQ(contentType->name(), first.name());
    EXPECT_EQ("test", first.value());
}

TEST_F(ResponseFixture, testSetContent)
{
    response->setContent("some content");

    EXPECT_EQ("some content", response->content());
}

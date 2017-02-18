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

#ifndef HTTP_FIXTURES_REQUESTFIXTURE_H
#define HTTP_FIXTURES_REQUESTFIXTURE_H

#include "gtest/gtest.h"
#include "hetach/http/request.h"

class RequestFixture: public testing::Test
{
public:
    Hetach::Http::Request *noContentRequest;
    Hetach::Http::Request *contentRequest;

    std::string path = "/some/path";
    std::string content = "some content";

    std::map<std::string, int> methods;

    RequestFixture()
    {
        noContentRequest = new Hetach::Http::Request(Hetach::Http::Request::METHOD_GET, path);
        contentRequest = new Hetach::Http::Request(Hetach::Http::Request::METHOD_GET, path, content);

        methods.insert(std::make_pair("GET", Hetach::Http::Request::METHOD_GET));
        methods.insert(std::make_pair("POST", Hetach::Http::Request::METHOD_POST));
        methods.insert(std::make_pair("PUT", Hetach::Http::Request::METHOD_PUT));
        methods.insert(std::make_pair("PATCH", Hetach::Http::Request::METHOD_PATCH));
        methods.insert(std::make_pair("DELETE", Hetach::Http::Request::METHOD_DELETE));
        methods.insert(std::make_pair("OPTIONS", Hetach::Http::Request::METHOD_OPTIONS));
    }

    ~RequestFixture()
    {
        delete noContentRequest;
        delete contentRequest;
    }
};

#endif // HTTP_FIXTURES_REQUESTFIXTURE_H


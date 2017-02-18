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

#ifndef HTTP_FIXTURES_RESPONSEFIXTURE_H
#define HTTP_FIXTURES_RESPONSEFIXTURE_H

#include "gtest/gtest.h"
#include "hetach/http/response.h"
#include "hetach/http/header.h"

class ResponseFixture: public testing::Test
{
public:
    Hetach::Http::Response *response;
    Hetach::Http::Header *contentType;
    Hetach::Http::Header *status;
    Hetach::Http::Header *customHeader;

    ResponseFixture()
    {
        response = new Hetach::Http::Response();
        contentType = new Hetach::Http::Header("Content-type", "text/html");
        status = new Hetach::Http::Header("Status", "200");
        customHeader = new Hetach::Http::Header("name", "value");
    }

    ~ResponseFixture()
    {
        delete response;
    }
};

#endif // HTTP_FIXTURES_RESPONSEFIXTURE_H


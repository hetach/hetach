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

#ifndef HTTPKERNEL_FIXTURES_RESPONSEFIXTURE_H
#define HTTPKERNEL_FIXTURES_RESPONSEFIXTURE_H

#include "gtest/gtest.h"
#include "http-kernel/response.h"
#include "http-kernel/header.h"

class ResponseFixture: public testing::Test
{
public:
    Hetach::HttpKernel::Response *response;
    Hetach::HttpKernel::Header *contentType;
    Hetach::HttpKernel::Header *status;
    Hetach::HttpKernel::Header *customHeader;

    ResponseFixture()
    {
        response = new Hetach::HttpKernel::Response();
        contentType = new Hetach::HttpKernel::Header("Content-type", "text/html");
        status = new Hetach::HttpKernel::Header("Status", "200");
        customHeader = new Hetach::HttpKernel::Header("name", "value");
    }

    ~ResponseFixture()
    {
        delete response;
    }
};

#endif // HTTPKERNEL_FIXTURES_RESPONSEFIXTURE_H


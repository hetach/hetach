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

#ifndef HTTP_FIXTURES_HEADERFIXTURE_H
#define HTTP_FIXTURES_HEADERFIXTURE_H

#include "gtest/gtest.h"
#include "hetach/http/header.h"

class HeaderFixture: public testing::Test
{
public:
    Hetach::Http::Header *headerOne;
    Hetach::Http::Header *headerTwo;

    HeaderFixture()
    {
        headerOne = new Hetach::Http::Header("One", "1");
        headerTwo = new Hetach::Http::Header("Two", 2);
    }

    ~HeaderFixture()
    {
        delete headerOne;
        delete headerTwo;
    }
};

#endif // HTTP_FIXTURES_HEADERFIXTURE_H


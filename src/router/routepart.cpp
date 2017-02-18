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

#include "hetach/router/routepart.h"

using namespace std;
using namespace Hetach::Router;

RoutePart::RoutePart()
{

}

RoutePart::RoutePart(std::string name, bool isParameter)
{
    this->m_name = name;
    this->m_isParameter = isParameter;
}

RoutePart* RoutePart::createFromString(string data)
{
    char first = data.front();
    char last = data.back();

    if(first == '{' && last == '}') {
        return new RoutePart(data.substr(1, data.size() - 2), true);
    }

    return new RoutePart(data, false);
}

string RoutePart::name()
{
    return this->m_name;
}

bool RoutePart::isParameter()
{
    return this->m_isParameter;
}

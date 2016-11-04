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

#include "http-kernel/header.h"

using namespace std;
using namespace Hetach::HttpKernel;

Header::Header(string name, string value)
{
    this->m_name = name;
    this->m_value = value;
}

Header::Header(string name, int value)
{
    this->m_name = name;
    this->m_value = to_string(value);
}

string Header::name()
{
    return this->m_name;
}

string Header::value()
{
    return this->m_value;
}

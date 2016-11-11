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

#include "router/compiledroute.h"

using namespace std;
using namespace Hetach::Router;

CompiledRoute::CompiledRoute(vector<string> *pathVariables, vector<string> *parts, string rawPath)
{
    this->m_pathVariables = pathVariables;
    this->m_parts = parts;
    this->m_rawPath = rawPath;
}

vector<string>* CompiledRoute::pathVariables()
{
    return this->m_pathVariables;
}

vector<string>* CompiledRoute::parts()
{
    return this->m_parts;
}

string CompiledRoute::rawPath()
{
    return this->m_rawPath;
}

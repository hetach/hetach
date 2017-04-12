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

#include <string>

#include <hetach/http-kernel/methodnotimplementedexception.h>

#include "hetach/api-rest/resource.h"

using namespace Hetach::ApiRest;
using namespace Hetach::HttpKernel;
using namespace std;

Resource::Resource()
{

}

Entity* Resource::fetch(std::string)
{
    throw MethodNotImplementedException();
}

EntityCollection* Resource::fetchAll()
{
    throw MethodNotImplementedException();
}

Entity* Resource::create(string)
{
    throw MethodNotImplementedException();
}

Entity* Resource::update(std::string, string)
{
    throw MethodNotImplementedException();
}

EntityCollection* Resource::update(string)
{
    throw MethodNotImplementedException();
}

Entity* Resource::replace(std::string, string)
{
    throw MethodNotImplementedException();
}

EntityCollection* Resource::replace(string)
{
    throw MethodNotImplementedException();
}

Entity* Resource::remove(std::string)
{
    throw MethodNotImplementedException();
}

EntityCollection* Resource::remove()
{
    throw MethodNotImplementedException();
}

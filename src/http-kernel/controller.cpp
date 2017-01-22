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

#include "http/request.h"
#include "http/response.h"
#include "http-kernel/methodunknownexception.h"
#include "http-kernel/methodnotimplementedexception.h"
#include "http-kernel/controller.h"

#include "router/params.h"

using namespace std;
using namespace Hetach::HttpKernel;
using namespace Hetach::Http;

Controller::Controller()
{

}

void Controller::doGet()
{
    throw MethodNotImplementedException();
}

void Controller::doPost(string)
{
    throw MethodNotImplementedException();
}

void Controller::doPut(string)
{
    throw MethodNotImplementedException();
}

void Controller::doPatch(string)
{
    throw MethodNotImplementedException();
}

void Controller::doDelete()
{
    throw MethodNotImplementedException();
}

void Controller::doOptions()
{
    throw MethodNotImplementedException();
}

void Controller::handle(Request *request, Response *response, Hetach::Router::Params *routeParams)
{
    this->m_request = request;
    this->m_routeParams = routeParams;
    this->m_response = response;

    switch (request->method()) {
        case Request::METHOD_GET:
            this->doGet();
            break;

        case Request::METHOD_POST:
            this->doPost(this->m_request->content());
            break;

        case Request::METHOD_PUT:
            this->doPut(this->m_request->content());
            break;

        case Request::METHOD_PATCH:
            this->doPatch(this->m_request->content());
            break;

        case Request::METHOD_DELETE:
            this->doDelete();
            break;

        case Request::METHOD_OPTIONS:
            this->doOptions();
            break;

        default:
            throw MethodUnknownException();
            break;
    }
}

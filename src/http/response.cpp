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

#include "http/response.h"
#include "http/header.h"
#include "http-kernel/headernotfoundexception.h"

using namespace std;
using namespace Hetach::Http;
using namespace Hetach::HttpKernel;

Response::Response()
{
    this->m_statusCode = 200;

    this->addDefaultHeaders();
}

void Response::addDefaultHeaders()
{
    this->addHeader(Header("Content-type", "text/html"));
}

void Response::setContent(string content)
{
    this->m_content = content;
}

string Response::content()
{
    return this->m_content;
}

std::vector<Header> Response::headers()
{
    return this->m_headers;
}

Header Response::header(string name)
{
    for(vector<Header>::iterator it = this->m_headers.begin(); it != this->m_headers.end(); ++it) {
        Header header = static_cast<Header>(*it);

        if(header.name() == name) {
            return header;
        }
    }

    throw HeaderNotFoundException();
}

void Response::addHeader(Header newHeader)
{
    for(vector<Header>::iterator it = this->m_headers.begin(); it != this->m_headers.end(); ++it) {
        Header header = static_cast<Header>(*it);

        if(header.name() == newHeader.name()) {
            (*it) = newHeader;

            return;
        }
    }

    this->m_headers.push_back(newHeader);
}

void Response::setStatusCode(int code)
{
    this->m_statusCode = code;
}

int Response::statusCode()
{
    return this->m_statusCode;
}

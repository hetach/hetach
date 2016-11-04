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

#include "http-kernel/request.h"

using namespace std;
using namespace Hetach::HttpKernel;

Request::Request(int method, std::string path, std::string content)
{
    this->m_method = method;
    this->m_path = path;
    this->m_content = content;
}

Request* Request::create(FCGX_Request *request)
{
    int method = Request::methodFromString(string(FCGX_GetParam("REQUEST_METHOD", request->envp)));
    string path = string(FCGX_GetParam("REQUEST_URI", request->envp));
    string content = "";

    int len = atoi(FCGX_GetParam("CONTENT_LENGTH", request->envp));

    if(len > 0) {
        char *str = new char[len];

        FCGX_GetStr(str, len, request->in);

        content = string(str);
    }

    return new Request(method, path, content);
}

int Request::methodFromString(string method)
{
    if(method == "GET") {
        return Request::METHOD_GET;
    } else if(method == "POST") {
        return Request::METHOD_POST;
    } else if(method == "PUT") {
        return Request::METHOD_PUT;
    } else if(method == "PATCH") {
        return Request::METHOD_PATCH;
    } else if(method == "DELETE") {
        return Request::METHOD_DELETE;
    } else if(method == "OPTIONS") {
        return Request::METHOD_OPTIONS;
    }

    return Request::METHOD_UNKNOWN;
}

int Request::method()
{
    return this->m_method;
}

string Request::path()
{
    return this->m_path;
}

string Request::content()
{
    return this->m_content;
}

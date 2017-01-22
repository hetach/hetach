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

#include <cstring>

#include "http/request.h"

using namespace std;
using namespace Hetach::Http;

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
        content = content.substr(0, len);

        delete str;
    }

    return new Request(method, path, content);
}

Request* Request::create(evhttp_request *request)
{
    int method = Request::methodFromHttpCommand(evhttp_request_get_command(request));
    string path = evhttp_request_get_uri(request);
    string content = "";

    evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
    size_t len = evbuffer_get_length(requestBuffer);

    if(len > 0) {
        char *str = new char[len];

        evbuffer_copyout(requestBuffer, str, len);

        content = string(str);
        content = content.substr(0, len);

        delete str;
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

int Request::methodFromHttpCommand(int method)
{
    switch(method) {
        case EVHTTP_REQ_GET:
            return Request::METHOD_GET;

        case EVHTTP_REQ_POST:
            return Request::METHOD_POST;

        case EVHTTP_REQ_PUT:
            return Request::METHOD_PUT;

        case EVHTTP_REQ_PATCH:
            return Request::METHOD_PATCH;

        case EVHTTP_REQ_DELETE:
            return Request::METHOD_DELETE;

        case EVHTTP_REQ_OPTIONS:
            return Request::METHOD_OPTIONS;

        default:
            return Request::METHOD_UNKNOWN;
    }
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

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

#include <list>
#include <unistd.h>

#include "fcgiapplication.h"

#include "http/header.h"
#include "http/request.h"
#include "http/response.h"
#include "http-kernel/kernel.h"

using namespace std;
using namespace Hetach;
using namespace Http;

void FCGIApplication::boot()
{
    this->m_fcgiRequest = new FCGX_Request();

    FCGX_Init();
    FCGX_InitRequest(this->m_fcgiRequest, 0, 0);

    Request *request;
    Response *response;

    while(FCGX_Accept_r(this->m_fcgiRequest) == 0) {
        request = Request::create(this->m_fcgiRequest);

        response = this->m_kernel->handle(request);

        string status = Header("Status", response->statusCode()).toString() + "\r\n";

        FCGX_PutStr(status.data(), status.size(), this->m_fcgiRequest->out);

        vector<Header> headers = response->headers();

        for(vector<Header>::iterator it = headers.begin(); it != headers.end(); ++it) {
            Header header = static_cast<Header>(*it);

            string data = header.toString() + "\r\n";

            FCGX_PutStr(data.data(), data.size(), this->m_fcgiRequest->out);
        }

        string content = "\r\n" + response->content();

        FCGX_PutStr(content.data(), content.size(), this->m_fcgiRequest->out);

        delete request;
        delete response;
    }
}

void FCGIApplication::quit()
{
    close(this->m_fcgiRequest->listen_sock);
}

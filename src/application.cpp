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

#include <memory>
#include <cstdint>
#include <iostream>
#include <evhttp.h>

#include "http-kernel/kernel.h"
#include "http-kernel/controller.h"
#include "http/request.h"
#include "http/response.h"
#include "http/header.h"

#include "application.h"

using namespace std;
using namespace Hetach;
using namespace Hetach::Http;
using namespace Hetach::HttpKernel;

void handler(evhttp_request *req, void *);

namespace ApplicationPrivate {
    static Kernel *kernel;
}

Application::Application()
{
    this->m_kernel = new HttpKernel::Kernel();
    this->m_listenAddres = "127.0.0.1";
    this->m_listenPort = 5555;
}

Application::Application(string listenAddress, int listenPort)
{
    this->m_kernel = new HttpKernel::Kernel();
    this->m_listenAddres = listenAddress;
    this->m_listenPort = listenPort;
}

Application::Application(string listenAddress, int listenPort, HttpKernel::Kernel *kernel)
{
    this->m_listenAddres = listenAddress;
    this->m_listenPort = listenPort;
    this->m_kernel = kernel;
}

Application::Application(HttpKernel::Kernel *kernel)
{
    this->m_kernel = kernel;
}

void Application::route(string route, HttpKernel::Controller *controller)
{
    this->m_kernel->add(&route, controller);
}

void Application::boot()
{
    ApplicationPrivate::kernel = this->m_kernel;

    if(!event_init()) {
        cerr << "Failed to init libevent" << endl;
        return;
    }

    this->m_httpd = evhttp_start(this->m_listenAddres.data(), this->m_listenPort);

    if(!this->m_httpd) {
        cerr << "Failed to init http server" << endl;
        return;
    }

    evhttp_set_gencb(this->m_httpd, handler, nullptr);

    if(event_dispatch() == -1) {
        cerr << "Failed to run message loop" << endl;
        return;
    }
}

void Application::quit()
{
    evhttp_free(this->m_httpd);
}

void handler(evhttp_request *req, void *)
{
    auto *outBuffer = evhttp_request_get_output_buffer(req);

    if(!outBuffer) {
        return;
    }

    Request *request = Request::create(req);
    Response *response = ApplicationPrivate::kernel->handle(request);

    evkeyvalq *outputHeaders = evhttp_request_get_output_headers(req);

    string version = HETACH_VERSION;
    response->addHeader(Header("Server", "hetach/" + version));

    response->addHeader(Header("Connection", "close"));

    vector<Header> headers = response->headers();

    for(vector<Header>::iterator it = headers.begin(); it != headers.end(); ++it) {
        Header header = static_cast<Header>(*it);

        evhttp_add_header(outputHeaders, header.name().data(), header.value().data());
    }

    evbuffer_add_printf(outBuffer, response->content().data());

    evhttp_send_reply(req, response->statusCode(), "", outBuffer);

    delete request;
    delete response;
}

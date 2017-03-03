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

#include <vector>
#include <memory>
#include <iostream>
#include <evhttp.h>

#include "hetach/server/webserver.h"
#include "hetach/http/request.h"
#include "hetach/http/response.h"
#include "hetach/http/header.h"

using namespace std;
using namespace Hetach::Http;
using namespace Hetach::Server;

namespace WebServerPrivate {
    Response* (*onRequest)(Request *request);

    void handler(evhttp_request *req, void *);
}

WebServer::WebServer() : Server()
{
    this->m_addres = "127.0.0.1";
    this->m_port = 5555;
}

WebServer::WebServer(string address, int port) : Server()
{
    this->m_addres = address;
    this->m_port = port;
}

WebServer::WebServer(int port) : Server()
{
    this->m_addres = "127.0.0.1";
    this->m_port = port;
}

bool WebServer::listen()
{
    WebServerPrivate::onRequest = this->m_onRequest;

    if(!event_init()) {
        cerr << "Failed to init libevent" << endl;
        return false;
    }

    this->m_httpd = evhttp_start(this->m_addres.data(), this->m_port);

    if(!this->m_httpd) {
        cerr << "Failed to init http server" << endl;
        return false;
    }

    evhttp_set_gencb(this->m_httpd, WebServerPrivate::handler, nullptr);

    if(event_dispatch() == -1) {
        cerr << "Failed to run message loop" << endl;
        return false;
    }

    return true;
}

void WebServer::close()
{
    evhttp_free(this->m_httpd);
}

void WebServerPrivate::handler(evhttp_request *req, void *)
{
    evbuffer *outBuffer = evhttp_request_get_output_buffer(req);

    if(!outBuffer) {
        return;
    }

    Request *request = Request::create(req);

    Response *response = WebServerPrivate::onRequest(request);

    evkeyvalq *outputHeaders = evhttp_request_get_output_headers(req);

    string version = HETACH_VERSION;
    response->addHeader(Header("Server", "hetach/" + version));

    response->addHeader(Header("Connection", "close"));

    vector<Header> headers = response->headers();

    for(vector<Header>::iterator it = headers.begin(); it != headers.end(); ++it) {
        Header header = static_cast<Header>(*it);

        evhttp_add_header(outputHeaders, header.name().data(), header.value().data());
    }

    evbuffer_add(outBuffer, response->content().data(), response->content().size());

    evhttp_send_reply(req, response->statusCode(), "", outBuffer);

    delete request;
    delete response;
}

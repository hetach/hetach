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

#include <iterator>
#include <router/router.h>
#include <router/resourcenotfoundexception.h>
#include <iostream>
#include <string>

#include "http-kernel/header.h"
#include "http-kernel/kernel.h"
#include "http-kernel/request.h"
#include "http-kernel/response.h"
#include "http-kernel/methodnotimplementedexception.h"
#include "http-kernel/methodunknownexception.h"

using namespace std;
using namespace Hetach::HttpKernel;
using namespace Hetach::Router;

Kernel::Kernel()
{
    this->m_router = new ::Router();
}

void Kernel::start()
{
    this->m_cin  = cin.rdbuf();
    this->m_cout = cout.rdbuf();
    this->m_cerr = cerr.rdbuf();

    FCGX_Request fcgiRequest;

    FCGX_Init();
    FCGX_InitRequest(&fcgiRequest, 0, 0);

    Request *request;
    Response *response;
    Resource *resource;

    while (FCGX_Accept_r(&fcgiRequest) == 0) {
        fcgi_streambuf cin_fcgi_streambuf(fcgiRequest.in);
        fcgi_streambuf cout_fcgi_streambuf(fcgiRequest.out);
        fcgi_streambuf cerr_fcgi_streambuf(fcgiRequest.err);

        request = Request::create(&fcgiRequest);
        response = new Response();

        try {
            resource = this->m_router->match(request->path());

            map<string, Controller*>::iterator it = this->m_controllers.find(resource->compiledRoute().rawPath());

            if(it != this->m_controllers.end()) {
                Controller *controller = dynamic_cast<Controller*>(it->second);

                controller->handle(request, response, resource->routeParams());
            }
        } catch(ResourceNotFoundException) {
            response->setStatusCode(404);
            response->setContent("Not found");
        } catch(MethodNotImplementedException) {
            response->setStatusCode(501);
            response->setContent("Not implemented");
        } catch(MethodUnknownException) {
            response->setStatusCode(500);
            response->setContent("Method unknown");
        }

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        list<Header> headers = response->headers();

        for(list<Header>::iterator it = headers.begin(); it != headers.end(); ++it) {
            Header header = static_cast<Header>(*it);

            cout << header.name() << ": " << header.value() << "\r\n";
        }

        cout << "\r\n";

        cout << response->content();

        delete request;
        delete response;
        delete resource;
    }
}

void Kernel::quit()
{
    cin.rdbuf(this->m_cin);
    cout.rdbuf(this->m_cout);
    cerr.rdbuf(this->m_cerr);
}

void Kernel::add(string path, Controller *controller)
{
    this->m_router->addRoute(Route(path));

    this->m_controllers.insert(make_pair(path, controller));
}

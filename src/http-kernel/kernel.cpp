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
#include <string>

#include "http-kernel/kernel.h"
#include "http/request.h"
#include "http/response.h"
#include "http-kernel/methodnotimplementedexception.h"
#include "http-kernel/methodunknownexception.h"

using namespace std;
using namespace Hetach::HttpKernel;
using namespace Hetach::Http;
using namespace Hetach::Router;

Kernel::Kernel()
{
    this->m_router = new ::Router();
}

Response* Kernel::handle(Request *request)
{
    Response *response = new Response();
    Resource *resource;

    try {
        resource = this->m_router->match(request->path());

        map<string, Controller*>::iterator it = this->m_controllers.find(resource->compiledRoute()->rawPath());

        if(it != this->m_controllers.end()) {
            Controller *controller = dynamic_cast<Controller*>(it->second);

            controller->handle(request, response, resource->routeParams());
        }

        delete resource;
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

    return response;
}

void Kernel::add(string path, Controller *controller)
{
    this->m_router->addRoute(new Route(path));

    this->m_controllers.insert(make_pair(path, controller));
}

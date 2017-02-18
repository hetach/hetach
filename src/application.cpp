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

#include "hetach/http-kernel/kernel.h"
#include "hetach/http-kernel/controller.h"
#include "hetach/http/request.h"
#include "hetach/http/response.h"
#include "hetach/server/server.h"

#include "hetach/application.h"

using namespace std;
using namespace Hetach;
using namespace Hetach::Http;
using namespace Hetach::HttpKernel;

namespace ApplicationPrivate {
    static Kernel *kernel;

    Response* onRequest(Request *request);
}

Application::Application(Server::Server *server)
{
    this->m_server = server;
    this->m_kernel = new HttpKernel::Kernel();
}

Application::Application(HttpKernel::Kernel *kernel)
{
    this->m_kernel = kernel;
}

Application::Application(Server::Server *server, HttpKernel::Kernel *kernel)
{
    this->m_server = server;
    this->m_kernel = kernel;
}

void Application::route(string route, HttpKernel::Controller *controller)
{
    this->m_kernel->add(route, controller);
}

int Application::exec()
{
    ApplicationPrivate::kernel = this->m_kernel;

    this->m_server->onRequest(ApplicationPrivate::onRequest);

    if(this->m_server->listen()) {
        return 0;
    }

    return 1;
}

void Application::quit()
{
    this->m_server->close();
}

Response* ApplicationPrivate::onRequest(Request *request)
{
    return ApplicationPrivate::kernel->handle(request);
}

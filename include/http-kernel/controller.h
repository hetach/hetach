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

#ifndef HETACH_HTTPKERNEL_CONTROLLER_H
#define HETACH_HTTPKERNEL_CONTROLLER_H

#include <map>
#include <string>

#include "http-kernel/response.h"
#include "http-kernel/request.h"

namespace Hetach {
    namespace Router {
        class Params;
    }

    namespace HttpKernel {
        class Controller
        {
        public:
            Controller();

            Response* response() { return m_response; }
            Request* request() { return m_request; }
            Hetach::Router::Params* routeParams() { return m_routeParams; }

            virtual Response* doGet();
            virtual Response* doPost(std::string content);
            virtual Response* doPut(std::string content);
            virtual Response* doPatch(std::string content);
            virtual Response* doDelete();
            virtual Response* doOptions();

            virtual Response* handle(Request *request, Response *response, Hetach::Router::Params *routeParams);

        protected:
            Response *m_response;
            Request *m_request;
            Hetach::Router::Params *m_routeParams;
        };
    }
}

#endif // HETACH_HTTPKERNEL_CONTROLLER_H

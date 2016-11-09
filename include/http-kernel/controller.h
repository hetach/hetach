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

namespace Hetach {
    namespace Http {
        class Request;
        class Response;
    }

    namespace Router {
        class Params;
    }

    namespace HttpKernel {
        class Controller
        {
        public:
            Controller();

            Http::Response* response() { return m_response; }
            Http::Request* request() { return m_request; }
            Hetach::Router::Params* routeParams() { return m_routeParams; }

            virtual void doGet();
            virtual void doPost(std::string content);
            virtual void doPut(std::string content);
            virtual void doPatch(std::string content);
            virtual void doDelete();
            virtual void doOptions();

            virtual void handle(Http::Request *request, Http::Response *response, Hetach::Router::Params *routeParams);

        protected:
            Http::Response *m_response;
            Http::Request *m_request;
            Hetach::Router::Params *m_routeParams;
        };
    }
}

#endif // HETACH_HTTPKERNEL_CONTROLLER_H

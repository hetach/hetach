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
            /**
             * @brief Controller
             */
            Controller();

            /**
             * @brief Returns response
             * @return
             */
            Http::Response* response() { return m_response; }

            /**
             * @brief Returns request
             * @return
             */
            Http::Request* request() { return m_request; }

            /**
             * @brief Returns route Params
             * @return
             */
            Hetach::Router::Params* routeParams() { return m_routeParams; }

            /**
             * @brief Handle GET method
             */
            virtual void doGet();

            /**
             * @brief Handle POST method
             * @param content
             */
            virtual void doPost(std::string content);

            /**
             * @brief Handle PUT method
             * @param content
             */
            virtual void doPut(std::string content);

            /**
             * @brief Handle PATCH method
             * @param content
             */
            virtual void doPatch(std::string content);

            /**
             * @brief Handle DELETE method
             */
            virtual void doDelete();

            /**
             * @brief Handle OPTIONS method
             */
            virtual void doOptions();

            /**
             * @brief Chooses suitable handler for incoming request
             * @param request
             * @param response
             * @param routeParams
             */
            virtual void handle(Http::Request *request, Http::Response *response, Hetach::Router::Params *routeParams);

        protected:
            Http::Response *m_response;
            Http::Request *m_request;
            Hetach::Router::Params *m_routeParams;
        };
    }
}

#endif // HETACH_HTTPKERNEL_CONTROLLER_H

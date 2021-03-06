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

#ifndef HETACH_APIREST_RESTCONTROLLER_H
#define HETACH_APIREST_RESTCONTROLLER_H

#include <string>
#include <exception>
#include <hetach/http-kernel/controller.h>

#include "hetach/api-rest/resource.h"
#include "hetach/api-rest/entity.h"
#include "hetach/api-rest/entitycollection.h"

namespace Hetach {
    namespace Http {
        class Request;
        class Resposne;
    }

    namespace Router {
        class Params;
    }

    namespace ApiRest {
        class RestController: public Hetach::HttpKernel::Controller
        {
        public:
            /**
             * @brief RestController
             * @param resource
             */
            RestController(Resource *resource);

            /**
             * @brief Handles GET method
             */
            void doGet();

            /**
             * @brief Handles POST method
             * @param content
             */
            void doPost(std::string content);

            /**
             * @brief Handles PATCH method
             * @param content
             */
            void doPatch(std::string content);

            /**
             * @brief Handles PUT method
             * @param content
             */
            void doPut(std::string content);

            /**
             * @brief Handles DELETE method
             */
            void doDelete();

            /**
             * @brief Chooses suitable handler for incoming request
             * @param request
             * @param response
             * @param routeParams
             */
            void handle(Http::Request *request, Http::Response *response, Router::Params *routeParams);

        protected:
            Resource *m_resource;

            std::string buildError(std::exception &exception);
        };
    }
}

#endif // HETACH_APIREST_RESTCONTROLLER_H

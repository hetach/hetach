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
#include <http-kernel/controller.h>

#include "api-rest/resource.h"
#include "api-rest/entity.h"
#include "api-rest/entitycollection.h"

namespace Hetach {
    namespace HttpKernel {
        class Resposne;
        class Request;
    }

    namespace Router {
        class Params;
    }

    namespace ApiRest {
        class RestController: public Hetach::HttpKernel::Controller
        {
        public:
            RestController(Resource *resource);

            Hetach::HttpKernel::Response* doGet();
            Hetach::HttpKernel::Response* doPost();
            Hetach::HttpKernel::Response* doPatch();
            Hetach::HttpKernel::Response* doPut();
            Hetach::HttpKernel::Response* doDelete();

            Hetach::HttpKernel::Response* handle(HttpKernel::Request *request, HttpKernel::Response *response, Router::Params *routeParams);

        protected:
            Resource *m_resource;

            std::string buildJson(Entity* entity);
            std::string buildJson(EntityCollection* collection);
        };
    }
}

#endif // HETACH_APIREST_RESTCONTROLLER_H

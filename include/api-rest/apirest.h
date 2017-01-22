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

#ifndef HETACH_APIREST_APIREST_H
#define HETACH_APIREST_APIREST_H

#include <string>
#include <map>

#include "api-rest/resource.h"

namespace Hetach {
    class Application;

    namespace ApiRest {
        class ApiRest
        {
        public:
            /**
             * @brief ApiRest
             * @param application
             * @param routePrefix
             */
            ApiRest(Hetach::Application *application, std::string routePrefix);

            /**
             * @brief Register resource in application
             * @param resource
             */
            void addResource(Resource *resource);

            /**
             * @brief Register subresource for resource in application
             * @param parent
             * @param resource
             */
            void addResource(Resource *parent, Resource *resource);

        protected:
            Hetach::Application *m_application;
            std::string m_routePrefix;
            std::map<std::string, std::string> m_routes;
        };
    }
}

#endif // HETACH_APIREST_APIREST_H

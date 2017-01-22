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

#ifndef HETACH_ROUTER_ROUTER_H
#define HETACH_ROUTER_ROUTER_H

#include <string>
#include <map>

#include "router/routecompiler.h"
#include "router/route.h"
#include "router/compiledroute.h"
#include "router/resource.h"

namespace Hetach {
    namespace Router {
        class Router
        {
        public:
            /**
             * @brief Router
             */
            Router();

            /**
             * @brief Registers route to be matched for incoming Request
             * @param route
             */
            void addRoute(Route *route);

            /**
             * @brief Matches path as string to compiled routes.
             *        Creates Resource object with needed informations to resolve Controller
             * @param path
             * @return
             */
            virtual Resource* match(std::string path);

        protected:
            std::map<Route*, CompiledRoute*> m_routes;
            RouteCompiler *m_compiler;
        };
    }
}


#endif // HETACH_ROUTER_ROUTER_H

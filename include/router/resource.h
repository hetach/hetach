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

#ifndef HETACH_ROUTER_RESOURCE_H
#define HETACH_ROUTER_RESOURCE_H

#include <map>
#include <string>

#include "router/route.h"
#include "router/compiledroute.h"
#include "router/params.h"

namespace Hetach {
    namespace Router {
        class Resource
        {
        public:
            /**
             * @brief Resource
             * @param route
             * @param compiledRoute
             * @param routeParams
             */
            Resource(Route *route, CompiledRoute *compiledRoute, Params *routeParams);

            ~Resource();

            /**
             * @brief Returns Route
             * @return
             */
            Route* route();

            /**
             * @brief Returns CompiledRoute
             * @return
             */
            CompiledRoute* compiledRoute();

            /**
             * @brief Returns route Params
             * @return
             */
            Params* routeParams();

        protected:
            Route *m_route;
            CompiledRoute *m_compiledRoute;
            Params *m_routeParams;
        };
    }
}

#endif // HETACH_ROUTER_RESOURCE_H

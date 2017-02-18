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

#ifndef HETACH_ROUTER_ROUTE_H
#define HETACH_ROUTER_ROUTE_H

#include <string>
#include <vector>

#include "hetach/router/routepart.h"

namespace Hetach {
    namespace Router {
        class Route
        {
        public:
            /**
             * @brief Route
             */
            Route() {}

            /**
             * @brief Route
             * @param path
             */
            Route(std::string path);

            /**
             * @brief Returns path template
             * @return
             */
            std::string path();

            /**
             * @brief Returns parts of the Route
             * @return
             */
            std::vector<RoutePart> parts();

        protected:
            std::string m_path;
            std::vector<RoutePart> m_parts;
        };
    }
}

#endif // HETACH_ROUTER_ROUTE_H

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

#ifndef HETACH_ROUTER_COMPILEDROUTE_H
#define HETACH_ROUTER_COMPILEDROUTE_H

#include <string>
#include <vector>

#include "hetach/router/routepart.h"

namespace Hetach {
    namespace Router {
        class CompiledRoute
        {
        public:
            /**
             * @brief CompiledRoute
             */
            CompiledRoute() {}

            /**
             * @brief CompiledRoute
             * @param pathVariables
             * @param parts
             * @param rawPath
             */
            CompiledRoute(std::vector<std::string> *pathVariables, std::vector<RoutePart*> *parts, std::string rawPath);

            /**
             * @brief Returns extracted path variables
             * @return
             */
            std::vector<std::string>* pathVariables();

            /**
             * @brief Returns created RouteParts
             * @return
             */
            std::vector<RoutePart*>* parts();

            /**
             * @brief Returns raw path template
             * @return
             */
            std::string rawPath();

        protected:
            std::vector<std::string> *m_pathVariables;
            std::vector<RoutePart*> *m_parts;
            std::string m_rawPath;
        };
    }
}

#endif // HETACH_ROUTER_COMPILEDROUTE_H

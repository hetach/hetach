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

#ifndef HETACH_ROUTER_ROUTEPART_H
#define HETACH_ROUTER_ROUTEPART_H

#include <string>

namespace Hetach {
    namespace Router {
        class RoutePart
        {
        public:
            /**
             * @brief RoutePart
             */
            RoutePart();

            /**
             * @brief RoutePart
             * @param name
             * @param isParameter
             */
            RoutePart(std::string name, bool isParameter);

            /**
             * @brief Creates RoutePart from string.
             *        If part is a parameter, then data starts with "{" and ends with "}"
             * @param data
             * @return
             */
            static RoutePart* createFromString(std::string data);

            /**
             * @brief Returns name of RoutePart
             * @return
             */
            std::string name();

            /**
             * @brief isParameter
             * @return
             */
            bool isParameter();

        protected:
            std::string m_name;
            bool m_isParameter;
        };
    }
}

#endif // HETACH_ROUTER_ROUTEPART_H

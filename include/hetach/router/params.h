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

#ifndef HETACH_ROUTER_PARAMS_H
#define HETACH_ROUTER_PARAMS_H

#include <map>
#include <string>

namespace Hetach {
    namespace Router {
        class Params
        {
        public:
            /**
             * @brief Params
             */
            Params();

            /**
             * @brief Params
             * @param params
             */
            Params(std::map<std::string, std::string> params);

            /**
             * @brief Returns param value for given key
             * @param key
             * @return
             */
            std::string value(std::string key);

        protected:
            std::map<std::string, std::string> m_params;
        };
    }
}

#endif // HETACH_ROUTER_PARAMS_H

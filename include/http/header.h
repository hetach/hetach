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

#ifndef HETACH_HTTP_HEADER_H
#define HETACH_HTTP_HEADER_H

#include <string>

namespace Hetach {
    namespace Http {
        class Header
        {
        public:
            /**
             * @brief Header
             * @param name
             * @param value
             */
            Header(std::string name, std::string value);

            /**
             * @brief Header
             * @param name
             * @param value
             */
            Header(std::string name, int value);

            /**
             * @brief Header name
             * @return
             */
            std::string name();

            /**
             * @brief Header value
             * @return
             */
            std::string value();

            /**
             * @brief Creates string from Header object.
             *        Example: "Content-type: application/json"
             * @return
             */
            std::string toString();

        protected:
            std::string m_name;
            std::string m_value;
        };
    }
}

#endif // HETACH_HTTP_HEADER_H

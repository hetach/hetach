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

#ifndef HETACH_HTTP_RESPONSE_H
#define HETACH_HTTP_RESPONSE_H

#include <string>
#include <vector>

namespace Hetach {
    namespace Http {
        class Header;

        class Response
        {
        public:
            /**
             * @brief Response
             */
            Response();

            /**
             * @brief Sets content of response
             * @param content
             */
            void setContent(std::string content);

            /**
             * @brief Returns content of response
             * @return
             */
            std::string content();

            /**
             * @brief Returns all response headers
             * @return
             */
            std::vector<Header> headers();

            /**
             * @brief Returns Header by name
             * @param name
             * @return
             */
            Header header(std::string name);

            /**
             * @brief Adds Header to response
             * @param newHeader
             */
            void addHeader(Header newHeader);

            /**
             * @brief Sets response status code
             * @param code
             */
            void setStatusCode(int code);

            /**
             * @brief Returns status code of response
             * @return
             */
            int statusCode();

        protected:
            std::string m_content;
            std::vector<Header> m_headers;
            int m_statusCode;

            void addDefaultHeaders();
        };
    }
}

#endif // HETACH_HTTP_RESPONSE_H

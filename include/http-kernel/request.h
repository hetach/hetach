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

#ifndef HETACH_HTTPKERNEL_REQUEST_H
#define HETACH_HTTPKERNEL_REQUEST_H

#include <list>
#include <string>
#include <fcgio.h>

namespace Hetach {
    namespace HttpKernel {
        class Request
        {
        public:
            Request(int method, std::string path, std::string content = "");

            static Request* create(FCGX_Request *request);

            static int methodFromString(std::string method);

            enum HttpMethod {
                METHOD_GET = 0,
                METHOD_POST,
                METHOD_PUT,
                METHOD_PATCH,
                METHOD_DELETE,
                METHOD_OPTIONS,
                METHOD_UNKNOWN
            };

            int method();
            std::string path();
            std::string content();

        protected:
            int m_method;
            std::string m_path;
            std::string m_content;
        };
    }
}


#endif // HETACH_HTTPKERNEL_REQUEST_H

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

#ifndef HETACH_SERVER_WEBSERVER_H
#define HETACH_SERVER_WEBSERVER_H

#include <string>

#include "server.h"

class evhttp;

namespace Hetach {
    namespace Http {
        class Request;
        class Response;
    }

    namespace Server {
        class WebServer: public Server
        {
        public:
            /**
             * @brief WebServer
             */
            WebServer();

            /**
             * @brief WebServer
             * @param address
             * @param port
             */
            WebServer(std::string address, int port);

            /**
             * @brief listen
             * @return
             */
            bool listen();

            /**
             * @brief close
             */
            void close();

        protected:
            std::string m_addres;
            int m_port;

            evhttp *m_httpd;
        };
    }
}

#endif // HETACH_SERVER_WEBSERVER_H

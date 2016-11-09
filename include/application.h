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

#ifndef HETACH_APPLICATION_H
#define HETACH_APPLICATION_H

#include <string>
#include <functional>

class evhttp;

namespace Hetach {
    namespace HttpKernel {
        class Kernel;
        class Controller;
    }

    class Application
    {
    public:
        Application();
        Application(std::string listenAddress, int listenPort);
        Application(std::string listenAddress, int listenPort, HttpKernel::Kernel *kernel);
        Application(HttpKernel::Kernel *kernel);

        void route(std::string route, HttpKernel::Controller *controller);

        virtual void boot();
        virtual void quit();

    protected:
        HttpKernel::Kernel *m_kernel;

    private:
        std::string m_listenAddres;
        int m_listenPort;

        evhttp *m_httpd;
    };
}

#endif // HETACH_APPLICATION_H

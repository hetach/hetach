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

namespace Hetach {
    namespace HttpKernel {
        class Kernel;
        class Response;
        class Controller;
    }
    class Application
    {
    public:
        Application();

        void route(std::string route, HttpKernel::Controller *controller);

        void run();

    protected:
        HttpKernel::Kernel *m_kernel;
    };
}

#endif // HETACH_APPLICATION_H

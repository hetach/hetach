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

#ifndef HETACH_HTTPKERNEL_KERNEL_H
#define HETACH_HTTPKERNEL_KERNEL_H

#include <map>
#include <fcgio.h>

#include "http-kernel/controller.h"

namespace Hetach {
    namespace Router {
        class Router;
    }

    namespace HttpKernel {
        class Kernel
        {
        public:
            Kernel();

            void start();
            void quit();
            void add(std::string path, Controller *controller);

        protected:
            std::map<std::string, Controller*> m_controllers;
            Hetach::Router::Router *m_router;
        };
    }
}


#endif // HETACH_HTTPKERNEL_KERNEL_H

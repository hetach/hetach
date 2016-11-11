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

#include "http-kernel/controller.h"
#include "http-kernel/controllerresolver.h"

namespace Hetach {
    namespace Router {
        class Router;
    }

    namespace Http {
        class Response;
        class Request;
    }

    namespace HttpKernel {
        class Kernel
        {
        public:
            Kernel();
            Kernel(ControllerResolver *controllerResolver);
            Kernel(Router::Router *router);
            Kernel(ControllerResolver *controllerResolver, Router::Router *router);

            virtual Http::Response* handle(Http::Request *request);

            void add(std::string path, Controller *controller);

        protected:
            ControllerResolver *m_controllerResolver;
            Router::Router *m_router;
        };
    }
}


#endif // HETACH_HTTPKERNEL_KERNEL_H

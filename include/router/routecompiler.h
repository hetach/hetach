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

#ifndef HETACH_ROUTER_ROUTECOMPILER_H
#define HETACH_ROUTER_ROUTECOMPILER_H

#include <string>

#include "router/compiledroute.h"
#include "router/route.h"

namespace Hetach {
    namespace Router {
        class RouteCompiler
        {
        public:
            RouteCompiler();

            static const std::string paramRegex() {
                return "([a-zA-Z0-9]+)";
            }

            CompiledRoute* compile(Route *route);
        };
    }
}

#endif // HETACH_ROUTER_ROUTECOMPILER_H

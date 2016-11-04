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

#include <http-kernel/kernel.h>
#include <http-kernel/response.h>
#include <http-kernel/controller.h>

#include "application.h"

using namespace std;
using namespace Hetach;

Application::Application()
{
    this->m_kernel = new HttpKernel::Kernel();
}

void Application::route(string route, HttpKernel::Controller *controller)
{
    this->m_kernel->add(route, controller);
}

void Application::run()
{
    this->m_kernel->start();

    this->m_kernel->quit();
}

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

#ifndef HETACH_APIREST_RESOURCE_H
#define HETACH_APIREST_RESOURCE_H

#include <string>

#include "api-rest/entity.h"
#include "api-rest/entitycollection.h"

namespace Hetach {
    namespace ApiRest {
        class Resource
        {
        public:
            Resource();

            virtual std::string name() = 0;

            virtual Entity* fetch(int id);
            virtual EntityCollection* fetchAll();

            virtual Entity* create();

            virtual Entity* update(int id);
            virtual EntityCollection* update();

            virtual Entity* replace(int id);
            virtual EntityCollection* replace();

            virtual Entity* remove(int id);
            virtual EntityCollection* remove();
        };
    }
}

#endif // HETACH_APIREST_RESOURCE_H

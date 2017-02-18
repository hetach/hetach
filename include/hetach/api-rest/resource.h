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

#include "hetach/api-rest/entity.h"
#include "hetach/api-rest/entitycollection.h"

namespace Hetach {
    namespace ApiRest {
        class Resource
        {
        public:
            Resource();

            /**
             * @brief Name of the resource.
             *        Will be used in path as <apiRoutePrefix>[/<parentResourceName>/<id>]/<name>
             * @return
             */
            virtual std::string name() = 0;

            /**
             * @brief Fetch (GET) single Entity. To implement by user
             * @param id
             * @return
             */
            virtual Entity* fetch(int id);

            /**
             * @brief Fetch (GET) collection of Entities. To implement by user
             * @return
             */
            virtual EntityCollection* fetchAll();

            /**
             * @brief Create (POST) new Entity. To implement by user
             * @return
             */
            virtual Entity* create();

            /**
             * @brief Update (PATCH) an Entity. To implement by user
             * @param id
             * @return
             */
            virtual Entity* update(int id);

            /**
             * @brief Update (PATCH) collection of Entities. To implement by user
             * @return
             */
            virtual EntityCollection* update();

            /**
             * @brief Replace (PUT) an Entity. To implement by user
             * @param id
             * @return
             */
            virtual Entity* replace(int id);

            /**
             * @brief Replace (PUT) collection of Entities. To implement by user
             * @return
             */
            virtual EntityCollection* replace();

            /**
             * @brief Remove (DELETE) an Entity. To implement by user
             * @param id
             * @return
             */
            virtual Entity* remove(int id);

            /**
             * @brief Remove (DELETE) collection of Entities. To implement by user
             * @return
             */
            virtual EntityCollection* remove();
        };
    }
}

#endif // HETACH_APIREST_RESOURCE_H

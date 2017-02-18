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

#ifndef HETACH_APIREST_ENTITYCOLLECTION_H
#define HETACH_APIREST_ENTITYCOLLECTION_H

#include <list>
#include <string>

#include "hetach/api-rest/entity.h"

namespace Hetach {
    namespace ApiRest {
        class EntityCollection
        {
        public:
            /**
             * @brief EntityCollection
             * @param collection
             */
            EntityCollection(std::list<Entity*> collection);

            /**
             * @brief ~EntityCollection
             */
            ~EntityCollection();

            /**
             * @brief items
             * @return
             */
            std::list<Entity*> items();

            /**
             * @brief count
             * @return
             */
            int count();

            /**
             * @brief Builds JSON string which represent the collection of Entities
             * @return
             */
            virtual std::string toJson();

        protected:
            std::list<Entity*> m_collection;
        };
    }
}

#endif // HETACH_APIREST_ENTITYCOLLECTION_H

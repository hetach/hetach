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

#include "hetach/api-rest/entitycollection.h"

using namespace std;
using namespace Hetach::ApiRest;

EntityCollection::EntityCollection(list<Entity*> collection)
{
    this->m_collection = collection;
}

EntityCollection::~EntityCollection()
{
    this->m_collection.clear();
}

list<Entity*> EntityCollection::items()
{
    return this->m_collection;
}

int EntityCollection::count()
{
    return this->m_collection.size();
}

string EntityCollection::toJson()
{
    string json = "[";

    for(list<Entity*>::iterator it = this->m_collection.begin(); it != this->m_collection.end(); ++it) {
        Entity* entity = dynamic_cast<Entity*>(*it);

        json.append(entity->toJson());

        if(this->m_collection.back() != entity) {
            json.append(",");
        }
    }

    json.append("]");

    return json;
}

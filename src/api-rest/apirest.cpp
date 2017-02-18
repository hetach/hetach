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

#include <hetach/application.h>

#include "hetach/api-rest/apirest.h"
#include "hetach/api-rest/restcontroller.h"

using namespace std;
using namespace Hetach::ApiRest;

ApiRest::ApiRest(Hetach::Application *application, string routePrefix)
{
    this->m_application = application;

    this->m_routePrefix = routePrefix;

    if(this->m_routePrefix.back() != '/') {
        this->m_routePrefix.append("/");
    }
}

void ApiRest::addResource(Resource *resource)
{
    RestController *controller = new RestController(resource);

    string collectionRoute = this->m_routePrefix + resource->name();
    string entityRoute = this->m_routePrefix + resource->name() + "/{"+resource->name()+"Id"+"}";

    this->m_application->route(collectionRoute, controller);
    this->m_application->route(entityRoute, controller);

    this->m_routes.insert(make_pair(resource->name(), collectionRoute));
    this->m_routes.insert(make_pair(resource->name() + "Entity", entityRoute));
}

void ApiRest::addResource(Resource *parent, Resource *resource)
{
    map<string, string>::iterator it = this->m_routes.find(parent->name() + "Entity");

    if(it == this->m_routes.end()) {
        return;
    }

    RestController *controller = new RestController(resource);

    string parentEntityRoute = static_cast<string>(it->second);

    string collectionRoute = parentEntityRoute + "/" + resource->name();
    string entityRoute = parentEntityRoute + "/" + resource->name() + "/{"+resource->name()+"Id"+"}";

    this->m_application->route(collectionRoute, controller);
    this->m_application->route(entityRoute, controller);

    this->m_routes.insert(make_pair(resource->name(), collectionRoute));
    this->m_routes.insert(make_pair(resource->name() + "Entity", entityRoute));
}

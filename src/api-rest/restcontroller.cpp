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

#include <hetach/http-kernel/controller.h>
#include <hetach/http/response.h>
#include <hetach/http/header.h>
#include <hetach/router/params.h>
#include <hetach/router/paramnotfoundexception.h>

#include "hetach/api-rest/restcontroller.h"

using namespace std;
using namespace Hetach::ApiRest;
using namespace Hetach::HttpKernel;
using namespace Hetach::Http;
using namespace Hetach::Router;

RestController::RestController(Resource *resource): Controller()
{
    this->m_resource = resource;
}

void RestController::doGet()
{
    string content;

    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        Entity *entity = this->m_resource->fetch(id);

        content = this->buildJson(entity);

        delete entity;
    } catch(ParamNotFoundException) {
        EntityCollection *collection = this->m_resource->fetchAll();

        content = this->buildJson(collection);

        delete collection;
    }

    this->response()->setContent(content);
}

void RestController::doPost()
{
    Entity *entity = this->m_resource->create();

    string content = this->buildJson(entity);

    delete entity;

    this->response()->setContent(content);
}

void RestController::doPatch()
{
    string content;

    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        Entity *entity = this->m_resource->update(id);

        content = this->buildJson(entity);

        delete entity;
    } catch(ParamNotFoundException) {
        EntityCollection *collection = this->m_resource->update();

        content = this->buildJson(collection);

        delete collection;
    }

    this->response()->setContent(content);
}

void RestController::doPut()
{
    string content;

    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        Entity *entity = this->m_resource->replace(id);

        content = this->buildJson(entity);

        delete entity;
    } catch(ParamNotFoundException) {
        EntityCollection *collection = this->m_resource->replace();

        content = this->buildJson(collection);

        delete collection;
    }

    this->response()->setContent(content);
}

void RestController::doDelete()
{
    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        this->m_resource->remove(id);
    } catch(ParamNotFoundException) {
        this->m_resource->remove();
    }

    this->response()->setContent("");
    this->response()->setStatusCode(204);
}

void RestController::handle(Request *request, Response *response, Router::Params *routeParams)
{
    Controller::handle(request, response, routeParams);

    this->response()->addHeader(Header("Content-type", "application/json"));
}

string RestController::buildJson(Entity *entity)
{
    return entity->toJson();
}

string RestController::buildJson(EntityCollection* collection)
{
    return collection->toJson();
}

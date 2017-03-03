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
#include <hetach/http/request.h>
#include <hetach/http/header.h>
#include <hetach/router/params.h>
#include <hetach/router/paramnotfoundexception.h>

#include "hetach/api-rest/restcontroller.h"
#include "hetach/api-rest/entitynotfoundexception.h"
#include "hetach/api-rest/exception.h"

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
    this->response()->setStatusCode(200);

    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        Entity *entity = this->m_resource->fetch(id);

        this->response()->setContent(entity->toJson());

        delete entity;
    } catch(ParamNotFoundException) {
        EntityCollection *collection = this->m_resource->fetchAll();

        this->response()->setContent(collection->toJson());

        delete collection;
    } catch(EntityNotFoundException) {
        this->response()->setContent("");
        this->response()->setStatusCode(404);
    } catch(Exception &exception) {
        this->response()->setContent(this->buildError(exception));
        this->response()->setStatusCode(500);
    }
}

void RestController::doPost(string content)
{
    try {
        Entity *entity = this->m_resource->create(content);
        this->response()->setContent(entity->toJson());

        delete entity;
    } catch(Exception &exception) {
        this->response()->setContent(this->buildError(exception));
        this->response()->setStatusCode(500);
    }
}

void RestController::doPatch(string content)
{
    this->response()->setStatusCode(200);

    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        Entity *entity = this->m_resource->update(id, content);

        this->response()->setContent(entity->toJson());

        delete entity;
    } catch(ParamNotFoundException) {
        EntityCollection *collection = this->m_resource->update(content);

        this->response()->setContent(collection->toJson());

        delete collection;
    } catch(EntityNotFoundException) {
        this->response()->setContent("");
        this->response()->setStatusCode(404);
    } catch(Exception &exception) {
        this->response()->setContent(this->buildError(exception));
        this->response()->setStatusCode(500);
    }
}

void RestController::doPut(string content)
{
    this->response()->setStatusCode(200);

    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        Entity *entity = this->m_resource->replace(id, content);

        this->response()->setContent(entity->toJson());

        delete entity;
    } catch(ParamNotFoundException) {
        EntityCollection *collection = this->m_resource->replace(content);

        this->response()->setContent(collection->toJson());

        delete collection;
    } catch(EntityNotFoundException) {
        this->response()->setContent("");
        this->response()->setStatusCode(404);
    } catch(Exception &exception) {
        this->response()->setContent(this->buildError(exception));
        this->response()->setStatusCode(500);
    }
}

void RestController::doDelete()
{
    this->response()->setContent("");
    this->response()->setStatusCode(204);

    try {
        int id = stoi(this->routeParams()->value(this->m_resource->name()+"Id"));

        this->m_resource->remove(id);
    } catch(ParamNotFoundException) {
        this->m_resource->remove();
    } catch(EntityNotFoundException) {
        this->response()->setStatusCode(404);
    } catch(Exception &exception) {
        this->response()->setContent(this->buildError(exception));
        this->response()->setStatusCode(500);
    }
}

void RestController::handle(Request *request, Response *response, Router::Params *routeParams)
{
    Controller::handle(request, response, routeParams);

    this->response()->addHeader(Header("Content-type", "application/json"));
}

string RestController::buildError(exception &exception)
{
    return "{\"error\": \"" + string(exception.what()) + "\"}";
}

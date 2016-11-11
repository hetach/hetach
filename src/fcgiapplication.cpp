#include <list>
#include <unistd.h>

#include "fcgiapplication.h"

#include "http/header.h"
#include "http/request.h"
#include "http/response.h"
#include "http-kernel/kernel.h"

using namespace std;
using namespace Hetach;
using namespace Http;

void FCGIApplication::boot()
{
    this->m_fcgiRequest = new FCGX_Request();

    FCGX_Init();
    FCGX_InitRequest(this->m_fcgiRequest, 0, 0);

    Request *request;
    Response *response;

    while(FCGX_Accept_r(this->m_fcgiRequest) == 0) {
        request = Request::create(this->m_fcgiRequest);

        response = this->m_kernel->handle(request);

        string status = Header("Status", response->statusCode()).toString() + "\r\n";

        FCGX_PutStr(status.data(), status.size(), this->m_fcgiRequest->out);

        vector<Header> headers = response->headers();

        for(vector<Header>::iterator it = headers.begin(); it != headers.end(); ++it) {
            Header header = static_cast<Header>(*it);

            string data = header.toString() + "\r\n";

            FCGX_PutStr(data.data(), data.size(), this->m_fcgiRequest->out);
        }

        string content = "\r\n" + response->content();

        FCGX_PutStr(content.data(), content.size(), this->m_fcgiRequest->out);

        delete request;
        delete response;
    }
}

void FCGIApplication::quit()
{
    close(this->m_fcgiRequest->listen_sock);
}

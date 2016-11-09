#ifndef HETACH_FCGIAPPLICATION_H
#define HETACH_FCGIAPPLICATION_H

#include "application.h"

class FCGX_Request;

namespace Hetach {
    namespace HttpKernel {
        class Kernel;
    }

    class FCGIApplication: public Application
    {
    public:
        FCGIApplication() : Application() {}
        FCGIApplication(HttpKernel::Kernel *kernel) : Application(kernel) {}

        void boot();
        void quit();

    protected:
        FCGX_Request *m_fcgiRequest;
    };
}

#endif // HETACH_FCGIAPPLICATION_H

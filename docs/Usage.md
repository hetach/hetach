# Usage

Depending on build system of Your choice, setup will be different, but here are main steps:

1. Build Hetach to get `libhetach.<suffix>` and link this library to Your project
2. Add `hetach/include` to include path
3. Build Your application
4. Setup [web server](https://github.com/hetach/hetach/tree/develop/docs/WebServers.md)
5. Run application using for example [spawn-fcgi](https://github.com/lighttpd/spawn-fcgi)

## Quick Start

Use the following code and run it, based on above steps.

```cpp
#include <application.h>
#include <http-kernel/controller.h>

using namespace Hetach;
using namespace Hetach::HttpKernel;

class IndexController: public Controller
{
    Response* doGet()
    {
        this->response()->setContent("Index controller");

        return this->response();
    }
};

int main()
{
    Application *app = new Application();

    Controller *controller = new IndexController();

    app->route("/index", controller);

    app->run();

    return 0;
}

```

After successfull setup, visit `<host>/index` page to see if it works. And that's it!

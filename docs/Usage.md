# Usage

Depending on build system of Your choice, setup will be different, but here are main steps:

1. Build Hetach to get `libhetach.<suffix>` and link this library to Your project
2. Add `hetach/include` to include path
3. Build Your application
4. If You used application with built-in web server, then just run it and skip below steps 
4. Setup [web server](https://github.com/hetach/hetach/tree/develop/docs/WebServers.md)
5. Run application using, for example [spawn-fcgi](https://github.com/lighttpd/spawn-fcgi)

## Example simple application

Following code is a minimal example with one route supporting GET method:

```cpp
#include <application.h>
// #include <fcgiapplication.h> <- if FastCGI context should be used
#include <http-kernel/controller.h>

using namespace Hetach;
using namespace Hetach::HttpKernel;

class IndexController: public Controller
{
    void doGet()
    {
        this->response()->setContent("Index controller");
    }
};

int main()
{
    // Application uses built-in webserver. Use FCGIApplication instead to init FastCGI context
    Application *app = new Application();

    Controller *controller = new IndexController();

    app->route("/index", controller);

    app->run();

    return 0;
}

```

After successfull setup, visit `http://<host>:<port>/index` page to see if it works. And that's it!

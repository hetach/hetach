# Controller

First, create a controller class which will show `Hello World!` on GET request

```cpp
#include <hetach/http-kernel/controller.h>

using namespace Hetach::HttpKernel;

class IndexController: public Controller
{
    void doGet()
    {
        this->response()->setContent("Hello World!");
    }
};
```

# Application

Next, create Hetach application using built-in web server running on default host and port

```cpp
#include <hetach/application.h>
#include <hetach/server/webserver.h>

#include "indexcontroller.h"

using namespace Hetach;
using namespace Hetach::HttpKernel;

int main()
{
    Application *app = new Application(new WebServer());

    Controller *controller = new IndexController();

    app->route("/", controller);

    return app->exec();
}
```

After successfull build, visit `http://localhost:5555/` page to see if it works. And that's it!

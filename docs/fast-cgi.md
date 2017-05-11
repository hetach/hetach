While using FastCGI server, an external [web server](/web-servers) with FastCGI support is required. Also FastCGI context should be created

# FastCGI context

[spawn-fcgi](https://github.com/lighttpd/spawn-fcgi) application can be used to create context

## Application

Example Hetach FastCGI application:

```cpp
#include <hetach/application.h>
#include <hetach/server/fcgiserver.h>

#include "indexcontroller.h"

using namespace Hetach;
using namespace Hetach::HttpKernel;

int main()
{
    Application *app = new Application(new FCGIServer());

    Controller *controller = new IndexController();

    app->route("/", controller);

    return app->exec();
}
```

## spawn-fcgi

Now Hetach application must be run through spawn-fcgi with example command:

```sh
spawn-fcgi -p 8000 -n app
```

All to do is to point web server to localhost:8000 and we're done!

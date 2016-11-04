[![Build Status](https://travis-ci.org/hetach/hetach.svg?branch=master)](https://travis-ci.org/hetach/hetach)

# Hetach - simple web framework

## Description

Hetach is a micro-framework written in C++, which goal is to speed up and help writing FastCGI applications.

## Build

```
mkdir build
cd build
cmake ..
make
```

If You want to build tests, use following cmake command:

```
cmake -DHETACH_BUILD_TESTS ..
```

this will build `hetachTest` executable to run tests, or use `make test` command

## License
[GPLv2](http://www.fsf.org/licensing/licenses/info/GPLv2.html) or any later GPL version.

## Disclaimer
Besides the usual disclaimer in the license, we want to specifically emphasize that neither the authors nor any organization the authors are associated with can and will hold responsible for data-loss caused by possible malfunctions of Hetach.

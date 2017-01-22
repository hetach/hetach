[![Build Status](https://travis-ci.org/hetach/hetach.svg?branch=develop)](https://travis-ci.org/hetach/hetach)

# Hetach - simple web framework

## Description

Hetach is a micro-framework written in C++, which goal is to provide solution for creating web applications. If Your need is located in one of:

* Running web aplication on inefficient platforms like single-board computers, for example RaspberryPI
* Expose api-rest or other interface for a library, for example WiringPI
* Performance is a high priority

then Hetach is for You.

Hetach comes with FastCGI support, so You can easly integrate any web server You like, and with built-in web server - just run Your application with specified listen port and address.

## Usage

Please read [usage](https://github.com/hetach/hetach/blob/develop/docs/Usage.md) document or check out [examples](https://github.com/hetach/examples) repository.

## Build

```
mkdir build
cd build
cmake ..
make
```

If You want to build tests, use following cmake command:

```
cmake -DHETACH_BUILD_TESTS=ON ..
```

this will build `hetachTest` executable to run tests, or use `make test` command

## License
[GPLv2](http://www.fsf.org/licensing/licenses/info/GPLv2.html) or any later GPL version.

## Disclaimer
Besides the usual disclaimer in the license, we want to specifically emphasize that neither the authors nor any organization the authors are associated with can and will hold responsible for data-loss caused by possible malfunctions of Hetach.

cmake_minimum_required(VERSION 2.8.8)

project(hetach C CXX)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "Using GNU compiler")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(STATUS "Using Clang compiler")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
endif()

set(HETACH_VERSION_MAJOR 0)
set(HETACH_VERSION_MINOR 1)
set(HETACH_VERSION_PATCH 0)

add_definitions(-DHETACH_VERSION="${HETACH_VERSION_MAJOR}.${HETACH_VERSION_MINOR}.${HETACH_VERSION_PATCH}")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(
    sources

    src/application.cpp

    src/api-rest/apirest.cpp
    src/api-rest/entity.cpp
    src/api-rest/entitycollection.cpp
    src/api-rest/resource.cpp
    src/api-rest/restcontroller.cpp

    src/http/header.cpp
    src/http/request.cpp
    src/http/response.cpp

    src/http-kernel/controller.cpp
    src/http-kernel/controllerresolver.cpp
    src/http-kernel/kernel.cpp

    src/router/compiledroute.cpp
    src/router/params.cpp
    src/router/resource.cpp
    src/router/route.cpp
    src/router/routecompiler.cpp
    src/router/routepart.cpp
    src/router/router.cpp

    src/server/fcgiserver.cpp
    src/server/webserver.cpp

    include/hetach/application.h

    include/hetach/api-rest/apirest.h
    include/hetach/api-rest/entity.h
    include/hetach/api-rest/entitycollection.h
    include/hetach/api-rest/entitynotfoundexception.h
    include/hetach/api-rest/exception.h
    include/hetach/api-rest/resource.h
    include/hetach/api-rest/restcontroller.h

    include/hetach/http/header.h
    include/hetach/http/request.h
    include/hetach/http/response.h

    include/hetach/http-kernel/controller.h
    include/hetach/http-kernel/controllerresolver.h
    include/hetach/http-kernel/kernel.h
    include/hetach/http-kernel/headernotfoundexception.h
    include/hetach/http-kernel/methodnotimplementedexception.h
    include/hetach/http-kernel/methodunknownexception.h

    include/hetach/server/fcgiserver.h
    include/hetach/server/server.h
    include/hetach/server/webserver.h

    include/hetach/router/compiledroute.h
    include/hetach/router/params.h
    include/hetach/router/paramnotfoundexception.h
    include/hetach/router/resource.h
    include/hetach/router/resourcenotfoundexception.h
    include/hetach/router/route.h
    include/hetach/router/routecompiler.h
    include/hetach/router/routepart.h
    include/hetach/router/router.h

)

add_library(hetach SHARED ${sources})

target_link_libraries(hetach fcgi${CMAKE_SHARED_LIBRARY_SUFFIX})
target_link_libraries(hetach fcgi++${CMAKE_SHARED_LIBRARY_SUFFIX})
target_link_libraries(hetach event${CMAKE_SHARED_LIBRARY_SUFFIX})

#
# TESTS
#
if(HETACH_BUILD_TESTS)
    find_package(Threads REQUIRED)

    enable_testing()

    add_subdirectory(ext/gtest)

    set(
        TEST_SOURCES

        tests/router/compiledroutetest.cpp
        tests/router/resourcetest.cpp
        tests/router/routetest.cpp
        tests/router/routecompilertest.cpp
        tests/router/routertest.cpp

        tests/http/headertest.cpp
        tests/http/responsetest.cpp
        tests/http/requesttest.cpp

        tests/router/fixtures/compiledroutefixture.h
        tests/router/fixtures/resourcefixture.h
        tests/router/fixtures/routecompilerfixture.h
        tests/router/fixtures/routerfixture.h

        tests/http/fixtures/headerfixture.h
        tests/http/fixtures/responsefixture.h
        tests/http/fixtures/requestfixture.h
    )

    include_directories(
        ${GTEST_INCLUDE_DIRS}
        tests
    )

    add_executable(hetachTest ${TEST_SOURCES} ${sources})
    add_dependencies(hetachTest googletest)
    add_test(hetachTest hetachTest)

    target_link_libraries(hetachTest fcgi${CMAKE_SHARED_LIBRARY_SUFFIX})
    target_link_libraries(hetachTest fcgi++${CMAKE_SHARED_LIBRARY_SUFFIX})
    target_link_libraries(hetachTest event${CMAKE_SHARED_LIBRARY_SUFFIX})

    target_link_libraries(
        hetachTest

        ${GTEST_LIBS_DIR}/libgtest${CMAKE_STATIC_LIBRARY_SUFFIX}
        ${GTEST_LIBS_DIR}/libgtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
    )

    target_link_libraries(hetachTest ${CMAKE_THREAD_LIBS_INIT})
endif(HETACH_BUILD_TESTS)

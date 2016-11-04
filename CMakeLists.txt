cmake_minimum_required(VERSION 2.8.8)

project(hetach CXX)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
endif()

set(HETACH_VERSION_MAJOR 0)
set(HETACH_VERSION_MINOR 1)
set(HETACH_VERSION_PATCH 0)

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

    src/http-kernel/controller.cpp
    src/http-kernel/header.cpp
    src/http-kernel/kernel.cpp
    src/http-kernel/request.cpp
    src/http-kernel/response.cpp

    src/router/compiledroute.cpp
    src/router/params.cpp
    src/router/resource.cpp
    src/router/route.cpp
    src/router/routecompiler.cpp
    src/router/router.cpp

    include/application.h

    include/api-rest/apirest.h
    include/api-rest/entity.h
    include/api-rest/entitycollection.h
    include/api-rest/resource.h
    include/api-rest/restcontroller.h

    include/http-kernel/controller.h
    include/http-kernel/header.h
    include/http-kernel/kernel.h
    include/http-kernel/headernotfoundexception.h
    include/http-kernel/methodnotimplementedexception.h
    include/http-kernel/methodunknownexception.h
    include/http-kernel/request.h
    include/http-kernel/response.h

    include/router/compiledroute.h
    include/router/params.h
    include/router/paramnotfoundexception.h
    include/router/resource.h
    include/router/resourcenotfoundexception.h
    include/router/route.h
    include/router/routecompiler.h
    include/router/router.h

)

add_library(hetach SHARED ${sources})

target_link_libraries(hetach fcgi${CMAKE_SHARED_LIBRARY_SUFFIX})
target_link_libraries(hetach fcgi++${CMAKE_SHARED_LIBRARY_SUFFIX})

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

        tests/http-kernel/headertest.cpp
        tests/http-kernel/responsetest.cpp
        tests/http-kernel/requesttest.cpp

        tests/router/fixtures/compiledroutefixture.h
        tests/router/fixtures/resourcefixture.h
        tests/router/fixtures/routecompilerfixture.h
        tests/router/fixtures/routerfixture.h

        tests/http-kernel/fixtures/headerfixture.h
        tests/http-kernel/fixtures/responsefixture.h
        tests/http-kernel/fixtures/requestfixture.h
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

    target_link_libraries(
        hetachTest

        ${GTEST_LIBS_DIR}/libgtest${CMAKE_STATIC_LIBRARY_SUFFIX}
        ${GTEST_LIBS_DIR}/libgtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
    )

    target_link_libraries(hetachTest ${CMAKE_THREAD_LIBS_INIT})
endif(HETACH_BUILD_TESTS)

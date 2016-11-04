#!/bin/bash

currentDir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

echo `whoami`

echo $currentDir

cd $currentDir/..

cmake -DHETACH_BUILD_TESTS=ON . && make -j3 && make test

#!/bin/bash

copyrightFile=$1

if [ ! -f "$copyrightFile" ]; then
    exit 1
fi

shift

copyright=`cat "$copyrightFile"`

for file in $@; do
    content=`head -n 20 "$file"`

    if [[ $content != *"Copyright"* ]]; then
        echo "$file No copyright"
        continue
    fi

    if [[ $content != "$copyright"* ]]; then
        echo "$file Outdated copyright"
        continue
    fi
done

#!/bin/sh

currentDir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

cd $currentDir

copyrightFile="../dist/copyright-template.txt"

declare -i i=0

echo "Fixing missing copyrights..."

for file in `find "../" -type f -name \*.cpp -o -name \*.h | xargs ./copyrightChecker.sh "$copyrightFile" | awk '/No copyright/{print $1}'`; do
    tmpFile="$file.tmp"

    cat "$copyrightFile" "$file" > "$tmpFile"

    mv "$tmpFile" "$file"

    i+=1
done

echo "Fixed $i files"

i=0

echo "Fixing outdated copyrights..."

for file in `find "../" -type f -name \*.cpp -o -name \*.h | xargs ./copyrightChecker.sh "$copyrightFile" | awk '/Outdated copyright/{print $1}'`; do
    tmpFile="$file.tmp"

    cat "$copyrightFile" > "$tmpFile"

    declare -i line=`awk '$1=="*/"{print NR;exit;}' "$file"`

    line+=2

    tail -n "+$line" "$file" >> "$tmpFile"

    mv "$tmpFile" "$file"

    i+=1
done

echo "Fixed $i files"

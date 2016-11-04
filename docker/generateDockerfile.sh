#!/bin/bash

templateFile=""
declare -a vars

while getopts "t:e:" opt; do
    case $opt in
      t)
          templateFile="$(pwd)/$OPTARG"
          ;;
      e)
          vars+=("$OPTARG")
          ;;
    esac
done

gsub=""

for var in "${vars[@]}"; do
    name=$(awk -F"=" '{print $1}' <<< $var)
    value=$(awk -F"=" '{print $2}' <<< $var)

    gsub="$(printf 'gsub(/{{%s}}/, "%s");' "${name}" "${value}")"
done

command="awk '{${gsub} print}' $templateFile"

eval $command

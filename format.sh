#!/bin/bash

# Quick bash script to format all cpp files present.
extension="*.cpp"
paths=($(find . -name "$extension"))
length=${#paths[@]}

echo -e "\n"
for file in "${paths[@]}"
do
    clang-format -i $file
done
echo -e "Formatted $length files \xe2\xad\x90\x0a"
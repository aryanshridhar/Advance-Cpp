#!/bin/bash
# Quick bash script to format all cpp files present.

# Check if clang is installed and install in case of Mac.
if ! command -v clang-format &> /dev/null
then
    echo "Error: clang-format could not be found"
    while true; do
        read -p "Do you want to install clang-format ? (Y/n) " yn
        case $yn in
            [Yy]* ) brew install clang-format; break;;
            [Nn]* ) exit;;
            * ) echo "Please answer yes or no.";;
        esac
    done
fi

extension="*.cpp"
paths=($(find . -name "$extension"))
length=${#paths[@]}

echo -e "\n"
for file in "${paths[@]}"
do
    clang-format -i $file
done
echo -e "Formatted $length files \xe2\xad\x90\x0a"
# Quick script to test all cpp files

extension="*.cpp"
paths=($(find . -name "$extension"))

cecho(){
    RED="\033[0;31m"
    GREEN="\033[0;32m"
    NC="\033[0m"

    printf "${!1}${2} ${NC}\n"
}

for file in "${paths[@]}"
do
    g++ -std=c++11 $file
    if [ $? -eq 0 ]; then
    cecho "GREEN" "$file"
    else
        cecho "RED" "Failed compiling $file"
        exit
    fi
done

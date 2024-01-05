#include "../headers/strFct.h"

std::string lower(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return str;
}

bool isIn(std::string str, std::vector<std::string> list){
    for (int i = 0; i < list.size(); ++i)
    {
        if (str == list[i])
        {
            return true;
        }
    }
    return false;
}
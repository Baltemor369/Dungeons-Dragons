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

std::vector<std::string> split(std::string text, char poundSign=' '){
    std::vector<std::string> list;
    std::string buffer("");
    for(auto c : text){
        if (c == poundSign)
        {
            list.push_back(buffer);
            buffer = "";
        }else{
            buffer += c;
        }
    }
    if (!buffer.empty())
    {
        list.push_back(buffer);
    }
    
    return list;
}

std::string mySubStr(const std::string text, int startIndex, char endChar){
    if (startIndex >= text.length()) {
        return "";
    }
    size_t endIndex = text.find(endChar, startIndex);

    if (endIndex == std::string::npos)
    {
        endIndex = text.length();
    }

    std::string result = text.substr(startIndex, endIndex - startIndex);

    return result;
}
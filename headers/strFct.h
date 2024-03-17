#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

namespace Str{
    std::string lower(std::string str);
    bool isIn(std::string str, std::vector<std::string> list);
    std::string mySubStr(const std::string text, int startIndex, char endChar);
    void debug(int nb);
    std::string capitalize(const std::string str);
    std::vector<std::string> split(std::string text, char poundSign);
    std::string autocomplete(std::vector<std::string> key_words, std::string input);
    std::string combine(std::vector<std::string> words);
}
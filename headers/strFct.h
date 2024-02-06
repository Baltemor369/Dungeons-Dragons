#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>


std::string lower(std::string str);
bool isIn(std::string str, std::vector<std::string> list);
std::vector<std::string> split(std::string text, char poundSign);
std::string mySubStr(const std::string text, int startIndex, char endChar);
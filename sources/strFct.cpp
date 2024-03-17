#include "../headers/strFct.h"

std::string Str::lower(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return str;
}

std::string Str::capitalize(const std::string str) {
    std::string result = str;

    if (!result.empty()) {
        // Met la première lettre en majuscule
        result[0] = std::toupper(result[0]);

        // Met le reste de la chaîne en minuscule
        for (size_t i = 1; i < result.length(); ++i) {
            result[i] = std::tolower(result[i]);
        }
    }

    return result;
}

bool Str::isIn(std::string str, std::vector<std::string> list){
    for (int i = 0; i < list.size(); ++i)
    {
        if (str == list[i])
        {
            return true;
        }
    }
    return false;
}

std::string Str::mySubStr(const std::string text, int startIndex, char endChar){
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

void Str::debug(int nb){
    std::cout << "Debug "<<nb<<std::endl;
}

std::string Str::autocomplete(std::vector<std::string> key_words, std::string input){
    // final var for the full complete command returned
    std::vector<std::string> full_command = {};
    // a temporary std::vector clear at each word of the input
    std::vector<std::string> matches;
    // the list of words from the input
    std::vector<std::string> input_words = split(input, ' ');

    for (std::string w : input_words)
    {
        std::string w2 = capitalize(w);
        matches = {};
        for (const std::string& key : key_words){
            std::string key2 = capitalize(key);
            // if the input word find in a key word
            if (key2.find(w2) == 0)
            {
                // add it to the temporary list
                matches.push_back(key);
                break;
            }
        }
        // at the end, if only one match, add to the final command
        if (matches.size() == 1)
        {
            full_command.push_back(matches[0] + " ");
        }                           
    }
    std::string command = combine(full_command);
    return command.substr(0, command.size() - 1);
}

std::string Str::combine(std::vector<std::string> words){
    std::string result = "";
    for(auto word : words){
        result += word;
    }
    return result;
}

std::vector<std::string> Str::split(std::string input, char mark){
    std::vector<std::string> result = {};
    std::string buffer("");
    bool bufferEmpty = true;
    for (char c : input){
        if (c == mark)
        {
            result.push_back(buffer);
            buffer = "";
            bufferEmpty = true;
        }else{
            buffer += c;
            bufferEmpty = false;
        }
    }
    if (!bufferEmpty)
    {
        result.push_back(buffer);
    }
    
    return result;
}
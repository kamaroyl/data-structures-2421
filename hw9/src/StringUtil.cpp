#include "StringUtil.hpp"
std::string stripNonAlphaCharacters(std::string word) {
    word.erase(std::remove_if(word.begin(), word.end(), std::not1(std::ptr_fun( (int(*)(int))std::isalnum))), word.end());
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}



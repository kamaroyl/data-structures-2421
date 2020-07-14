#ifndef STRINGS_UTILS
#define STRINGS_UTILS
#include <algorithm>
#include <sstream>
#include <string>

 /***********************************
 *    String to Bool conversion    *
 ***********************************/
bool stringToBool(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    if(str == "1") return true;
    std::istringstream ss(str);
    bool b;
    ss >> std::boolalpha >> b;
    return b;
}

std::string boolToString(bool value) {
    if(value) return "true";
    return "false";
}   
#endif

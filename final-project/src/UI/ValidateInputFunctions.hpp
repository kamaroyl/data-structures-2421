#ifndef VALIDATE_INPUT_FUNCTIONS_HPP
#define VALIDATE_INPUT_FUNCTIONS_HPP
#include <fstream>
#include <string>

bool validateFilePath(std::string fp) {
    std::ifstream f(fp);
    return f.good();
}

#endif

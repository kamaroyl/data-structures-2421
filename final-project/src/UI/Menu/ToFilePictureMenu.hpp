#ifndef TO_FILE_PICTURE_MENU_HPP
#define TO_FILE_PICTURE_MENU_HPP
#include <string>
#include "MenuBase.hpp"
class ToFilePictureMenu: public MenuBase {
    private:
        std::string filePath;    
    public:
        ToFilePictureMenu();
        void printMenu();
        std::string getUserInfo();
        
        void clear();
        std::string getFilePath();
};
#endif

#ifndef DELETE_PICTURE_MENU_HPP
#define DELETE_PICTURE_MENU_HPP
#include <string>
#include "../../Data/Picture.hpp"
#include "MenuBase.hpp"
class DeletePictureMenu: public MenuBase {
    private:
       Picture* picture;
       std::string confirmMenu();
    public:
        DeletePictureMenu();
        void printMenu();
        std::string getUserInfo();
        void setPicture(Picture* picture);
        Picture* getPicture();
        void clear();
};
#endif

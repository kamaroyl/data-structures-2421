#ifndef EDIT_PICTURE_MENU_HPP
#define EDIT_PICTURE_MENU_HPP
#include "MenuBase.hpp"
#include "../../Data/Picture.hpp"
class EditPictureMenu: public MenuBase {
    private:
        Picture* picture;
        std::string name;
        std::string year;
        std::string nominations; 
        std::string rating;
        std::string duration;
        std::string genre1;
        std::string genre2;
        std::string release;
        std::string metacritic;
        std::string synopsis;
        
        void printMonths();
        void printGenre();

    public:
        EditPictureMenu();
        ~EditPictureMenu();
        void printMenu();
        std::string getUserInfo();
        void setPicture(Picture* picture);
        Picture* getPicture();
        bool submit();
        void clear();
        void setName();
        void setYear();
        void setNominations();
        void setRating();
        void setDuration();
        void setGenre1();
        void setGenre2();
        void setRelease();
        void setMetacritic();
        void setSynopsis();
};
#endif

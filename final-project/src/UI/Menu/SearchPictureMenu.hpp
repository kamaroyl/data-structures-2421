#ifndef SEARCH_PICTURE_MENU_HPP
#define SEARCH_PICTURE_MENU_HPP
#include <string>
#include "MenuBase.hpp"
class SearchPictureMenu: public MenuBase {
    private:
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
        SearchPictureMenu();
        void printMenu();
        std::string getUserInfo();
       
        std::string getName();
        std::string getYear();
        std::string getNominations();
        std::string getRating();
        std::string getDuration();
        std::string getGenre1();
        std::string getGenre2();
        std::string getRelease();
        std::string getMetacritic();
        std::string getSynopsis();

        void setNameFilter();
        void setYearFilter();
        void setNominationsFilter();
        void setRatingFilter();
        void setDurationFilter();
        void setGenre1Filter();
        void setGenre2Filter();
        void setReleaseFilter();
        void setMetacriticFilter();
        void setSynopsisFilter();
        
        void clear();
};
#endif

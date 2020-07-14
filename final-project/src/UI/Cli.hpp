#ifndef CLI_UI_HPP
#define CLI_UI_HPP
#include <string>
#include "../../lib/BSNode.hpp"
#include "../Data/Actor.hpp"
#include "../Data/Comparators/ActorComparator.hpp"
#include "../Data/Picture.hpp"
#include "../Data/Comparators/PictureComparator.hpp"
#include "../Business/TreeManager.hpp"
#include "../FileHandling/CsvParser.hpp"
#include "../FileHandling/CsvWriter.hpp"
#include "Menu/ExitMenu.hpp"
#include "Menu/MenuBase.hpp"
#include "Menu/ActorMenu.hpp"
#include "Menu/ToFileActorMenu.hpp"
#include "Menu/AddActorMenu.hpp"
#include "Menu/AddPictureMenu.hpp"
#include "Menu/DeleteActorMenu.hpp"
#include "Menu/DeletePictureMenu.hpp"
#include "Menu/EditActorMenu.hpp"
#include "Menu/EditPictureMenu.hpp"
#include "Menu/MainMenu.hpp"
#include "Menu/PictureMenu.hpp"
#include "Menu/ToFilePictureMenu.hpp"
#include "Menu/SearchActorMenu.hpp"
#include "Menu/SearchPictureMenu.hpp"
#include "../Data/Filters/ActorFilterAward.hpp"
#include "../Data/Filters/ActorFilterFilm.hpp"
#include "../Data/Filters/ActorFilterName.hpp"
#include "../Data/Filters/ActorFilterWinner.hpp"
#include "../Data/Filters/ActorFilterYear.hpp"

#include "../Data/Filters/PictureFilter.hpp"
#include "../Data/Filters/PictureFilterDuration.hpp"
#include "../Data/Filters/PictureFilterGenre1.hpp"
#include "../Data/Filters/PictureFilterGenre2.hpp"
#include "../Data/Filters/PictureFilterMetacritic.hpp"
#include "../Data/Filters/PictureFilterMonth.hpp"
#include "../Data/Filters/PictureFilterName.hpp"
#include "../Data/Filters/PictureFilterNominations.hpp"
#include "../Data/Filters/PictureFilterRating.hpp"
#include "../Data/Filters/PictureFilterSynopsis.hpp"
#include "../Data/Filters/PictureFilterYear.hpp"

class Cli {
    private:
        MenuBase** menuMap;
        const int menuCount = 14;
        int state;
        TreeManager* treeManager;
        CsvParser* csvReader;
        CsvWriter* csvWriter;

        //Functions
       BSNode<Actor>* getActorId();
       BSNode<Picture>* getPictureId();

    public:
        Cli();
        ~Cli();
        std::string getActorPath();
        std::string getPicturePath();

        void printMenu();
        std::string getUserInput();

        void setTreeManager(TreeManager* tm);
        void setCsvParser(CsvParser* cp);
        void setCsvWriter(CsvWriter* cw);

        bool handleInput(std::string input);

        void handleMainMenuInput(std::string input);

        void handleActorMenuInput(std::string input);
        void handleAddActorMenuInput(std::string input);
        void handleEditActorMenuInput(std::string input);
        void handleDeleteActorMenuInput(std::string input);
        void handleSearchActorMenuInput(std::string input);
        void handleToFileActorMenuInput(std::string input);

        void handlePictureMenuInput(std::string input);
        void handleAddPictureMenuInput(std::string input);
        void handleEditPictureMenuInput(std::string input);
        void handleDeletePictureMenuInput(std::string input);
        void handleSearchPictureMenuInput(std::string input);
        void handleToFilePictureMenuInput(std::string input);
        
        void handleExit(std::string input);
};

#endif

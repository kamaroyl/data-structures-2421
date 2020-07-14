#include "../src/Data/Actor.hpp"
#include "../src/Data/Picture.hpp"
#include "../src/Data/Comparators/ActorComparator.hpp"
#include "../src/Data/Comparators/PictureComparator.hpp"
#include "../src/Data/Filters/ActorFilter.hpp"

#include "../src/Data/Filters/ActorFilterAward.hpp"
#include "../src/Data/Filters/ActorFilterFilm.hpp"
#include "../src/Data/Filters/ActorFilterName.hpp"
#include "../src/Data/Filters/ActorFilterWinner.hpp"
#include "../src/Data/Filters/ActorFilterYear.hpp"

#include "../src/Data/Filters/PictureFilter.hpp"
#include "../src/Data/Filters/PictureFilterDuration.hpp"
#include "../src/Data/Filters/PictureFilterGenre1.hpp"
#include "../src/Data/Filters/PictureFilterGenre2.hpp"
#include "../src/Data/Filters/PictureFilterMetacritic.hpp"
#include "../src/Data/Filters/PictureFilterMonth.hpp"
#include "../src/Data/Filters/PictureFilterName.hpp"
#include "../src/Data/Filters/PictureFilterNominations.hpp"
#include "../src/Data/Filters/PictureFilterRating.hpp"
#include "../src/Data/Filters/PictureFilterSynopsis.hpp"
#include "../src/Data/Filters/PictureFilterYear.hpp"

#include "../src/Business/TreeManager.hpp"
#include "../src/FileHandling/CsvParser.hpp"
#include "../src/FileHandling/CsvWriter.hpp"

#include "../src/UI/Cli.hpp"
#include "../src/UI/Menu/ActorMenu.hpp"
#include "../src/UI/Menu/AddActorMenu.hpp"
#include "../src/UI/Menu/AddPictureMenu.hpp"
#include "../src/UI/Menu/DeleteActorMenu.hpp"
#include "../src/UI/Menu/EditActorMenu.hpp"
#include "../src/UI/Menu/EditPictureMenu.hpp"
#include "../src/UI/Menu/MainMenu.hpp"
#include "../src/UI/Menu/PictureMenu.hpp"
#include "../src/UI/Menu/SearchActorMenu.hpp"
#include "../src/UI/Menu/SearchPictureMenu.hpp"
#include "../src/UI/Menu/ToFileActorMenu.hpp"
#include "../src/UI/Menu/ToFilePictureMenu.hpp"

void testCli() {
    bool running = true;
    CsvParser* csvParser = new CsvParser();
    CsvWriter* csvWriter = new CsvWriter();
    TreeManager* tm = new TreeManager();
    std::vector<std::vector<std::string>*>* actorList = csvParser->parseCsv("../resource/actor-actress.csv");
    std::vector<std::vector<std::string>*>* pictureList = csvParser->parseCsv("../resource/pictures.csv");
    tm->createActorTreeFromStrings(actorList);
    tm->createPictureTreeFromStrings(pictureList);
    Cli cli;
    cli.setTreeManager(tm);
    cli.setCsvParser(csvParser);
    cli.setCsvWriter(csvWriter);
    while(running) {
        cli.printMenu();
        std::string userInput = cli.getUserInput();
        running = cli.handleInput(userInput);
    }
    std::cout <<"Goodbye" << std::endl;
}

int main() {
    testCli();
    return 0;
}

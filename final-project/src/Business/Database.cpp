#include "Database.hpp"

Database::Database() {
    this->csvReader = new CsvParser();
    this->csvWriter = new CsvWriter();
    this->treeManager = TreeManager();
    this->cli = new Cli(this->treeManager, this->csvReader, this->csvWriter);
    this->running = false;
}

Database::~Database() {
    delete cli
}

void Database::run() {
    std::string actorFp = cli->getActorPath();
    std::string pictureFp = cli->getPicturePath();

    this->treeManager->createActorTreeFromStrings(scvReader->parseCsv(actorFp));
    this->treeManager->createPictureTreeFromStrings(csvReader->parseCsv(pictureFp));
    
    
    this->running = true;
    while(running) {    
        this->cli->printMenu();
        std::string userInput = this->cli->getUserInput();
        this->running = this->cli->handleInput(userInput);
        
    }
    std::cout << std::endl << "Goodbye" << std::endl;

}


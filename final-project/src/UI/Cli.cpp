#include "Cli.hpp"

Cli::Cli() {
    this->menuMap[this->menuCount];
    this->menuMap[0] = new MainMenu(); 
    this->menuMap[1] = new ActorMenu();
    this->menuMap[2] = new AddActorMenu();
    this->menuMap[3] = new EditActorMenu();
    this->menuMap[4] = new DeleteActorMenu();
    this->menuMap[5] = new SearchActorMenu();
    this->menuMap[6] = new ToFileActorMenu();
    this->menuMap[7] = new PictureMenu();
    this->menuMap[8] = new AddPictureMenu();
    this->menuMap[9] = new EditPictureMenu();
    this->menuMap[10] = new DeletePictureMenu();
    this->menuMap[11] = new SearchPictureMenu();
    this->menuMap[12] = new ToFilePictureMenu();
    this->menuMap[13] = new ExitMenu();
    this->state = 0;
}

Cli::~Cli() {
}

void Cli::setTreeManager(TreeManager* tm) {
    this->treeManager = tm;
}

void Cli::setCsvParser(CsvParser* cp) {
    this->csvReader = cp;
}

void Cli::setCsvWriter(CsvWriter* cw) {
    this->csvWriter = cw;
}

void Cli::printMenu() {
    this->menuMap[this->state]->printMenu();
}

std::string Cli::getUserInput() {
    return this->menuMap[this->state]->getUserInfo();
}

bool Cli::handleInput(std::string input) {
    switch(this->state) {
        case 0 :
            handleMainMenuInput(input);
            break;
        case 1 :
            handleActorMenuInput(input);
            break;
        case 2 :
            handleAddActorMenuInput(input);
            break;
        case 3 :
            handleEditActorMenuInput(input);
            break;
        case 4 :
            handleDeleteActorMenuInput(input);
            break;
        case 5 :
            handleSearchActorMenuInput(input);
            break;
        case 6 : 
            handleToFileActorMenuInput(input);
            break;
        case 7 :
            handlePictureMenuInput(input);
            break;
        case 8 :
            handleAddPictureMenuInput(input);
            break;
        case 9 :
            handleEditPictureMenuInput(input);
            break;
        case 10 :
            handleDeletePictureMenuInput(input);
            break;
        case 11 :
            handleSearchPictureMenuInput(input);
            break;
        case 12 :
            handleToFilePictureMenuInput(input);
            break;
        case 13 :
            handleExit(input);
            return false;
    }   
    return true;
}

void Cli::handleMainMenuInput(std::string input) {
    if(input == "A") {
        this->state = 1;
    } else if( input == "P") {
        this->state = 5;
    } else {
        this->state = 13;
    }
}

void Cli::handleActorMenuInput(std::string input) {
    if(input == "A") {
        this->state = 2;
    } else if(input == "E") {
        BSNode<Actor>* searchNode = getActorId(); 
        BSNode<Actor>* resultNode = this->treeManager->getActorTree()->findNode(searchNode->getData());
        (dynamic_cast<EditActorMenu*> (this->menuMap[3]))->setActor(resultNode->getData());
        this->state = 3;
    } else if(input == "D") {
        BSNode<Actor>* searchNode = getActorId();
        BSNode<Actor>* resultNode = this->treeManager->getActorTree()->findNode(searchNode->getData());
        (dynamic_cast<DeleteActorMenu*>(this->menuMap[4]))->setActor(resultNode->getData());
        this->state = 4;
    } else if(input == "S") {
        this->state = 5;
    } else if(input == "B") {
        this->state = 0;
    } else {
        this->state = 13;
        //quit
    }
}

void Cli::handleAddActorMenuInput(std::string input) {
    if(input == "S") {
        Actor* addActorPtr = (dynamic_cast<AddActorMenu*>(this->menuMap[2]))->getActor();
        this->treeManager->addActorToTree(addActorPtr);
        (dynamic_cast<AddActorMenu*>(this->menuMap[2]))->clear();
        this->state = 1; 
    } else if(input == "B") {
        (dynamic_cast<AddActorMenu*>(this->menuMap[2]))->clear();
        this->state = 1;
    } else {
        this->state = 13;
        //quit
    }
}

void Cli::handleEditActorMenuInput(std::string input) {
    if(input == "S") {
        (dynamic_cast<EditActorMenu*>(this->menuMap[3]))->clear();
        this->state = 1;
    } else if(input == "B") {
        (dynamic_cast<EditActorMenu*>(this->menuMap[3]))->clear();
        this->state = 1;
    } else {
        this->state = 13;
    }
}

void Cli::handleDeleteActorMenuInput(std::string input) {
    if(input == "S"){
        Actor* actorToDelete = (dynamic_cast<DeleteActorMenu*>(this->menuMap[4]))->getActor();
        BSNode<Actor>* dNode = new BSNode<Actor>();
        dNode->setData(actorToDelete);
        this->treeManager->getActorTree()->deleteNode(dNode);
        (dynamic_cast<DeleteActorMenu*>(this->menuMap[4]))->clear();
        this->state = 1;
    } else if(input == "B") {
        (dynamic_cast<DeleteActorMenu*>(this->menuMap[4]))->clear();
        this->state = 1;
    } else {
        this->state = 13;
    }
}

void Cli::handleSearchActorMenuInput(std::string input) {
    ActorComparator* ac = nullptr;
    //copy comparator from latest tree
    if(this->treeManager->isTmpActorStackEmpty()) {
        ac = new ActorComparator(this->treeManager->getActorTree()->getComparator());
    } else {
        ac = new ActorComparator(this->treeManager->getTmpActorTree()->getComparator());
    }
    if(input == "Y") {
        std::string year = (dynamic_cast<SearchActorMenu*>(this->menuMap[5]))->getYear();
        ActorFilterYear* af = new ActorFilterYear();
        af->setValue(year);
        ac->setYear(1);
        this->treeManager->addFilteredActorTreeToStack(af, ac);
    } else if(input == "A") {
        std::string award = (dynamic_cast<SearchActorMenu*>(this->menuMap[5]))->getAward();
        ActorFilterAward* af = new ActorFilterAward();
        af->setValue(award);
        ac->setAward(1);
        this->treeManager->addFilteredActorTreeToStack(af, ac);
    } else if(input == "W") {
        std::string winner = (dynamic_cast<SearchActorMenu*>(this->menuMap[5]))->getWinner();
        ActorFilterWinner* af = new ActorFilterWinner();
        af->setValue(winner);
        ac->setWinner(1);
        this->treeManager->addFilteredActorTreeToStack(af, ac);
    } else if(input == "N") {
        std::string name = (dynamic_cast<SearchActorMenu*>( this->menuMap[5]))->getName();
        ActorFilterName* af = new ActorFilterName();
        af->setValue(name);
        ac->setName(1);
        this->treeManager->addFilteredActorTreeToStack(af, ac);
    } else if(input == "F") {
        std::string film = (dynamic_cast<SearchActorMenu*>( this->menuMap[5]))->getFilm();
        ActorFilterFilm* af = new ActorFilterFilm();
        af->setValue(film);
        ac->setFilm(1);
        this->treeManager->addFilteredActorTreeToStack(af, ac);
    } else if(input == "P") {
        this->treeManager->printActorTree();
    } else if(input == "B") {
        this->treeManager->clearActorStack();
        this->state = 1;
    } else {
        this->state = 13; 
    }
}

void Cli::handleToFileActorMenuInput(std::string input) {
    if(input == "S") {
        std::string filePath = (dynamic_cast<ToFileActorMenu*> (this->menuMap[6]))->getFilePath();
        this->csvWriter->writeVectorizedObjects(filePath, this->treeManager->getActorHeader(), this->treeManager->actorTreeToVector());
        (dynamic_cast<ToFileActorMenu*>( this->menuMap[6]))->clear();
        this->state = 1;
    } else if(input == "B") {
        (dynamic_cast<ToFileActorMenu*> ( this->menuMap[6]))->clear();
        this->state = 1;
    } else {
        this->state = 13;
    }
}

void Cli::handlePictureMenuInput(std::string input) {
    if(input == "A") {
        this->state = 8;
    } else if(input == "E") { 
        BSNode<Picture>* searchNode = getPictureId();
        BSNode<Picture>* resultNode = this->treeManager->getPictureTree()->findNode(searchNode->getData());
        (dynamic_cast<EditPictureMenu*>(this->menuMap[9]))->setPicture(resultNode->getData());
        this->state = 9;
    } else if(input == "D") {
        BSNode<Picture>* searchNode = getPictureId();
        BSNode<Picture>* resultNode = this->treeManager->getPictureTree()->findNode(searchNode->getData());
        (dynamic_cast<DeletePictureMenu*>(this->menuMap[10]))->setPicture(resultNode->getData());
        this->state = 10;
    } else if(input == "S") {
        this->state = 11;
    } else if(input == "F") {
        this->state = 12;
    } else if(input == "B") {
        this->state = 0;
    } else {
        this->state = 13;
    }

}

void Cli::handleAddPictureMenuInput(std::string input) {
    if(input == "S") {
        Picture* addPicturePtr = (dynamic_cast<AddPictureMenu*>(this->menuMap[8]))->getPicture();
        this->treeManager->addPictureToTree(addPicturePtr);
        (dynamic_cast<AddPictureMenu*>(this->menuMap[8]))->clear();
        this->state = 7;
    } else if(input == "B") {
        (dynamic_cast<AddPictureMenu*>(this->menuMap[8]))->clear();
        this->state = 7;
    } else {
        this->state = 13;
    }

}

void Cli::handleEditPictureMenuInput(std::string input) {
    if(input == "S") {
        (dynamic_cast<EditPictureMenu*>(this->menuMap[9]))->clear();
        this->state = 7;
    } else if(input == "B") {
        (dynamic_cast<EditPictureMenu*>(this->menuMap[9]))->clear();
        this->state = 7;
    } else {
        this->state = 13;
    }
   
}

void Cli::handleDeletePictureMenuInput(std::string input) {
    if(input == "S") {
        Picture* pictureToDelete = (dynamic_cast<DeletePictureMenu*>(this->menuMap[10]))->getPicture();
        BSNode<Picture>* dNode = new BSNode<Picture>();
        dNode->setData(pictureToDelete);
        this->treeManager->getPictureTree()->deleteNode(dNode);
        (dynamic_cast<DeletePictureMenu*> (this->menuMap[10]))->clear();
        this->state = 7;
    } else if(input == "B") {
        (dynamic_cast<DeletePictureMenu*>(this->menuMap[10]))->clear();
        this->state = 7;
    } else {
        this->state = 13;
    }

}

void Cli::handleSearchPictureMenuInput(std::string input) {
    PictureComparator* pc = nullptr;
    if(this->treeManager->isTmpPictureStackEmpty()) {
        pc = new PictureComparator(this->treeManager->getPictureTree()->getComparator());
    } else {
        pc = new PictureComparator(this->treeManager->getTmpPictureTree()->getComparator());
    }

    if(input == "Y") {
        std::string year = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getYear();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(year);
        pc->setYear(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "N") {
        std::string name = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getName();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(name);
        pc->setName(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "T") {
        std::string nominations= (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getNominations();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(nominations);
        pc->setNominations(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "4") {
        std::string rating = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getRating();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(rating);
        pc->setRating(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "D") {
        std::string duration = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getDuration();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(duration);
        pc->setDuration(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "1") {
        std::string genre1 = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getGenre1();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(genre1);
        pc->setGenre1(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "2") {
        std::string genre2 = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getGenre2();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(genre2);
        pc->setGenre2(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "L") {
        std::string release = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getRelease();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(release);
        pc->setRelease(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "M") {
        std::string metacritic = (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getMetacritic();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(metacritic);
        pc->setMetacritic(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc);
    } else if(input == "3") {
        std::string synopsis= (dynamic_cast<SearchPictureMenu*>(this->menuMap[11]))->getSynopsis();
        PictureFilter* pf = new PictureFilter();
        pf->setValue(synopsis);
        pc->setSynopsis(1);
        this->treeManager->addFilteredPictureTreeToStack(pf, pc); 
    } else if(input == "P") {
        this->treeManager->printPictureTree();
    } else if(input == "B") {
        this->treeManager->clearPictureStack();
        this->state = 7;
    } else {
        this->state = 13;
    }

}

void Cli::handleToFilePictureMenuInput(std::string input) {
    if(input == "S") {
        std::string filePath = (dynamic_cast<ToFilePictureMenu*> (this->menuMap[12]))->getFilePath();
        this->csvWriter->writeVectorizedObjects(filePath, this->treeManager->getPictureHeader(), this->treeManager->pictureTreeToVector());
        (dynamic_cast<ToFilePictureMenu*>( this->menuMap[12]))->clear();
        this->state = 7;
    } else if(input == "B") {
        (dynamic_cast<ToFilePictureMenu*> ( this->menuMap[12]))->clear();
        this->state = 7;
    } else {
        this->state = 13;
    }
}

void Cli::handleExit(std::string input) {

}

BSNode<Actor>* Cli::getActorId() {
    std::string input = "";
    std::cout << "Please enter an Actor ID " << std::endl;
    std::cout << "Valid IDs range from 0 to " << this->treeManager->getActorTree()->getCount() << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(this->menuMap[0]->isNumber(&input)) break;
        else {
            std::cout << "Please enter a number. " << input << " is not a number." << std::endl;
        }
    }

    Actor* searchActor = new Actor();
    searchActor->setIndex(std::stoi(input));
    BSNode<Actor>* searchNode = new BSNode<Actor>();
    searchNode->setData(searchActor);
    return searchNode;
}

BSNode<Picture>* Cli::getPictureId() {
    std::string input = "";
    std::cout << "Please enter a Picture ID " << std::endl;
    std::cout << "Valid IDs range from 0 to " << this->treeManager->getPictureTree()->getCount() << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(this->menuMap[0]->isNumber(&input)) break;
        else {
            std::cout << "Please enter a number. " << input << " is not a number." << std::endl;
        }
    }
    
    Picture* searchPicture = new Picture();
    searchPicture->setIndex(input);
    BSNode<Picture>* searchNode = new BSNode<Picture>();
    searchNode->setData(searchPicture);
    return searchNode;
}

std::string Cli::getActorPath() {
    std::string input = "Resource/actor-actress.csv";
    std::cout << "Please enter a path for actors. Will default to \"Resource/actor-actress.csv";
    std::getline(std::cin, input);
    if(input.empty()) std::cout << "Defaulting. . . " << std::endl;
    return input;
}

std::string Cli::getPicturePath() {
    std::string input = "Resource/actor-actress.csv";
    std::cout << "Please enter a path for actors. Will default to \"Resource/picture.csv";
    std::getline(std::cin, input);
    if(input.empty()) std::cout << "Defaulting. . . " << std::endl;
    return input;
   
}

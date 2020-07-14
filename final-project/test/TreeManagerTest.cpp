#include <iostream>
#include <string>
#include <vector>
#include "../src/Data/Filters/ActorFilter.hpp"
#include "../src/Data/Filters/ActorFilterName.hpp"
#include "../src/Data/Filters/ActorFilterAward.hpp"
#include "../src/Data/Filters/ActorFilterWinner.hpp"
#include "../src/Data/Filters/ActorFilterFilm.hpp"
#include "../src/Data/Filters/ActorFilterYear.hpp"
#include "../src/Data/Filters/PictureFilter.hpp"
#include "../src/Data/Filters/PictureFilterDuration.hpp"
#include "../src/Data/Filters/PictureFilterGenre1.hpp"
#include "../src/Data/Filters/PictureFilterGenre2.hpp"
#include "../src/Data/Filters/PictureFilterMonth.hpp"
#include "../src/Data/Filters/PictureFilterName.hpp"
#include "../src/Data/Filters/PictureFilterNominations.hpp"
#include "../src/Data/Filters/PictureFilterRating.hpp"
#include "../src/Data/Filters/PictureFilterSynopsis.hpp"
#include "../src/Data/Filters/PictureFilterYear.hpp"
#include "../src/FileHandling/CsvParser.hpp"
#include "../src/Data/Actor.hpp"
#include "../src/Data/Comparators/ActorComparator.hpp"
#include "../src/Data/Picture.hpp"
#include "../src/Business/TreeManager.hpp"

std::vector<std::vector<std::string>*>* createTestInput(int limit) { 
    std::vector<std::vector<std::string>*>* input = new std::vector<std::vector<std::string>*>();
    for(int i = 0; i < 10; i++) {
        std::vector<std::string>* actorString = new std::vector<std::string>();
        std::string number = std::to_string(i);
        for(int j = 0; j < limit; j++) {
            actorString->push_back(number);              
        }
        input->push_back(actorString);
    }
    return input;
}
 
void testCreateActorTreeFromStrings() {
    std::cout << "testCreateActorTreeFromString()" << std::endl;
    TreeManager tm;
    std::vector<std::vector<std::string>*>* input = createTestInput(5);
    tm.createActorTreeFromStrings(input);
    BSTree<Actor, ActorComparator>* testTree = tm.getActorTree();
    testTree->traversePostorder(printNode); 
    delete input;
}

void testCreatePictureTreeFromStrings() {
    std::cout << "testCreatePictureTreeFromStrings()" << std::endl;
    TreeManager tm;
    tm.createPictureTreeFromStrings(createTestInput(12));
    BSTree<Picture, PictureComparator>* testTree = tm.getPictureTree();
    testTree->traverseInorder(printNode);
}


void testAddFilteredActorTreeToStack() {
    std::cout << "testAddFilteredActorTreeToStack()" << std::endl;
    TreeManager tm;
    CsvParser csvParser;
    std::string fp = "../resource/actor-actress.csv";
    std::vector<std::vector<std::string>*>* input = csvParser.parseCsv(fp);
    tm.createActorTreeFromStrings(input);
    //tm.printActorTree();
    ActorFilter* af = new ActorFilterName();
    af->setValue("Betty");
    ActorComparator* ac = new ActorComparator();
    ac->setName(10);
    std::cout <<"set up filter and comparator" << std::endl;
    tm.addFilteredActorTreeToStack(af, ac);
    tm.printActorTree();
}

void testAddFilteredActorTreeToStackMulti() {
    std::cout << "testAddFilteredActorTreeToSTackMulti()" << std::endl;
    TreeManager tm;
    CsvParser csvParser;
    std::string fp = "../resource/actor-actress.csv";
    std::vector<std::vector<std::string>*>* input = csvParser.parseCsv(fp);
    tm.createActorTreeFromStrings(input);

    ActorFilter* af1 = new ActorFilterAward();
    af1->setValue("Leading");
    ActorComparator* ac1 = new ActorComparator();
    ac1->setAward(2);

    std::cout <<"set up filter and comparator" << std::endl;
    tm.addFilteredActorTreeToStack(af1, ac1);
    std::cout << "First Filter" << std::endl;
    tm.printActorTree();
    ActorComparator* ac2 = new ActorComparator(tm.getTmpActorTree()->getComparator());
    ac2->setName(1);
    ActorFilter* af2 = new ActorFilterName();
    af2->setValue("Paul");
    tm.addFilteredActorTreeToStack(af2, ac2);
    std::cout << "Second Filter" << std::endl;
    tm.printActorTree();
    
    ActorFilter* af3 = new ActorFilterWinner();
    af3->setValue("false");
    ActorComparator* ac3 = new ActorComparator(tm.getTmpActorTree()->getComparator());
    ac3->setWinner(1);
    tm.addFilteredActorTreeToStack(af3, ac3);
    std::cout << "Third filter" << std::endl;
    tm.printActorTree();

    ActorFilter* af4 = new ActorFilterFilm();
    af4->setValue("Val");
    ActorComparator* ac4 = new ActorComparator(tm.getTmpActorTree()->getComparator());
    ac4->setFilm(1);
    tm.addFilteredActorTreeToStack(af4, ac4);
    std::cout << "Fourth Filter" << std::endl;
    tm.printActorTree();
    
    ActorFilter* af5 = new ActorFilterYear();
    af5->setValue("1989");
    ActorComparator* ac5 = new ActorComparator(tm.getTmpActorTree()->getComparator());
    ac5->setYear(1);
    tm.addFilteredActorTreeToStack(af5, ac5);
    std::cout << "Fifth Filter" << std::endl;
    tm.printActorTree();
    tm.clearActorStack();   
    std::cout << "Cleared" << std::endl;
    tm.printActorTree();
    
}

void testAddFilteredPictureTreeToStack() {
    std::cout << "testAddFilteredPictureTreeToStack()" << std::endl;
    TreeManager tm;
    CsvParser csvParser;
    std::string fp = "../resource/pictures.csv";
    std::vector<std::vector<std::string>*>* input = csvParser.parseCsv(fp);
    tm.createPictureTreeFromStrings(input);
    tm.printPictureTree();
    
    PictureComparator* pc = new PictureComparator();
    pc->setGenre1(1);
    PictureFilter* pf = new PictureFilterGenre1();
    pf->setValue("Comedy");
    tm.addFilteredPictureTreeToStack(pf, pc);
    std::cout << "Filtering Pictures" << std::endl;
    tm.printPictureTree(); 
}

int main() {
    testCreateActorTreeFromStrings();
    testCreatePictureTreeFromStrings();
    testAddFilteredActorTreeToStack();
    testAddFilteredActorTreeToStackMulti();
    testAddFilteredPictureTreeToStack();
    return 0;
}

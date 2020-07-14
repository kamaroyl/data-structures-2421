#include "TreeManager.hpp"
#include <iostream>
TreeManager::TreeManager() {
    ActorComparator *ac = new ActorComparator();
    PictureComparator *pc = new PictureComparator();
    this->actors = new BSTree<Actor, ActorComparator>(ac, false);
    this->pictures = new BSTree<Picture, PictureComparator>(pc, false);
}

TreeManager::~TreeManager() {
    delete this->actors;
    delete this->pictures;
}

BSTree<Actor, ActorComparator>* TreeManager::getActorTree() {
    return this->actors;
}

BSTree<Actor, ActorComparator>* TreeManager::getTmpActorTree() {
    return this->tmpActorStack.top();
}

BSTree<Picture, PictureComparator>* TreeManager::getPictureTree() {
    return this->pictures;
}

BSTree<Picture, PictureComparator>* TreeManager::getTmpPictureTree() {
    return this->tmpPictureStack.top();
}

void TreeManager::createActorTreeFromStrings(std::vector<std::vector<std::string>*>* stringArgs) {
    unsigned int indexCount = 0;
    std::vector<BSNode<Actor>*> inputActors;
    for(std::vector<std::vector<std::string>*>::iterator it = stringArgs->begin(); it != stringArgs->end(); ++it) {
        BSNode<Actor>* actorNode = new BSNode<Actor>();
                                 // index  ,  year    ,  award   ,   winner ,  name    ,  film 
        Actor* actor = new Actor(indexCount, (**it)[0], (**it)[1], (**it)[2], (**it)[3], (**it)[4]);
         
        actorNode->setData(actor);
        inputActors.push_back(actorNode);
        indexCount++;
    }
    //randomize input so we don't end up with a linked list
    std::random_shuffle(inputActors.begin(), inputActors.end());
    for(std::vector<BSNode<Actor>*>::iterator it2 = inputActors.begin(); it2 != inputActors.end(); ++it2) {
        this->actors->addNode(*it2);
    }
 
}

void TreeManager::createPictureTreeFromStrings(std::vector<std::vector<std::string>*>* stringArgs) {
    unsigned int indexCount = 0;
    std::vector<BSNode<Picture>*> inputPictures;
    for(std::vector<std::vector<std::string>*>::iterator it = stringArgs->begin(); it != stringArgs->end(); ++it) {
        BSNode<Picture>* pictureNode = new BSNode<Picture>();
                                        // index , name     ,  year    ,  noms    ,  rating  ,  duration,  genre1  ,  genre2 ,   release ,  metacr  ,  synopsis
        Picture* picture = new Picture(indexCount, (**it)[0], (**it)[1], (**it)[2], (**it)[3], (**it)[4], (**it)[5], (**it)[6], (**it)[7], (**it)[8], (**it)[9]);
        pictureNode->setData(picture);
        inputPictures.push_back(pictureNode);
        indexCount++;
    }
    std::random_shuffle(inputPictures.begin(), inputPictures.end());
    for(std::vector<BSNode<Picture>*>::iterator it2 = inputPictures.begin(); it2 != inputPictures.end(); ++it2) {
        this->pictures->addNode(*it2);
    }

}

bool TreeManager::isActorsNull() {
    if(this->actors == nullptr) return true;
    return false;
}

bool TreeManager::isPicturesNull() {
    if(this->pictures == nullptr) return true;
    return false;
}

bool TreeManager::isTmpActorStackEmpty() {
    return this->tmpActorStack.empty();
}

bool TreeManager::isTmpPictureStackEmpty() {
    return this->tmpPictureStack.empty();
}

void TreeManager::addActorToTree(Actor* actor) {
    BSNode<Actor>* newActorNode = new BSNode<Actor>();
    newActorNode->setData(actor);
    this->actors->addNode(newActorNode);
}

void TreeManager::addPictureToTree(Picture* picture) {
    BSNode<Picture>* newPictureNode = new BSNode<Picture>();
    newPictureNode->setData(picture);
    this->pictures->addNode(newPictureNode);
}

/*
 * Preorder traversal where each element has filter called on it. If 
 *     the filter returns true, the Picture is added to a new tree. Otherwise
 *     continue.
 */
void TreeManager::addFilteredPictureTreeToStack(PictureFilter* pf, PictureComparator* pictureComparator) {
    BSTree<Picture, PictureComparator>* treeToBeFilteredPtr = nullptr;
    if(this->tmpPictureStack.empty()) treeToBeFilteredPtr = this->pictures;
    else treeToBeFilteredPtr = tmpPictureStack.top();
    BSNode<Picture>* currentPtr = treeToBeFilteredPtr->getRoot();
    BSTree<Picture, PictureComparator>* newTree = new BSTree<Picture, PictureComparator>(pictureComparator, true);
    
    std::stack<BSNode<Picture>*> nodeStack;
    
    while(currentPtr != nullptr || !nodeStack.empty()) {
        while(currentPtr != nullptr) {
            nodeStack.push(currentPtr);
            currentPtr = currentPtr->getLeft();
        }
        currentPtr = nodeStack.top();
        nodeStack.pop();
        if(pf->filter(currentPtr->getData())) {
            BSNode<Picture>* newPictureNode = new BSNode<Picture>();
            newPictureNode->setData(currentPtr->getData());
            newTree->addNode(newPictureNode);
        }
        currentPtr = currentPtr->getRight();
    }
    this->tmpPictureStack.push(newTree);
}

void TreeManager::removeFilteredPictureTreeFromStack() {
    if(this->tmpPictureStack.empty()) return;
    BSTree<Picture, PictureComparator>* tmp = this->tmpPictureStack.top();
    this->tmpPictureStack.pop();
    delete tmp;
}

void TreeManager::printActorTree() {
    if(this->tmpActorStack.empty()) {
        this->actors->traverseInorder(printNode);
    } else {
        this->tmpActorStack.top()->traverseInorder(printNode);
    }
}

void TreeManager::clearActorStack() {
    while(!this->tmpActorStack.empty()) {
        BSTree<Actor, ActorComparator>* tmp = this->tmpActorStack.top();
        this->tmpActorStack.pop();
        delete tmp;
    }
}

void TreeManager::clearPictureStack() {
    while(!this->tmpPictureStack.empty()) {
        BSTree<Picture,PictureComparator>* tmp = this->tmpPictureStack.top();
        this->tmpPictureStack.pop();
        delete tmp;
    }
}

void TreeManager::printPictureTree() {
    if(this->tmpPictureStack.empty()) {
        this->pictures->traverseInorder(printNode);
    } else {
        this->tmpPictureStack.top()->traverseInorder(printNode);
    }
}

/*
 * Preorder traversal where each element has filter called on it. If
 *    the filter reutnrs true, the Actor is added to the new tree. Otherwise,
 *    continue. The tree is then added to the stack.
 */
void TreeManager::addFilteredActorTreeToStack(ActorFilter* af, ActorComparator* actorComparator) {
    BSTree<Actor, ActorComparator>* treeToBeFilteredPtr = nullptr;
    if(this->tmpActorStack.empty()) treeToBeFilteredPtr = this->actors;
    else treeToBeFilteredPtr = tmpActorStack.top();
    BSNode<Actor>* currentPtr = treeToBeFilteredPtr->getRoot();
    BSTree<Actor, ActorComparator>* newTree = new BSTree<Actor, ActorComparator>(actorComparator, true);
    std::stack<BSNode<Actor>*> nodeStack;
    
    while(currentPtr != nullptr || !nodeStack.empty()) {
        while(currentPtr != nullptr) {
            nodeStack.push(currentPtr);
            currentPtr = currentPtr->getLeft();
        }
        currentPtr = nodeStack.top();
        nodeStack.pop();
        if(af->filter(currentPtr->getData())) {
            BSNode<Actor>* newActorNode = new BSNode<Actor>();
            newActorNode->setData(currentPtr->getData());
            newTree->addNode(newActorNode);
        }
        currentPtr = currentPtr->getRight();
    }
    newTree->traverseInorder(printNode);
    this->tmpActorStack.push(newTree);
}

void TreeManager::removeFilteredActorTreeFromStack() {
    if(this->tmpActorStack.empty()) return;
    BSTree<Actor,ActorComparator>* tmp = this->tmpActorStack.top();
    this->tmpActorStack.pop();
    delete tmp;
}

std::vector<std::string> TreeManager::actorTreeToVector() {

    std::vector<std::string> toFileVector;
    std::stack<BSNode<Actor>*> nodeStack;
    BSNode<Actor>* currentPtr = this->actors->getRoot();    
    while(currentPtr != nullptr || !nodeStack.empty()) {
        while(currentPtr != nullptr) {
            nodeStack.push(currentPtr);
            currentPtr = currentPtr->getLeft();
        }
        currentPtr = nodeStack.top();
        nodeStack.pop();
        toFileVector.push_back(currentPtr->getData()->toCsvFormat());
        currentPtr = currentPtr->getRight();
    }
    return toFileVector; 
}

std::vector<std::string> TreeManager::pictureTreeToVector() {
    std::vector<std::string> toFileVector;
    std::stack<BSNode<Picture>*> nodeStack;
    BSNode<Picture>* currentPtr = this->pictures->getRoot();
    
    while(currentPtr != nullptr || !nodeStack.empty()) {
        while(currentPtr != nullptr) {
            nodeStack.push(currentPtr);
            currentPtr = currentPtr->getLeft();
        }
        currentPtr = nodeStack.top();
        nodeStack.pop();
        toFileVector.push_back(currentPtr->getData()->toCsvFormat());
        currentPtr = currentPtr->getRight();
    }
    return toFileVector; 
}

std::string TreeManager::getActorHeader() {
    return "Year,Award,Winner,Name,Film";
}

std::string TreeManager::getPictureHeader() {
    return "Name,Year,Nominations,Rating,Duration,Genre1,Genre2,Release,Metacritic,Synopsis";
}


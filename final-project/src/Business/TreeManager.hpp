#ifndef TREE_MANAGER_HPP
#define TREE_MANAGER_HPP
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include "../../lib/BSTree.hpp"
#include "../../lib/BSNode.hpp"
#include "../Data/Actor.hpp"
#include "../Data/Picture.hpp"
#include "../Data/Comparators/ActorComparator.hpp"
#include "../Data/Comparators/PictureComparator.hpp"
#include "../Data/Filters/ActorFilter.hpp"
#include "../Data/Filters/PictureFilter.hpp"

class TreeManager {

    private:
        BSTree<Actor, ActorComparator>* actors;
        BSTree<Picture, PictureComparator>* pictures;
        std::stack<BSTree<Actor, ActorComparator>*> tmpActorStack;
        std::stack<BSTree<Picture, PictureComparator>*> tmpPictureStack;
        

    public:
        TreeManager();
        ~TreeManager();
        BSTree<Actor, ActorComparator>* getActorTree();
        BSTree<Picture, PictureComparator>* getPictureTree();
        BSTree<Actor, ActorComparator>* getTmpActorTree();
        BSTree<Picture, PictureComparator>* getTmpPictureTree();
        void createActorTreeFromStrings(std::vector<std::vector<std::string>*>* stringArgs);
        void createPictureTreeFromStrings(std::vector<std::vector<std::string>*>* stringArgs);
        
        void addFilteredActorTreeToStack(ActorFilter* filter, ActorComparator* actorComparator);
        void addFilteredPictureTreeToStack(PictureFilter* filter, PictureComparator* pictureComparator);
        void removeFilteredActorTreeFromStack();
        void removeFilteredPictureTreeFromStack();
        
        void printActorTree();
        void printPictureTree();

        void clearActorStack();
        void clearPictureStack();
        
        void addActorToTree(Actor* actor);
        void addPictureToTree(Picture* picture);
    
        bool isActorsNull();
        bool isPicturesNull();
        bool isTmpActorStackEmpty();
        bool isTmpPictureStackEmpty();

        std::vector<std::string> pictureTreeToVector();
        std::vector<std::string> actorTreeToVector();
        
        std::string getPictureHeader();
        std::string getActorHeader();
};
#endif

//To be used in conjunction with BNode.h and BTree<T, V>.cpp
//If you modify this, please add your name and list any changes that you made
// Ben Straub don't use std namespace
// Didn't like the way the class was layed out, refactor. 
// Move "print" to two methods
// One that traverses the tree and calls a function pointer
// One that prints the object at node. 
// That way we can do other things with the traversal. 
// Header 
#ifndef BTREE_HPP
#define BTREE_HPP
#include <iostream>
#include <stack>

#include "BSNode.hpp"

// Binary Search Tree class
template <typename T, typename C> //T data type C strict ordering compare functor 
class BSTree {
    private:
        //variables
        BSNode<T>* root;
        C* comparator;
        BSNode<T>* removeNode(BSNode<T>* node);
	 
    public:
        BSTree<T,C>(C* comparator);
        ~BSTree<T,C>();

        BSNode<T>* getRoot();
        void setRoot(BSNode<T>* root);
        
        void addNode(BSNode<T>* node);
        void deleteNode(BSNode<T>* node);
 
	BSNode<T>* findNode(T* value);
        
        /*
         *    Traversal methods - 
         *        methods will traverse the tree in the order indicated
         *        and execute a function that takes a node of the tree
         */ 
        void traverseInorder(void (*function)(BSNode<T>*));
        void traversePreorder(void (*function)(BSNode<T>*));
        void traversePostorder(void (*function)(BSNode<T>*));
        
        BSNode<T>* getMin();
	BSNode<T>* getMax();
};

#include "BSTree.tpp"
#endif

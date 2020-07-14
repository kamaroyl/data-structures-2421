//To be used in conjunction with BSTree.h and BSTree.hpp
//If you modify this, please add your name and list any changes that you made
/* Ben Straub
 * don't use std namespace
 * Change templating to use T and V instead of large names
 * hpp
 * Move data to pointer to data
 * Remove key
 * rename methods to be consistent verb-object camel case in naming
 */
#ifndef BS_NODE_HPP
#define BS_NODE_HPP
#include <iostream>

//B Tree Node
template <typename T>
class BSNode {
    private:
        T* data;
        BSNode<T>* left;
        BSNode<T>* right;
        BSNode<T>* parent;
        bool isSecondary;

    public:
        BSNode();
        BSNode(T* data); //copy constructor;
        ~BSNode(); 
        //Setters
	void setData(T* data);
        void setLeft(BSNode<T>* left);
        void setRight(BSNode<T>* right);
        void setParent(BSNode<T>* parent);
        void setIsSecondary(bool isSecondary); 
        //Getters
	T* getData();
        BSNode<T>* getLeft();
        BSNode<T>* getRight();
        BSNode<T>* getParent();
       

};
#include "BSNode.tpp"
#endif

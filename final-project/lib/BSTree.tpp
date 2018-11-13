//To be used in conjunction with BSTree.h and BSNode.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.hpp"

template <typename T, typename C>
BSTree<T,C>::BSTree(C* comparator) {
    this->root = nullptr;
    this->comparator = comparator;
}

template <typename T, typename C>
BSTree<T,C>::~BSTree() {
    if(this->comparator != nullptr) delete this->comparator;
    if(this->getRoot() == nullptr) return;
    if(this->getRoot()) {
        BSNode<T>* currentPtr = this->getRoot();
        std::stack<BSNode<T>*> nodeStack;
        while(this->getRoot()) {
            while(currentPtr != nullptr) {
                nodeStack.push(currentPtr);
                nodeStack.push(currentPtr);
                currentPtr = currentPtr->getLeft();
            }
        
            if(nodeStack.empty()) return;
            currentPtr = nodeStack.top();
            nodeStack.pop();
        
            if(!nodeStack.empty() && nodeStack.top() == currentPtr) currentPtr = currentPtr->getRight();
            else{
                
                BSNode<T>* tmpNode = removeNode(currentPtr);
                currentPtr = currentPtr->getParent();
                delete tmpNode;
            }
            if( this->getRoot() == nullptr ) {
                return;
            }
        }
    }

}

template <typename T, typename C>
BSNode<T>* BSTree<T,C>::getRoot() {

    return this->root;

}

template <typename T, typename C>
void BSTree<T,C>::addNode(BSNode<T>* node) {
    BSNode<T>* parentPtr = nullptr;
    if(this->getRoot() == nullptr) { //case empty tree
        this->root = node;
        return;
    }
    
    BSNode<T>* currentPtr = this->getRoot();
    while(currentPtr) {
        parentPtr = currentPtr;
        
        if((*comparator)(node->getData(), currentPtr->getData()) < 0) {
            currentPtr = currentPtr->getLeft();
        } else {
            currentPtr = currentPtr->getRight();
        }
    }
    if((*comparator)(node->getData(), parentPtr->getData()) < 0) {
        parentPtr->setLeft(node);
        node->setParent(parentPtr);
    } else { 
        parentPtr->setRight(node);
        node->setParent(parentPtr);
    }
}

template <typename T, typename C>
BSNode<T> * BSTree<T,C>::findNode(T* value) {
   
    BSNode<T>* current = this->getRoot();
 
    while(true) {

        if(current == nullptr) return nullptr;
        int compare = (*comparator)(value, current->getData());// comparator returns -1 if x<y, 0 if x=y, and 1 if x>y

        if(compare == 0) return current; // We found it, return

        if(compare < 0) { //if the value is smaller, go left

            current = current->getLeft();

	} else { //otherwise go right

            current = current->getRight();

        }
    }

}

/*
 *    Iterative inorder traversal.
 *    Executes a function that takes type T and has no return for each node
 ******/
template <typename T, typename C>
void BSTree<T,C>::traverseInorder(void (*function)(BSNode<T>*)) {
    
    BSNode<T> *currentPtr = this->getRoot();
    std::stack<BSNode<T>*> nodeStack;

    while(currentPtr != nullptr || !nodeStack.empty()) {
        while(currentPtr != nullptr) {
            nodeStack.push(currentPtr);
            currentPtr = currentPtr->getLeft();
        }
        
        currentPtr = nodeStack.top();
        nodeStack.pop();
        
        //call the function pointer on the current node
        function(currentPtr); 

        currentPtr = currentPtr->getRight();
    }
}

template <typename T, typename C>
void BSTree<T,C>::traversePreorder(void (*function)(BSNode<T>*)) {

    BSNode<T>* currentPtr = this->getRoot();
    std::stack<BSNode<T>*> nodeStack;
    nodeStack.push(currentPtr);

    while(!nodeStack.empty()) {
        currentPtr = nodeStack.top();
        nodeStack.pop();
        function(currentPtr);
        if(currentPtr->getRight() != nullptr) nodeStack.push(currentPtr->getRight());
        if(currentPtr->getLeft() != nullptr) nodeStack.push(currentPtr->getLeft());
    }
}

template <typename T, typename C>
void BSTree<T,C>::traversePostorder(void (*function)(BSNode<T>*)) {
    
    BSNode<T>* currentPtr = this->getRoot();
    std::stack<BSNode<T>*> nodeStack;
    
    while(true) {
        while(currentPtr) {
            nodeStack.push(currentPtr);
            nodeStack.push(currentPtr);
            currentPtr = currentPtr->getLeft();
        }
        
        if(nodeStack.empty()) return;
        currentPtr = nodeStack.top();
        nodeStack.pop();
        
        if(!nodeStack.empty() && nodeStack.top() == currentPtr) currentPtr = currentPtr->getRight();
        else {
            function(currentPtr);
            currentPtr = nullptr;
        }
    }

}


// Find the node with min value
// Traverse the Tree 
// until left branch is nullptr to get min
template <typename T, typename C>
BSNode<T> * BSTree<T,C>::getMin() {

	BSNode<T>* currentPtr = this->getRoot();
	if( currentPtr == nullptr) return nullptr;

	/* loop down to find the leftmost leaf */
	while (currentPtr->getLeft()) currentPtr = currentPtr->getLeft();

	return currentPtr;
}

// Find the node with max value
// Traverse the right Tree until
// right Tree is nullptr to get max
template <typename T, typename C>
BSNode<T>* BSTree<T,C>::getMax() {

	BSNode<T>* currentPtr = this->getRoot();
	if (currentPtr == nullptr) return nullptr;
       
        /* loop down to the rightmost leaf */ 
        while(currentPtr->getRight()) currentPtr = currentPtr->getRight();
        
        return currentPtr;
}

template <typename T, typename C>
void BSTree<T,C>::deleteNode(BSNode<T>* node) {
    BSNode<T>* tmp = this->removeNode(node); // remove references to node and replace vacancy
    delete tmp; //delete it

}

/*
 * Based off www.anuttaralearning.com/vle/mod/page/view.php?id=295
 * returns nullptr if failure has occurred - need to check the return value
 * otherwise returns the removed node.
 */
template <typename T, typename C>
BSNode<T>* BSTree<T,C>::removeNode(BSNode<T>* node) {
    BSNode<T>* parentPtr = node->getParent();
    BSNode<T>* childPtr = nullptr;
    if(node == nullptr) return node;

    if(node->getLeft() == nullptr && node->getRight() == nullptr) { // Node has no children
        if(parentPtr == nullptr) { //We are at the root
            if(node == this->getRoot()) { //We've confirmed that the root is equal to the node
                
                this->root = nullptr; //remove root
                 
                return node; //return node
            }
            else {
                return nullptr; //Something is odd with the state -> we have a null parent, but node is not equal to root
            }
        } else {
            if(parentPtr->getLeft() == node) { // the node is the left child of the parent
                parentPtr->setLeft(nullptr);
                node->setParent(nullptr);
                return node;
            } else if(parentPtr->getRight() == node) { // the node is the right child of the parent
                parentPtr->setRight(nullptr);
                node->setParent(nullptr);
                return node;
            } else {
                std::cout << "we are in a bad state"<< std::endl;
                return nullptr; //Parent doesn't point to the child object, we're in a bad state.
            }
        }
    } else if(node->getLeft() == nullptr || node->getRight() == nullptr) { //Has a single child
        std::cout <<"node has single child" << std::endl;
        if(node->getLeft() != nullptr) { // has a left child
            childPtr = node->getLeft();
        } else { // has a right child
            childPtr = node->getRight();
        }

        if(parentPtr == nullptr) { // We're at the root
            if(parentPtr == this->getRoot()) { // if root is equal to this node
                 this->root = childPtr;
                 this->root->setParent(nullptr);
                 node->setLeft(nullptr);
                 node->setRight(nullptr);
                 node->setParent(nullptr);
                 return node;
            } else {
                return nullptr; //Another odd state
            }
        } else {
            if(parentPtr->getLeft() == node) {
                parentPtr->setLeft(childPtr); //replace parents left child with nodes child
                childPtr->setParent(parentPtr); //set child's parent to grand parent?
                node->setLeft(nullptr);
                node->setRight(nullptr);
                node->setParent(nullptr);
            } else if(parentPtr->getRight() == node) {
                parentPtr->setRight(childPtr); //replace parents right child with nodes child
                childPtr->setParent(parentPtr); // set child's parent to grand parent
                node->setLeft(nullptr);
                node->setRight(nullptr);
                node->setParent(nullptr);
            } else {
                return nullptr; //Parent doesn't point to child object, we're in a bad state
            }
            return node;
        }
    } else { //Node is not a leaf and not the root
        std::cout << "Node is not root or leaf" << std::endl;
        BSNode<T>* parentReplacementPtr = node;
        BSNode<T>* replacementPtr = node->getLeft();
        bool isLeft = true;
        while(replacementPtr->getRight()) {
            parentReplacementPtr = replacementPtr;
            replacementPtr = replacementPtr->getRight();
            isLeft = false;
        }
        
        node->setData(replacementPtr->getData()); // replace data at the current node with data from the replacement node

        if(isLeft) {
            if(replacementPtr->getRight() == nullptr) {
                
                node->setLeft(replacementPtr->getLeft()); // set the node passed in to have a new child, the replacement pointers left child
                replacementPtr->getLeft()->setParent(node); // set the child to have the node as its parent
                parentReplacementPtr->setLeft(nullptr);
                replacementPtr->setParent(nullptr);
                replacementPtr->setLeft(nullptr);
                replacementPtr->setRight(nullptr);
   
                return replacementPtr; //replacement ptr is to be removed
            } else {
                return nullptr; // a bad state
            }
        } else {
            parentReplacementPtr->setRight(replacementPtr->getLeft()); //replacement is right grand child of the left child
            parentReplacementPtr->getRight()->setParent(parentReplacementPtr);
            replacementPtr->setParent(nullptr);
            replacementPtr->setLeft(nullptr);
            replacementPtr->setRight(nullptr);
            return replacementPtr;
        }
    }
}

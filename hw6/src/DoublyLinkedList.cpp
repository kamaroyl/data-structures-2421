#include "DoublyLinkedList.hpp"
//Default Constructor Node
Node::Node(): data(DictEntry()), nextPtr(nullptr), prevPtr(nullptr) {} 

//Default Constructor
DoublyLinkedList::DoublyLinkedList(): length(0), headPtr(nullptr), tailPtr(nullptr), currentPtr(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node *tmpPtr;
    //While the linked list isn't empty
    while(nullptr != this->headPtr) {
        // a temp storeage location is the head pointer
        tmpPtr = this->headPtr;
        // head pointer is the next pointer
        this->headPtr = this->headPtr->nextPtr;
        // remove the previous head
        delete tmpPtr;
    }
    tmpPtr = this->headPtr;
    this->headPtr = nullptr;
    delete tmpPtr;
}

/*
 * Insert a node at the front
 */
bool DoublyLinkedList::insertAtFront(DictEntry value) {
    if(nullptr == this->headPtr) {
        this->headPtr = new Node();
        this->headPtr->data = value;
        this->tailPtr = this->headPtr;
        return true;
    }    

    //store off head
    Node *tmpPtr = this->headPtr;
    //make head a new node
    this->headPtr = new Node();
    //assign previous head to next pointer of head
    this->headPtr->nextPtr = tmpPtr;
    this->headPtr->data = value;
    tmpPtr->prevPtr = this->headPtr;
    if(this->tailPtr == nullptr) this->tailPtr = this->headPtr;
    this->length++;
    return true;
}

/*
 * Insert an element at position index - 1
 * index must be greater than 0
 * If list is empty create a new headPtr
 *
 * Index = 6
 * front   1 2 3 4 5 x 6 7 8 9 10
 *         1 2 3 4 5 6 7 8 9 10
 * back              x 0 1 2 3
 */
bool DoublyLinkedList::insertAtPosition(DictEntry value, int index) {
    if(index > 0 || index <= this->length) {

        //empty list create a new node
        if(this->headPtr == nullptr) { 
            this->headPtr = new Node();
            this->headPtr->data = value;
            this->tailPtr = this->headPtr;
            return true;
        }
        
        if(this->length == index) {
            return insertAtBack(value);
        }
        if(index == 1) {
            return insertAtFront(value);
        }       


        if(index < (this->length/2)) {

            Node *tmpPtr = this->headPtr;
            index--; 
            //interate through list
            while(--index) {
                tmpPtr = tmpPtr->nextPtr;
            }

            Node *addPtr = new Node();
            addPtr->data = value;
            addPtr->nextPtr = tmpPtr->nextPtr;
            tmpPtr->nextPtr->prevPtr = addPtr;
            tmpPtr->nextPtr = addPtr;
            addPtr->prevPtr = tmpPtr;
        } else {

            index = (this->length + 2 - index);
            Node *tmpPtr = this->tailPtr;

            while(--index) {
                tmpPtr = tmpPtr->prevPtr;
            }
            
            Node *addPtr = new Node();
            addPtr->data = value;
            addPtr->nextPtr = tmpPtr;
            tmpPtr->prevPtr->nextPtr = addPtr;
            tmpPtr->prevPtr = addPtr;
            addPtr->prevPtr = tmpPtr->prevPtr;
            
        }
        this->length++;
        return true;
    }
    return false;
}


/*
 * Iterate through the list and when the nextPtr of the current element is null,
 * add node as next pointer
 */
bool DoublyLinkedList::insertAtBack(DictEntry value) {
    Node *newNode = new Node();
    newNode->data = value;

    //Empty linked list, create a new node
    if(this->headPtr == nullptr) {
        this->headPtr = newNode;
        this->tailPtr = newNode;
        return true;
    }
    

    Node *tmpPtr = this->tailPtr;
    tmpPtr->nextPtr = newNode;
    this->tailPtr = newNode;
    this->tailPtr->prevPtr = tmpPtr;
    this->length++;
    return true;
}

/*
 * Delete the first element in the linked list
 * if list is empty, return false
 */
bool DoublyLinkedList::deleteAtFront() {
    if(nullptr == this->headPtr) return false;

    // copy off head pointer
    Node *tmpPtr = this->headPtr;

    // set head pointer to next pointer
    this->headPtr = this->headPtr->nextPtr;
    this->headPtr->prevPtr = nullptr;
    delete tmpPtr;
    this->length--;
    return true;
}


/*
 * Delete at position of linked list. 
 * If linked list is shorter than index return false
 */
bool DoublyLinkedList::deleteAtPosition(int index) {
    
    //if outside bounds exit
    if(index <= 0 || index > this->length) return false;
    
    //if index is front element
    if(index == 1) {
        return this->deleteAtFront();
    }
    
    //if index is last element
    if(index == this->length) {
        return this->deleteAtBack();
    }

    //if the element is closer to the front than the back
    if( index < (this->length/2) ) {
    
        //navigate through the linked list
        Node *beforePtr = this->headPtr;
        index--;
        
        //navigate to the element before the elment to be removed
        while(--index) {
            //move to next element
            beforePtr = beforePtr->nextPtr;
        }
        //save off node to be deleted
        Node *tmpPtr = beforePtr->nextPtr;
            
        //link next node to previous node
        beforePtr->nextPtr = beforePtr->nextPtr->nextPtr;
        beforePtr->nextPtr->prevPtr = beforePtr;
              
        //clean up orphaned node and return
        delete tmpPtr;
        this->length--;
        return true;

       
    } else {
        index = (this->length + 1 - index);
        Node *afterPtr = this->tailPtr;
        while(--index) {
            afterPtr = afterPtr->prevPtr;
        }
        Node *tmpPtr = afterPtr->prevPtr;
        afterPtr->prevPtr = afterPtr->prevPtr->prevPtr;
        afterPtr->prevPtr->nextPtr = afterPtr;
        
        delete tmpPtr;
        this->length--;
        return true;
    }
    return false;
}

/*
 * Remove the last element of the linked list
 * if list is empty, return false
 */
bool DoublyLinkedList::deleteAtBack() {
    if(nullptr == this->headPtr) return false;

    if(nullptr == this->headPtr->nextPtr) {
        Node *tmpPtr = this->headPtr;
        this->headPtr = nullptr;
        this->tailPtr = nullptr;
        delete tmpPtr;
        return true;
    }
    
    Node *tmpPtr = this->tailPtr;
    this->tailPtr = tmpPtr->prevPtr;
    this->tailPtr->nextPtr = nullptr;
    delete tmpPtr;
    return true;
}

/*
 * Remove all elements from linked list
 */
void DoublyLinkedList::clear() {
    Node *tmp;
    if(nullptr == this->headPtr) return;
    // while we aren't at the end of the list
    while(nullptr != this->headPtr) {
        tmp = this->headPtr;
        this->headPtr = this->headPtr->nextPtr;
        delete tmp;
    }
}

int DoublyLinkedList::getLength() {
    return this->length;
}


Node * DoublyLinkedList::getElementAtIndex(int index) {
    //if the element is closer to the front than the back
    if( index < (this->length/2) ) {
    
        //navigate through the linked list
        Node *beforePtr = this->headPtr;
        
        //navigate to the element before the elment to be removed
        while(--index) {
            //move to next element
            beforePtr = beforePtr->nextPtr;
        }
        
        return beforePtr;
       
    }

    index = (this->length + 2 - index);
    Node *afterPtr = this->tailPtr;
    while(--index) {
        afterPtr = afterPtr->prevPtr;
    }
    return afterPtr;    
}

void DoublyLinkedList::swap(int a, int b){
    Node *aPtr = getElementAtIndex(a);
    Node *bPtr = getElementAtIndex(b);
    DictEntry de = aPtr->data;
    aPtr->data = bPtr->data;
    bPtr->data = de;
}

void DoublyLinkedList::swap(DictEntry *a, DictEntry *b) {
    DictEntry tmp = *a;
    *a = *b;
    *b = tmp;
}

Node * DoublyLinkedList::partition(Node *low, Node *high) {
    std::cout << "low: " << low->data.getWord() << " high: " << high->data.getWord() << std::endl;
    std::string pivot = high->data.getWord();
    Node *i = low;
 
    for(Node *j = low; j != high; j = j->nextPtr) {
        if(j->data.getWord() <= pivot) {
            if(i == nullptr){ std::cout << "i is uninitialized" << std::endl; i = low; }
            else{ i = i->nextPtr; std::cout << i->data.getWord() <<std::endl;}
            swap(&(i->data), &(j->data));
        }
    }
    if(nullptr == i){ i = low;}
    else{ i = i->nextPtr;}
    swap(&(i->data), &(high->data));
    return i;
}

DictEntry  DoublyLinkedList::current() {
    if( this->currentPtr == nullptr) this->begin();
    return this->currentPtr->data;
}

void DoublyLinkedList::begin() {
    this->currentPtr = this->headPtr;
}

void DoublyLinkedList::end() {
    this->currentPtr = this->tailPtr;
}

bool DoublyLinkedList::next() {
    if( this->currentPtr->nextPtr == nullptr ) return false;
    this->currentPtr = this->currentPtr->nextPtr;
    return true;
}

bool DoublyLinkedList::prev() {
    if( nullptr == this->currentPtr->prevPtr ) return false; 
    this->currentPtr = this->currentPtr->prevPtr;
    return true;
}

void DoublyLinkedList::quickSort(Node *low, Node *high) {
    if( high != nullptr && low != high && low != high->nextPtr ) {
        Node *p = partition(low, high);
        quickSort(low, p->prevPtr);
        quickSort(p->nextPtr, high);
    }
}

void DoublyLinkedList::sort() {
    quickSort(this->headPtr, this->tailPtr);
}
 
/*
 *       prints DoublyLinkedList: [{element}...{element}]
 */
std::ostream& operator<<(std::ostream &out, DoublyLinkedList &list) {
    out << "DoublyLinkedList: [" << std::endl;
    Node *tmpPtr = list.headPtr;
    while(nullptr != tmpPtr) {
        out << "    { word: " << tmpPtr->data.getWord() << ", def: " << tmpPtr->data.getDef() << " }" << std::endl;
        tmpPtr = tmpPtr->nextPtr;
    }
    out << "]";
    return out;
}

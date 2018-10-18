#include <iostream>
#include <string>
#include "../src/DoublyLinkedList.hpp"

void print(std::string func){
    std::string banner = "===========================";
    std::cout << banner << func << banner << std::endl;
}


void testConstruction() {
    print("testConstruction");
    DoublyLinkedList dll;
    std::cout << dll << std::endl;
}

void testAddFront() {
    print("testAddFront");
    DoublyLinkedList dll;
    DictEntry de;
    for( int i = 0; i < 20; i++ ) {
        de.setWord(std::to_string(i));
        de.setDef(std::to_string(i));
        dll.insertAtFront(de);
    }
    std::cout << dll << std::endl;
}

void testAddBack() {
    print("testAddBack");
    DoublyLinkedList dll;
    DictEntry de;
    for( int i = 1; i < 21; i++ ) {
        de.setWord(std::to_string(i));
        de.setDef(std::to_string(i));
        dll.insertAtBack(de);
    }
    std::cout << dll << std::endl;
}

void testAddPosition() {
    print("testAddPosition");
    DoublyLinkedList dll;
    DictEntry de;
    for( int i = 1; i < 21; i++ ) {
        de.setWord(std::to_string(i));
        de.setDef(std::to_string(i));
        dll.insertAtBack(de);
    } 
    std::cout << dll << std::endl;
    de.setWord("At18");
    de.setDef("At18");
    dll.insertAtPosition(de,18);
    std::cout << dll << std::endl;
    de.setWord("At2");
    de.setDef("At2");
    dll.insertAtPosition(de,2);
    std::cout << dll << std::endl;
    dll.deleteAtFront();
    std::cout << dll << std::endl;
    dll.deleteAtFront();
    std::cout << dll << std::endl;
    dll.deleteAtBack();
    std::cout << dll << std::endl;
    dll.deleteAtBack();
    std::cout << dll << std::endl;
    dll.deleteAtPosition(5);
    std::cout << dll << std::endl;
}

void testDeleteAtPositionBack() {
    print("testAddPosition");
    DoublyLinkedList dll;
    DictEntry de;
    for( int i = 1; i < 21; i++ ) {
        de.setWord(std::to_string(i));
        de.setDef(std::to_string(i));
        dll.insertAtBack(de);
    } 
    dll.deleteAtPosition(15);
    std::cout <<dll << std::endl;
}

void testSwap() {
    DoublyLinkedList dll;
    DictEntry de;
    for( int i = 1; i < 21; i++ ) {
        de.setWord(std::to_string(i));
        de.setDef(std::to_string(i));
        dll.insertAtBack(de);
    } 
    dll.swap(8, 12);
    std::cout <<dll << std::endl;
}

void testSort() {
    DoublyLinkedList dll;
    DictEntry de;
    de.setWord("Zebra");
    //de.setDef("na");
    dll.insertAtBack(de); 
    de.setWord("Delicious");
    dll.insertAtBack(de);
    de.setWord("Absolutely");
    dll.insertAtBack(de);
    de.setWord("Dynamite");
    dll.insertAtBack(de);
    de.setWord("Heliotrophe");
    dll.insertAtBack(de); 
    std::cout << dll << std::endl;
    dll.sort();
    std::cout <<dll << std::endl;

}

void testIterator() {
    DoublyLinkedList dll;
    DictEntry de;
    de.setWord("Zebra");
    de.setDef("na");
    dll.insertAtBack(de); 
    de.setWord("Delicious");
    dll.insertAtBack(de);
    de.setWord("Absolutely");
    dll.insertAtBack(de);
    de.setWord("Dynamite");
    dll.insertAtBack(de);
    de.setWord("Heliotrophe");
    dll.insertAtBack(de);
    dll.begin();
    int count = 0;

    while(true) {
        DictEntry de2 = dll.current(); 
        std::cout << count << " " << de2.getWord() << std::endl;
        if(!dll.next())break;
        count++;
    }
    dll.end();

    while(true) {
        std::cout <<"Hello " << count << std::endl;
        DictEntry de2 = dll.current();
        std::cout << count << " " << de2.getWord() << std::endl;
        if(!dll.prev())break;
        count--;
    }
}

int main() {
    testConstruction();
    testAddFront();
    testAddBack();
    testAddPosition();
    testDeleteAtPositionBack();
    testSwap();
    testSort();
    testIterator();
    return 0;
}

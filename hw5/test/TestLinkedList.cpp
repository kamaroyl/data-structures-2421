#include "../src/LinkedList.h"
#include <string>

string b2s(bool value) {
    if(value) return "true";
    return "false";
}

string decorate(string functionName) {
    return "=======" + functionName + "=======";
}

void testConstructor() {
    std::cout << decorate("testConstructor") << std::endl;
    LinkedList linkedList;
    std::cout << linkedList;
    std::cout << std::endl;
    linkedList.clear();
    std::cout << "clear: " << linkedList << std::endl;
    std::cout << std::endl;
}

void testAddFrontElement() {
    std::cout << decorate("testAddElement") << std::endl;
    LinkedList linkedList;
    linkedList.insertAtFront(68);
    linkedList.insertAtFront(67);
    linkedList.insertAtFront(66);
    linkedList.insertAtFront(65);
    std::cout << linkedList;
    std::cout << std::endl;
    std::cout << std::endl;
    linkedList.clear();
    std::cout << linkedList << std::endl;
    std::cout << std::endl;

}

void testAddFrontElementLoop() {
    std::cout << decorate("testAddFrontElementLoop") << std::endl;
    LinkedList linkedList;
    for(int i = 0; i < 26; i++) {
        linkedList.insertAtFront(90 - i);
    }
    std::cout << linkedList << std::endl;
    linkedList.clear();
    std::cout << "clear: " << linkedList << std::endl;
    std::cout << std::endl;
}

void testAddBackElement() {
    std::cout << decorate("testAddBackElement") << std::endl;
    LinkedList linkedList;
    //[A]
    linkedList.insertAtBack(65);
    //[AB]
    linkedList.insertAtBack(66);
    //[ABC]
    linkedList.insertAtBack(67);
    //[ABCD]
    linkedList.insertAtBack(68);
    //[ABCDE]
    linkedList.insertAtBack(69);
    for(int i = 0; i < 21; i++) {
        linkedList.insertAtBack(70 + i);
    }
    std::cout << linkedList;
    linkedList.clear();
    std::cout << std::endl;
    std::cout << "after clear: " << linkedList << std::endl;
    std::cout << std::endl;
}

void testAddAtIndex() {
    std::cout << decorate("testAddAtIndexEmpty") << std::endl;
    LinkedList linkedList;
    //[C]
    linkedList.insertBeforePosition(67, 1);
    std::cout << linkedList << std::endl;
    //[CB]
    linkedList.insertBeforePosition(66, 1);
    std::cout << linkedList << std::endl;
    //[CAB]
    linkedList.insertBeforePosition(65, 1);
    std::cout << linkedList << std::endl;
    //[CAKB]
    linkedList.insertBeforePosition(75,2);
    std::cout << linkedList;
    linkedList.clear();
    std::cout <<linkedList;
    std::cout << std::endl;
    std::cout << std::endl;
}

void testDeleteAtBack() {
    std::cout << decorate("testDeleteAtBack") << std::endl;
    LinkedList linkedList;
    linkedList.insertAtBack(88);
    linkedList.insertAtBack(89);
    linkedList.insertAtBack(90);
    std::cout << linkedList << std::endl;
    linkedList.deleteAtBack();
    std::cout << linkedList << std::endl;
    linkedList.clear();
    std::cout << std::endl;
    std::cout << "after clear: " << linkedList << std::endl;
    std::cout << std::endl;
}

void testDeleteAtFront() {
    std::cout << decorate("testDeleteAtFront") << std::endl;
    LinkedList linkedList;
    linkedList.insertAtFront(56);
    linkedList.insertAtBack(97);
    linkedList.insertAtFront(76);
    std::cout << linkedList << std::endl;
    linkedList.deleteAtFront();
    std::cout << linkedList << std::endl;
    std::cout << std::endl;
    linkedList.clear();
    std::cout << std::endl;
    std::cout << "after clear: " << linkedList << std::endl;
}

void testDeleteAtPosition() {
    bool result = false;
    std::cout << decorate("testDeleteAtPosition") << std::endl;
    LinkedList linkedList;
    result = linkedList.deletePosition(0);
    cout << "delete at 0 when empty: " << b2s(result) << std::endl;  
    result = linkedList.deletePosition(1);
    cout << "delete at 1 when empty: " << b2s(result) << std::endl;
    linkedList.insertAtFront(69);
    linkedList.insertAtBack(87);
    linkedList.insertAtFront(76);
    std::cout << linkedList << std::endl;
    linkedList.deletePosition(1);
    std::cout << linkedList << std::endl;
    linkedList.deletePosition(1);
    std::cout << linkedList << std::endl;
    linkedList.clear();
    std::cout << std::endl;
    std::cout << "after clear: " << linkedList << std::endl;
}

void testClear() {
    LinkedList linkedList;
    for(int i =0; i < 26; i++) {
        linkedList.insertAtBack(65 + i);
    }
    std::cout << linkedList << std::endl;

}
int main() {
    testConstructor();    
    testAddFrontElement();
    testAddFrontElementLoop();
    testAddBackElement();
    testAddAtIndex();
    testDeleteAtBack();
    testDeleteAtFront();
    testDeleteAtPosition();
    testClear();
    return 0;
}

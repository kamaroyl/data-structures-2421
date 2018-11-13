#include <iostream>
#include <string>
#include "../lib/BSTree.hpp"
class TestClass {
    private:
        std::string stringValue;
        int intValue;
    public:
        int getInt(){ return intValue; }
        std::string getString(){ return stringValue; }
        void setInt(int value){ this->intValue = value; }
        void setString(std::string value){ this->stringValue = value; }
        friend std::ostream& operator<<(std::ostream& os, TestClass& tc) {
            return os << "string value: " << tc.getString() << " int value: " << tc.getInt() <<std::endl;
        }
};

class TcStringComparator {
    public:
       int operator()(TestClass* tc1, TestClass* tc2) {
            if(tc1->getString() < tc2->getString()) return -1;
            else if(tc1->getString() > tc2->getString()) return 1;
            else return 0;
        }
};

void printHeader(std::string title) {
    std::cout << "======" << title << "======" << std::endl;
}

void constructorTestNull() {
    printHeader("constructorTestNull");
    TcStringComparator* tcC = new TcStringComparator();
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
}


void constructorTestTwo() {
    printHeader("constructorTestTwo");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("Hello");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("World!");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
}

void constructorTestFull() {
    printHeader("constructorTestFull");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("Hello");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("World!");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(0); 
    tcPointer3->setString("Again!");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
}

void preorderTest() {
    printHeader("preorderTest");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("Hello");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("World!");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(0); 
    tcPointer3->setString("Again!");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
    tcTree.traversePreorder(printNode);
} 

void inorderTest() {
    printHeader("inorderTest");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("Hello");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("World!");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(0); 
    tcPointer3->setString("Again!");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
    tcTree.traverseInorder(printNode);
   
}

void postorderTest() {
    printHeader("postorderTest");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("Hello");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("World!");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(0); 
    tcPointer3->setString("Again!");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
    tcTree.traversePostorder(printNode);
}

void testMax() {
    printHeader("testMax");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("A");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("B");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(3); 
    tcPointer3->setString("C");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
    BSNode<TestClass>* maxNode = tcTree.getMax();
    printNode(maxNode);
}

void testMin() {
    printHeader("testMin");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("C");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("B");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(3); 
    tcPointer3->setString("A");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
    BSNode<TestClass>* minNode = tcTree.getMin();
    printNode(minNode);
}

void findTest() {
    printHeader("findTest");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("Hello");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("World!");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(0); 
    tcPointer3->setString("Again!");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
    TestClass* searchData = new TestClass();
    searchData->setInt(99); 
    searchData->setString("World!");
    BSNode<TestClass>* resultNode = tcTree.findNode(searchData);
    printNode(resultNode);
    delete searchData;
}

void deleteTest() {
    printHeader("deleteTest");
    BSNode<TestClass>* tcNode1 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode2 = new BSNode<TestClass>();
    BSNode<TestClass>* tcNode3 = new BSNode<TestClass>();
    TcStringComparator* tcC = new TcStringComparator();
    TestClass* tcPointer1 = new TestClass();
    tcPointer1->setInt(1);
    tcPointer1->setString("Hello");
    TestClass* tcPointer2 = new TestClass();
    tcPointer2->setInt(2);
    tcPointer2->setString("World!");
    TestClass* tcPointer3 = new TestClass();
    tcPointer3->setInt(0); 
    tcPointer3->setString("Again!");
    tcNode1->setData(tcPointer1);
    tcNode2->setData(tcPointer2);
    tcNode3->setData(tcPointer3);
    BSTree<TestClass,TcStringComparator> tcTree(tcC);
    tcTree.addNode(tcNode1);
    tcTree.addNode(tcNode2);
    tcTree.addNode(tcNode3);
    TestClass* searchData = new TestClass();
    searchData->setInt(99); 
    searchData->setString("World!");
    BSNode<TestClass>* resultNode = tcTree.findNode(searchData);
    delete searchData;
    tcTree.deleteNode(resultNode); 
    tcTree.traversePostorder(printNode);

}

int main() {
    constructorTestNull();
    constructorTestTwo();
    constructorTestFull();
    preorderTest();
    inorderTest();
    postorderTest();
    findTest();
    testMax();
    testMin();
    deleteTest();
}

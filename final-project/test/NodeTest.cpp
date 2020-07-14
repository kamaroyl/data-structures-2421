#include "../lib/BSNode.hpp"
#include <iostream>
class testNode {
    private:
        int val;
    
    public:
        testNode(int val){ this->val = val; }
        int getVal() { return this->val; }
        void setVal(int val) { this->val = val; }
        friend std::ostream& operator<<(std::ostream& os, const testNode& test) { 
            os << "val: " << test.val << std::endl;
            return os;
        }
};

void testConstructNode(){
    BSNode<testNode>* aNode = new BSNode<testNode>();
    testNode* test = new testNode(12);
    aNode->setData(test);
    printNode(aNode);
}

void copyConstructionTest() {
    BSNode<testNode>* aNode = new BSNode<testNode>();
    testNode* test = new testNode(12);
    aNode->setData(test);
    BSNode<testNode>* bNode = new BSNode<testNode>(aNode->getData());
    printNode(bNode);
}

int main() {
    testConstructNode();
    copyConstructionTest();
}

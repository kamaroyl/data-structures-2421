#include "../src/Data/Comparators/ActorComparator.hpp"
#include "../src/Data/Actor.hpp"
#include <iostream>
#include <string>

std::string humanReadableResult(char value) {
    if(value < 0) return "less than";
    if(value > 0) return "greater than";
    return "equal to";

}


void TestActorComparatorConstructor() {
    ActorComparator ac;
}

void ActorComparatorNoFields() {
    Actor* one = new Actor(1, "1111", "A", "1", "AAAA", "AAAA");
    Actor* two = new Actor(2, "2222", "B", "2", "BBBB", "BBBB");

    ActorComparator ac;
    char result = ac(one, two);
    std::cout <<"One is: " << humanReadableResult(result) << " Two" << std::endl;

}

void ActorComparatorOneField() {
    Actor* one = new Actor(1, "1111", "A", "1", "AAAA", "AAAA");
    Actor* two = new Actor(2, "2222", "B", "2", "BBBB", "BBBB");
    ActorComparator ac; 
    ac.setYear(10);
    char result = ac(one, two);
    std::cout <<"One is: " << humanReadableResult(result) << " Two " << std::endl;

}

void ActorComparatorTwoFields() {
    Actor* one = new Actor(1, "1111", "A", "1", "AAAA", "AAAA");
    Actor* two = new Actor(2, "1111", "B", "2", "BBBB", "BBBB");

    ActorComparator ac;
    ac.setYear(10);
    ac.setAward(2);
    char result = ac(one, two);
    std::cout << "One is " << humanReadableResult(result) << " two" <<std::endl;
}

int main() {
    TestActorComparatorConstructor();
    ActorComparatorNoFields();
    ActorComparatorOneField();
    ActorComparatorTwoFields();
    return 0;
}

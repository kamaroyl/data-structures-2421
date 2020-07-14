#include "../src/Data/Comparators/PictureComparator.hpp"
#include "../src/Data/Picture.hpp"
#include <iostream>
#include <string>

std::string humanReadableResult(char value) {
    if(value < 0) return "less than";
    if(value > 0) return "greater than";
    return "equal to";
}

void testPictureComparatorConstructor() {
    std::cout << "testPictureComparatorConstructor()" << std::endl;
    PictureComparator pc;
}

void testPictureCompareNoFields() {
    std::cout << "testPictureCompareNoFields()" << std::endl;
    Picture *one = new Picture(1, "one", "1111", "1", "11.11", "111", "Adventure", "Action", "January", "11", "AAAAAAAA");
    Picture *two = new Picture(2, "two", "2222", "2", "22.22", "222", "Biography", "Comedy", "February", "22", "BBBBBBBBB");
    PictureComparator pc;
    char result = pc(one, two);
    std::cout << "One is: " << humanReadableResult(result) << " Two" << std::endl;
}

void testPictureCompareOneField() {
    std::cout << "testPictureCompareOneField()" << std::endl;
    Picture *one = new Picture(1, "one", "1111", "1", "11.11", "111", "adventure", "action", "january", "11", "aaaaaaaa");
    Picture *two = new Picture(2, "two", "2222", "2", "22.22", "222", "biography", "comedy", "february", "22", "bbbbbbbbb");
    PictureComparator pc;
    pc.setYear(1);
    char result = pc(one, two);
    std::cout << "One is: " << humanReadableResult(result) << " Two" << std::endl;
}

void testPictureCompareOneFieldReverse() {
    std::cout << "testPictureCompareOneFieldReverse()" << std::endl;
    Picture *one = new Picture(1, "one", "1111", "1", "11.11", "111", "adventure", "action", "january", "11", "aaaaaaaa");
    Picture *two = new Picture(2, "two", "2222", "2", "22.22", "222", "biography", "comedy", "february", "22", "bbbbbbbbb");
    PictureComparator pc;
    pc.setYear(-1);
    char result = pc(one, two);
    std::cout << "One is: " << humanReadableResult(result) << " Two" << std::endl;
}

void testPictureCompareTwoFields() {
    std::cout << "testPictureCompareTwoFields()" << std::endl;
    Picture *one = new Picture(1, "one", "1111", "1", "11.11", "111", "adventure", "action", "january", "11", "aaaaaaaa");
    Picture *two = new Picture(2, "two", "1111", "2", "22.22", "222", "biography", "comedy", "february", "22", "bbbbbbbbb");
    PictureComparator pc;
    pc.setYear(10);
    char result = pc(one, two);
    std::cout << "One is: " << humanReadableResult(result) << " Two" << std::endl;
    pc.setMetacritic(5);
    result = pc(one, two);
    std::cout << "One is: " << humanReadableResult(result) << " Two" << std::endl;
}

int main() {
    testPictureComparatorConstructor();
    testPictureCompareNoFields();
    testPictureCompareOneField();
    testPictureCompareOneFieldReverse();
    testPictureCompareTwoFields();
    return 0;
}

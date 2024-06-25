//File: ListTest2.cpp 
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include "List2.h"
#include <iostream>

void printInt(int data) {
    std::cout << data << " ";
}

int main() {
    List<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    std::cout << "List after push_back: ";
    myList.traverse(printInt);
    std::cout << std::endl;

    myList.push_front(0);
    myList.push_front(-1);
    std::cout << "List after push_front: ";
    myList.traverse(printInt); 
    std::cout << std::endl;

    std::cout << "Front element: " << myList.front() << std::endl; 
    std::cout << "Back element: " << myList.back() << std::endl;   

    myList.pop_front();
    std::cout << "List after pop_front: ";
    myList.traverse(printInt);  
    std::cout << std::endl;

    myList.pop_back();
    std::cout << "List after pop_back: ";
    myList.traverse(printInt); 
    std::cout << std::endl;

    std::cout << "Is list empty? " << (myList.empty() ? "Yes" : "No") << std::endl;

    List<int> copiedList(myList);
    std::cout << "Copied list: ";
    copiedList.traverse(printInt);  
    std::cout << std::endl;

    return 0;
}
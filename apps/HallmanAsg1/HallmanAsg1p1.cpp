//File: HallmanAsg1P1.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu
//Purpose: Demonstrates some classic pointer coding anti-patterns. 

#include <iostream>
#include <string>


void useCase1() {
    const int size = 100;
    int* array1 = new int[size];
    
   
    for (int i = 0; i < size; ++i) {
        array1[i] = i;
    }
    
    int* array2 = array1;

    
    delete[] array1;

    
    for (int i = 0; i < 10; ++i) {
        std::cout << array2[i] << " "; 
    }
    std::cout << std::endl;
}


void useCase2() {
    const int size = 100;
    int* array1 = new int[size];
    
    
    for (int i = 0; i < size; ++i) {
        array1[i] = i;
    }

    int* array2 = array1;

    delete array1; 


    std::cout << "Second Pointer Address: " << array2 << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << array2[i] << " "; 
    }
    std::cout << std::endl;
}

std::string* createString() {
    std::string* str = new std::string("abcdefghijkl");
    return str;
}


void useCase3() {
    std::string* myString = createString();
    std::cout << *myString << std::endl;
    delete myString;
}

int main() {
    std::cout << "Case 1:" << std::endl;
    useCase1();
    
    std::cout << "Case 2:" << std::endl;
    useCase2();
    
    std::cout << "Case 3:" << std::endl;
    useCase3();
    
    return 0;
}
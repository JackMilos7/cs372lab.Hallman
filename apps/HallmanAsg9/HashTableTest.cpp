//File: HashTableTest.cpp - A9P1
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <iostream>
#include "HashTable.h"

int main() {

// A small size to demonstrate collision and full table

    int size = 7;
    HashTable ht(size);

    // Insert elements

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(22);
    ht.insert(35);
    ht.insert(40);

    std::cout << "Initial table:\n";
    ht.display();

    // Test search

    std::cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";
    std::cout << "Searching for 99: " << (ht.search(99) ? "Found" : "Not Found") << "\n";

    // Test remove

    ht.remove(15);
    std::cout << "\nTable after removing 15:\n";
    ht.display();

    // Insert more elements to test full table behavior

    ht.insert(13);
    ht.insert(26);

    std::cout << "\nTable after inserting more elements:\n";
    ht.display();

    return 0;
}
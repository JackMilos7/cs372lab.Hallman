//File: HashTableTest2.cpp - A9P2
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <iostream>
#include "HashTable.h"

int main() {

// A small size to demonstrate probing

    int size = 7;          
    HashTable ht(size);

// Insert elements using linear probing (default)

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(22);
    ht.insert(35);
    ht.insert(40);

    std::cout << "Table after inserting elements using linear probing:\n";
    ht.display();

// Test quadratic probing

    HashTable htQuad(size);
    htQuad.insert(10, std::bind(&HashTable::quadraticProbe, &htQuad, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htQuad.insert(20, std::bind(&HashTable::quadraticProbe, &htQuad, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htQuad.insert(15, std::bind(&HashTable::quadraticProbe, &htQuad, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htQuad.insert(7, std::bind(&HashTable::quadraticProbe, &htQuad, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htQuad.insert(22, std::bind(&HashTable::quadraticProbe, &htQuad, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htQuad.insert(35, std::bind(&HashTable::quadraticProbe, &htQuad, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htQuad.insert(40, std::bind(&HashTable::quadraticProbe, &htQuad, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    std::cout << "\nTable after inserting elements using quadratic probing:\n";
    htQuad.display();

// Test double hashing

    HashTable htDouble(size);
    htDouble.insert(10, std::bind(&HashTable::secondHash, &htDouble, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htDouble.insert(20, std::bind(&HashTable::secondHash, &htDouble, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htDouble.insert(15, std::bind(&HashTable::secondHash, &htDouble, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htDouble.insert(7, std::bind(&HashTable::secondHash, &htDouble, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htDouble.insert(22, std::bind(&HashTable::secondHash, &htDouble, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htDouble.insert(35, std::bind(&HashTable::secondHash, &htDouble, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    htDouble.insert(40, std::bind(&HashTable::secondHash, &htDouble, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    std::cout << "\nTable after inserting elements using double hashing:\n";
    htDouble.display();

    return 0;
}

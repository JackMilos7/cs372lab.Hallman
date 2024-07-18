// File: HashTableTest3.cpp
// Author: Jackson Hallman
// Student Num: 00102945
// Email: jhallma5@my.athens.edu

#include <iostream>
#include "HashTable3.h"

// Define a simple RecordType for testing

struct RecordType {
    int key;
    int value;
};

int main() {

    // Create a Table instance

    Table<RecordType> table;

    // Insert some records

    table.insert({10, 100});
    table.insert({22, 200});
    table.insert({31, 300});
    table.insert({4, 400});
    table.insert({15, 500});

    // Test insertion and retrieval

    bool found;
    RecordType result;

    table.find(10, found, result);
    if (found) {
        std::cout << "Key: 10, Value: " << result.value << std::endl;
    } else {
        std::cout << "Key 10 not found." << std::endl;
    }

    table.find(22, found, result);
    if (found) {
        std::cout << "Key: 22, Value: " << result.value << std::endl;
    } else {
        std::cout << "Key 22 not found." << std::endl;
    }

    table.find(31, found, result);
    if (found) {
        std::cout << "Key: 31, Value: " << result.value << std::endl;
    } else {
        std::cout << "Key 31 not found." << std::endl;
    }

    table.find(4, found, result);
    if (found) {
        std::cout << "Key: 4, Value: " << result.value << std::endl;
    } else {
        std::cout << "Key 4 not found." << std::endl;
    }

    table.find(15, found, result);
    if (found) {
        std::cout << "Key: 15, Value: " << result.value << std::endl;
    } else {
        std::cout << "Key 15 not found." << std::endl;
    }

    // Test removing an item

    table.remove(22);
    table.find(22, found, result);
    if (found) {
        std::cout << "Key: 22, Value: " << result.value << std::endl;
    } else {
        std::cout << "Key 22 not found after removal." << std::endl;
    }

    // Test inserting after removing

    table.insert({22, 600});
    table.find(22, found, result);
    if (found) {
        std::cout << "Key: 22, Value: " << result.value << std::endl;
    } else {
        std::cout << "Key 22 not found after reinserting." << std::endl;
    }

    // Test table size

    std::cout << "Table size: " << table.size() << std::endl;

    return 0;
}

//File: HashTable.h - A9P1
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    std::vector<std::list<int>> table;
    int capacity;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int size) : capacity(size) {
        table.resize(size);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (const auto &element : table[index]) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; ++i) {
            std::cout << "Index " << i << ": ";
            for (const auto &element : table[i]) {
                std::cout << element << " -> ";
            }
            std::cout << "NULL\n";
        }
    }
};
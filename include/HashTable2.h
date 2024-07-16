//File: HashTable2.h - A9P2
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <iostream>
#include <vector>
#include <functional>

class HashTable {

private:
    std::vector<int> table;
    int capacity;
    int emptySlot = -1;          // Assume -1 represents an empty slot

    int hashFunction(int key) {

        return key % capacity;
    }

    void findIndex(int key, bool &found, std::size_t &index) {
        index = hashFunction(key);
        std::size_t initialIndex = index;
        while (table[index] != emptySlot && table[index] != key) {
            index = (index + 1) % capacity;
            if (index == initialIndex) {
                found = false;
                return;
            }
        }
        found = (table[index] == key);
    }

    void quadraticProbe(int key, bool &found, std::size_t &index) {
        index = hashFunction(key);
        std::size_t initialIndex = index;
        std::size_t i = 1;
        while (table[index] != emptySlot && table[index] != key) {
            index = (initialIndex + i * i) % capacity;
            if (index == initialIndex) {
                found = false;
                return;
            }
            i++;
        }
        found = (table[index] == key);
    }

    void secondHash(int key, bool &found, std::size_t &index) {
        index = hashFunction(key);
        std::size_t h2 = 7 - (key % 7);
        std::size_t initialIndex = index;
        while (table[index] != emptySlot && table[index] != key) {
            index = (index + h2) % capacity;
            if (index == initialIndex) {
                found = false;
                return;
            }
        }
        found = (table[index] == key);
    }

public:
    HashTable(int size) : capacity(size) {
        table.resize(size, emptySlot);
    }

    void insert(int key, std::function<void(int, bool &, std::size_t)> hashingFunction = std::bind(&HashTable::findIndex, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)) {
        bool found;
        std::size_t index;
        hashingFunction(key, found, index);
        if (!found) {
            table[index] = key;
        }
    }

    void remove(int key, std::function<void(int, bool &, std::size_t)> hashingFunction = std::bind(&HashTable::findIndex, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)) {
        bool found;
        std::size_t index;
        hashingFunction(key, found, index);
        if (found) {
            table[index] = emptySlot;
        }
    }

    bool search(int key, std::function<void(int, bool &, std::size_t)> hashingFunction = std::bind(&HashTable::findIndex, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)) {
        bool found;
        std::size_t index;
        hashingFunction(key, found, index);
        return found;
    }

    void display() {
        for (int i = 0; i < capacity; ++i) {
            if (table[i] == emptySlot) {
                std::cout << "Index " << i << ": NULL\n";
            } else {
                std::cout << "Index " << i << ": " << table[i] << "\n";
            }
        }
    }
};
//File: HashTable3.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <cassert>
#include <cstdlib>

template <class RecordType>
class Table {
public:

    // Make sure the size is a power of 2
    static const std::size_t CAPACITY = 1024; 
    Table();

    void insert(const RecordType &entry) {
        bool alreadyPresent;
        std::size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);
        if (!alreadyPresent) {
            assert(size() < CAPACITY);
            index = hash(entry.key);
            quadProbe(index); // Use quadratic probing to find an empty slot
            ++used;
        }
        data[index] = entry;
    }

    void remove(int key) {
        bool found;
        std::size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }

    bool isPresent(int key) const;
    void find(int key, bool &found, RecordType &result) const;
    std::size_t size() const { return used; }

private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    std::size_t used;

    std::size_t hash(int key) const { return key % CAPACITY; }

    void quadProbe(std::size_t &index) const {
        std::size_t i = 1;
        std::size_t originalIndex = index;
        while (!isVacant(index)) {
            index = (originalIndex + i * i) % CAPACITY;
            ++i;
        }
    }

    void findIndex(int key, bool &found, std::size_t &index) const {
        std::size_t count = 0;
        index = hash(key);
        while ((count < CAPACITY) && (!neverUsed(index)) && (data[index].key != key)) {
            ++count;
            quadProbe(index);
        }
        found = (data[index].key == key);
    }

    bool neverUsed(std::size_t index) const { return (data[index].key == NEVERUSED); }
    bool isVacant(std::size_t index) const { return (data[index].key == NEVERUSED || data[index].key == PREVIOUSLYUSED); }
};

// Constructor
template <class RecordType>
Table<RecordType>::Table() : used(0) {
    for (std::size_t i = 0; i < CAPACITY; ++i) {
        data[i].key = NEVERUSED;
    }
}


template <class RecordType>
bool Table<RecordType>::isPresent(int key) const {
    bool found;
    std::size_t index;
    findIndex(key, found, index);
    return found;
}

template <class RecordType>
void Table<RecordType>::find(int key, bool &found, RecordType &result) const {
    std::size_t index;
    findIndex(key, found, index);
    if (found) {
        result = data[index];
    }
}
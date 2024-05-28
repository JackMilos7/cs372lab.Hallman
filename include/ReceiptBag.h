//File: ReceiptBag.h 
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#ifndef RECEIPTBAG_H
#define RECEIPTBAG_H

#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <utility> 

template <typename T>
class ReceiptBag {
public:
    int insert(const T& item);
    T remove(int receipt);

private:
    std::vector<T> items;
    std::unordered_map<int, std::size_t> receiptToIndex;
    int nextReceipt = 0;
};

template <typename T>
int ReceiptBag<T>::insert(const T& item) {
    items.push_back(item);
    int receipt = nextReceipt++;
    receiptToIndex[receipt] = items.size() - 1;
    return receipt;
}

template <typename T>
T ReceiptBag<T>::remove(int receipt) {
    auto it = receiptToIndex.find(receipt);
    if (it == receiptToIndex.end()) {
        throw std::invalid_argument("Invalid receipt");
    }

    std::size_t index = it->second;
    T removedItem = std::move(items[index]);

    if (index != items.size() - 1) {
        items[index] = std::move(items.back());
        for (auto& pair : receiptToIndex) {
            if (pair.second == items.size() - 1) {
                pair.second = index;
                break;
            }
        }
    }
    items.pop_back();
    receiptToIndex.erase(it);

    return removedItem;
}

#endif 
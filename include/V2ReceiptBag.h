//File: V2ReceiptBag.h 
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#ifndef RECEIPTBAG_H
#define RECEIPTBAG_H

#include "List.h"
#include <unordered_map>
#include <stdexcept>

template <typename T>
class ReceiptBag {
private:
    List<T> items;
    std::unordered_map<int, typename List<T>::Node*> receipts;
    int nextReceipt;

public:
    ReceiptBag() : nextReceipt(1) {}

    int insert(T item) {
        items.push_back(item);
        receipts[nextReceipt] = items.tail;
        return nextReceipt++;
    }

    T remove(int receipt) {
        auto it = receipts.find(receipt);
        if (it == receipts.end()) {
            throw std::invalid_argument("Invalid receipt");
        }
        typename List<T>::Node* node = it->second;
        T data = node->data;
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            items.head = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            items.tail = node->prev;
        }
        delete node;
        receipts.erase(it);
        return data;
    }
};

#endif 
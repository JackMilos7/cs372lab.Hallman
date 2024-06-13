//File: SelfAdjustingList.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#ifndef SELFADJUSTINGLIST_H
#define SELFADJUSTINGLIST_H

#include "List.h"

template <typename T>
class SelfAdjustingList : public List<T> {
public:
    SelfAdjustingList() : List<T>() {}

    T* find(T itemToFind) {
        typename List<T>::Node* current = this->head;

        while (current != nullptr) {
            if (current->data == itemToFind) {
                if (current != this->head) {
                    
                    if (current->prev != nullptr) {
                        current->prev->next = current->next;
                    }
                    if (current->next != nullptr) {
                        current->next->prev = current->prev;
                    }
                    if (current == this->tail) {
                        this->tail = current->prev;
                    }

                    
                    current->next = this->head;
                    current->prev = nullptr;
                    if (this->head != nullptr) {
                        this->head->prev = current;
                    }
                    this->head = current;
                    if (this->tail == nullptr) {
                        this->tail = current;
                    }
                }

                return &(this->head->data);
            }
            current = current->next;
        }

        return nullptr; 
    }
};

#endif 
//File: CircularList.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "List.h"

template <typename T>
class CircularList : public List<T> {
public:
    CircularList() : List<T>() {}

    ~CircularList() {

        if (!this->empty()) {
            this->tail->next = nullptr;
            this->head->prev = nullptr;
        }
    }

    void push_front(T data) {
        List<T>::push_front(data);
        if (this->head == this->tail) {
            this->head->next = this->tail;
            this->tail->prev = this->head;
        } else {
            this->head->prev = this->tail;
            this->tail->next = this->head;
        }
    }

    void push_back(T data) {
        List<T>::push_back(data);
        if (this->head == this->tail) {
            this->head->next = this->tail;
            this->tail->prev = this->head;
        } else {
            this->tail->next = this->head;
            this->head->prev = this->tail;
        }
    }

    void pop_front() {
        if (this->empty()) throw std::runtime_error("List is empty");
        if (this->head == this->tail) {
            delete this->head;
            this->head = this->tail = nullptr;
        } else {
            List<T>::pop_front();
            this->head->prev = this->tail;
            this->tail->next = this->head;
        }
    }

    void pop_back() {
        if (this->empty()) throw std::runtime_error("List is empty");
        if (this->head == this->tail) {
            delete this->tail;
            this->head = this->tail = nullptr;
        } else {
            List<T>::pop_back();
            this->tail->next = this->head;
            this->head->prev = this->tail;
        }
    }

    void circle(int startPos, void (*doIt)(T data)) {
        if (this->empty()) throw std::runtime_error("List is empty");
        typename List<T>::Node* current = this->head;
        for (int i = 0; i < startPos; ++i) {
            current = current->next;
            if (current == this->head) throw std::out_of_range("Start position out of range");
        }
        typename List<T>::Node* startNode = current;
        do {
            doIt(current->data);
            current = current->next;
        } while (current != startNode);
    }
};

#endif 
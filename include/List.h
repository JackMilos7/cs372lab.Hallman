//File: List.h 
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
        Node(T data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

    void deleteListContents() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    List(T newData) {
        head = new Node(newData);
        tail = head;
    }

    List(List& rhs) {
        head = tail = nullptr;
        Node* current = rhs.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    ~List() {
        deleteListContents();
    }

    bool empty() {
        return head == nullptr;
    }

    void push_front(T data) {
        Node* newNode = new Node(data);
        if (empty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T data) {
        Node* newNode = new Node(data);
        if (empty()) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    T front() {
        if (empty()) throw std::runtime_error("List is empty");
        return head->data;
    }

    T back() {
        if (empty()) throw std::runtime_error("List is empty");
        return tail->data;
    }

    void pop_front() {
        if (empty()) throw std::runtime_error("List is empty");
        Node* oldHead = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete oldHead;
    }

    void pop_back() {
        if (empty()) throw std::runtime_error("List is empty");
        Node* oldTail = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete oldTail;
    }

    void traverse(void (*doIt)(T data)) {
        Node* current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }
};

#endif
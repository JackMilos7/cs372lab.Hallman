//File: List2.h 
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
        Node(T data) : data(data), next(nullptr), prev(nullptr) {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

    void deleteListContents() {
        head.reset();
        tail.reset();
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    List(T newData) {
        head = std::make_shared<Node>(newData);
        tail = head;
    }

    List(const List& rhs) {
        head = tail = nullptr;
        auto current = rhs.head;
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
        auto newNode = std::make_shared<Node>(data);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T data) {
        auto newNode = std::make_shared<Node>(data);
        if (empty()) {
            head = tail = newNode;
        } else {
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
        head = head->next;
        if (head) {
            head->prev.reset();
        } else {
            tail.reset();
        }
    }

    void pop_back() {
        if (empty()) throw std::runtime_error("List is empty");
        tail = tail->prev;
        if (tail) {
            tail->next.reset();
        } else {
            head.reset();
        }
    }

    void traverse(void (*doIt)(T data)) {
        auto current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }
};

#endif 
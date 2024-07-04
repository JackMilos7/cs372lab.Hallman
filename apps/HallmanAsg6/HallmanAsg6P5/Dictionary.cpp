//File: Dictionary.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {}
};


template<typename KeyType, typename ValueType>
class Dictionary {
private:
    struct Node {
        Node(Pair<KeyType, ValueType> v, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
            : value(v), left(l), right(r) {}
        Pair<KeyType, ValueType> value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> root;

    std::shared_ptr<Node> findNode(std::shared_ptr<Node> node, KeyType key) const {
        if (!node) return nullptr;
        if (key == node->value.first) return node;
        if (key < node->value.first) return findNode(node->left, key);
        return findNode(node->right, key);
    }

    std::shared_ptr<Node> insertNode(std::shared_ptr<Node> node, Pair<KeyType, ValueType> pair) {
        if (!node) return std::make_shared<Node>(pair, nullptr, nullptr);
        if (pair.first < node->value.first) {
            node->left = insertNode(node->left, pair);
        } else if (pair.first > node->value.first) {
            node->right = insertNode(node->right, pair);
        } else {
            node->value.second = pair.second;                                                      // Update if key exists
        }
        return node;
    }

    void inOrderKeys(std::shared_ptr<Node> node, std::list<KeyType>& keys) const {
        if (node) {
            inOrderKeys(node->left, keys);
            keys.push_back(node->value.first);
            inOrderKeys(node->right, keys);
        }
    }

    void inOrderValues(std::shared_ptr<Node> node, std::list<ValueType>& values) const {
        if (node) {
            inOrderValues(node->left, values);
            values.push_back(node->value.second);
            inOrderValues(node->right, values);
        }
    }


public:
    Dictionary() : root(nullptr) {}

    ValueType& get(KeyType key) {
        std::shared_ptr<Node> node = findNode(root, key);
        if (!node) {
            throw std::runtime_error("Key not found in dictionary");
        }
        return node->value.second;
    }

    void set(KeyType key, ValueType value) {
        root = insertNode(root, Pair<KeyType, ValueType>(key, value));
    }

    std::list<KeyType> getKeys() const {
        std::list<KeyType> keys;
        inOrderKeys(root, keys);
        return keys;
    }

    std::list<ValueType> getValues() const {
        std::list<ValueType> values;
        inOrderValues(root, values);
        return values;
    }

    ValueType& operator[](const KeyType& key) {
        return get(key);
    }
};


int main() {
    Dictionary<int, std::string> dict;

    dict.set(1, "one");
    dict.set(2, "two");
    dict.set(3, "three");

    std::cout << "Value for key 2: " << dict.get(2) << std::endl;

    std::list<int> keys = dict.getKeys();
    std::list<std::string> values = dict.getValues();

    std::cout << "Keys: ";
    for (int key : keys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::cout << "Values: ";
    for (const std::string& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
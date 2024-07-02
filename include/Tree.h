//File: Tree.h - A6P2/P3
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#pragma once

#include <memory>
#include <functional>
#include <cassert>
#include <initializer_list>

template<typename V>
class Tree {
private:
    struct Node {
        Node(V v, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
            : value(v), left(l), right(r) {}
        V value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> root;

    // Helper function to find the minimum value node in a subtree

    std::shared_ptr<Node> findMin(std::shared_ptr<Node> node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node with a given value

    std::shared_ptr<Node> deleteNode(std::shared_ptr<Node> node, V value, bool& deleted) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->value) {
            node->left = deleteNode(node->left, value, deleted);
        }
        else if (value > node->value) {
            node->right = deleteNode(node->right, value, deleted);
        }
        else {
            deleted = true;

            // Node with only one child or no child

            if (node->left == nullptr) {
                return node->right;
            }
            else if (node->right == nullptr) {
                return node->left;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)

            std::shared_ptr<Node> temp = findMin(node->right);

            // Copy the inorder successor's content to this node

            node->value = temp->value;

            // Delete the inorder successor

            node->right = deleteNode(node->right, temp->value, deleted);
        }
        return node;
    }


public:
    Tree() : root(nullptr) {}

    Tree(const Tree& lft, V value, const Tree& rgt)
        : root(std::make_shared<Node>(value, lft.root, rgt.root)) {}

    bool isEmpty() const { return !root; }

    V rootValue() const { return root->value; }

    Tree left() const { return Tree(root->left); }

    Tree right() const { return Tree(root->right); }

    bool member(V x) const {
        if (isEmpty()) {
            return false;
        }
        if (root->value == x) {
            return true;
        }
        if (left().member(x)) {
            return true;
        }
        return right().member(x);
    }

    bool isLeaf() const {
        return root && !root->left && !root->right;
    }

    bool deleteNode(V value) {
        bool deleted = false;
        root = deleteNode(root, value, deleted);
        return deleted;
    }
};

int main() 

{

    // Example usage
    Tree<int> leftTree;
    Tree<int> rightTree;
    Tree<int> tree(leftTree, 10, rightTree);

    tree.deleteNode(10); // Deleting root node
    std::cout << "Tree is empty: " << tree.isEmpty() << std::endl;

    return 0;
}
//File: TreeWithRemoveLeaves.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <memory>

// Forward declaration of the Tree class to use it in the function signature

template<typename V>
class Tree;

// Function to create a new tree without leaves

template<typename V>
std::shared_ptr<typename Tree<V>::Node> removeLeaves(const std::shared_ptr<typename Tree<V>::Node>& node) {
    if (!node || (!node->left && !node->right))
    
    {
     
        // If the node is null or it's a leaf return null

        return nullptr;
    }
    // Recursively remove leaves from left and right subtrees

    std::shared_ptr<typename Tree<V>::Node> newLeft = removeLeaves(node->left);
    std::shared_ptr<typename Tree<V>::Node> newRight = removeLeaves(node->right);

    // Create a new node with the current node's value and the new left and right children

    return std::make_shared<typename Tree<V>::Node>(node->value, newLeft, newRight);

}

// Forward declaration of the Tree class definition

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

public:
    Tree() : root(nullptr) {}

    Tree(const Tree& lft, V value, const Tree& rgt)
        : root(std::make_shared<Node>(value, lft.root, rgt.root)) {}

    explicit Tree(std::shared_ptr<Node> node) : root(node) {}

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

private:
    std::shared_ptr<Node> deleteNode(std::shared_ptr<Node> node, V value, bool& deleted) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->value) {
            node->left = deleteNode(node->left, value, deleted);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value, deleted);
        } else {
            deleted = true;

            if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr) {
                return node->left;
            }

            std::shared_ptr<Node> temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value, deleted);
        }
        return node;
    }

    std::shared_ptr<Node> findMin(std::shared_ptr<Node> node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    static Tree removeLeavesFromTree(const Tree& tree) {
        return Tree(removeLeaves(tree.root));
    }
};

// Example usage

int main() {
    Tree<int> leftTree;
    Tree<int> rightTree;
    Tree<int> tree(leftTree, 10, rightTree);

    Tree<int> newTree = Tree<int>::removeLeavesFromTree(tree);
    std::cout << "New tree root value: " << newTree.rootValue() << std::endl;

    return 0;
}
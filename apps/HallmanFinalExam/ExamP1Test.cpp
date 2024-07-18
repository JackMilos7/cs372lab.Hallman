// File: ExamP1Test.cpp
// Author: Jackson Hallman
// Student Num: 00102945
// Email: jhallma5@my.athens.edu

#include "Tree.h"
#include <iostream>

int main() {

    Tree<int> leftTree;
    Tree<int> rightTree;
    Tree<int> tree(leftTree, 10, rightTree);

    tree.deleteNode(10); 
    std::cout << "Tree is empty: " << tree.isEmpty() << std::endl;

    // Testing the new functions

    Tree<int> leftChild(Tree<int>(), 5, Tree<int>());
    Tree<int> rightChild(Tree<int>(), 15, Tree<int>());
    Tree<int> mainTree(leftChild, 10, rightChild);

    int totalNodes = countNodes<int>(mainTree.getRoot());
    int internalNodes = countInternalNodes<int>(mainTree.getRoot());
    int pathLengthSum = 0;
    externalPathLength<int>(mainTree.getRoot(), 0, pathLengthSum);

    std::cout << "Total nodes: " << totalNodes << std::endl;
    std::cout << "Internal nodes: " << internalNodes << std::endl;
    std::cout << "External path length: " << pathLengthSum << std::endl;

    return 0;
}
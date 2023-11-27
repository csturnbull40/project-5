// BinarySearchTree.h
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* root, int value);
    void inorderTraversal(Node* root);
    void postorderTraversal(Node* root);
    Node* deleteNode(Node* root, int key);
    int getHeight(Node* root);
    bool isAVLTree(Node* root);

public:
    BinarySearchTree();
    BinarySearchTree();
    
    void insert(int value);
    void displayInorder();
    void deleteNode(int key);
    void displayPostorder();
    bool isAVLTree();
};

#endif // BINARY_SEARCH_TREE_H

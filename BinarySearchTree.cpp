// BinarySearchTree.cpp
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    // Implement destructor if needed for memory cleanup
}

Node* BinarySearchTree::insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void BinarySearchTree::insert(int value) {
    root = insert(root, value);
}

void BinarySearchTree::inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void BinarySearchTree::displayInorder() {
    cout << "Inorder DFS: ";
    inorderTraversal(root);
    cout << endl;
}

void BinarySearchTree::postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

void BinarySearchTree::displayPostorder() {
    cout << "Postorder DFS: ";
    postorderTraversal(root);
    cout << endl;
}

Node* BinarySearchTree::deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void BinarySearchTree::deleteNode(int key) {
    root = deleteNode(root, key);
}

int BinarySearchTree::getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

bool BinarySearchTree::isAVLTree(Node* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isAVLTree(root->left) && isAVLTree(root->right)) {
        return true;
    }

    return false;
}

bool BinarySearchTree::isAVLTree() {
    return isAVLTree(root);
}

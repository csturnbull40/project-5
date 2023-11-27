// Main.cpp

#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(nullptr));

    // Create an array with at least 35 random natural numbers (less than 100)
    int numArray[35];
    for (int i = 0; i < 35; ++i) {
        numArray[i] = rand() % 100;
    }

    // Construct a binary search tree
    BinarySearchTree bst;
    for (int i = 0; i < 35; ++i) {
        bst.insert(numArray[i]);
    }

    // Display the binary search tree with inorder DFS
    bst.displayInorder();

    // Prompt user to delete a node
    int keyToDelete;
    cout << "Enter a node to delete: ";
    cin >> keyToDelete;
    bst.deleteNode(keyToDelete);

    // Display the updated tree with postorder DFS
    bst.displayPostorder();

    // Test if the tree is an AVL tree
    if (bst.isAVLTree()) {
        cout << "The tree is an AVL tree." << endl;
    } else {
        cout << "The tree is not an AVL tree." << endl;
    }

    return 0;
}

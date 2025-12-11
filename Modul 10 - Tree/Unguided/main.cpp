#include <iostream>
#include "bstree.h"
#include "bstree.cpp"

using namespace std;

int main() {
    cout << "Hello World\n";

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);  // duplikat (tidak masuk BST)
    insertNode(root, 7);

    cout << "Inorder Traversal : ";
    printInOrder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    printPreOrder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    printPostOrder(root);
    cout << endl;

    cout << "\nKedalaman Tree : " << hitungKedalaman(root) << endl;
    cout << "Jumlah Node    : " << hitungJumlahNode(root) << endl;
    cout << "Total Info     : " << hitungTotalInfo(root) << endl;

    return 0;
}

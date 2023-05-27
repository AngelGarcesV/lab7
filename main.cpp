#include <iostream>
#include "binarySearchTree.h"
int main() {
    BinarySearchTree<int> arbol(6);
    arbol.insert(4);
    arbol.insert(5);
    arbol.insert((2));
    arbol.insert(1);
    arbol.insert(3);
    arbol.insert(8);
    arbol.insert(7);
    arbol.insert(9);
    arbol.insert(10);

    arbol.deleteNode(7);
    arbol.inorder();
    return 0;
}

//
// Created by angel on 25/05/23.
//

#ifndef LAB7_BINARYTREE_H
#define LAB7_BINARYTREE_H

template<class T>
struct NodeTree{
    T data;
    NodeTree<T>* left;
    NodeTree<T>* right;
    NodeTree<T>* makeNode(const T& value);
    void insertLeft(const T& value);
    void insertRight(const T& value);
};
template<class T>
class BinaryTree {
protected:
    NodeTree<T>* root;
    int count;
    void destroy(NodeTree<T> *ptr);
public:
    BinaryTree(const T& value);
    ~BinaryTree();
    void setRoot(const T& value);
    NodeTree<T>* getRoot();
};

template<class T>
NodeTree<T> *NodeTree<T>::makeNode(const T &value) {
    NodeTree<T>* temp = new NodeTree<T>;
    temp->data = value;
    temp->left = 0;
    temp->right = 0;
    return temp;
}
template<class T>
void NodeTree<T>::insertLeft(const T &value) {
    if(!left){
        left = makeNode(value);
    }else{
        NodeTree<T>* temp = makeNode(value);
        temp->left = left;
        left = temp;
    }
}
template<class T>
void NodeTree<T>::insertRight(const T &value) {
    if(!right){
        right = makeNode(value);
    }else{
        NodeTree<T>* temp = makeNode(value);
        temp->right = right;
        right = temp;
    }
}
template<class T>
void BinaryTree<T>::destroy(NodeTree<T> *ptr) {
    if(!ptr) return;
    destroy(ptr->left);
    destroy(ptr->right);
    delete ptr;
}
template<class T>
BinaryTree<T>::BinaryTree(const T &value) {
    root = root->makeNode(value);
}
template<class T>
BinaryTree<T>::~BinaryTree() {
    destroy(root);
}
template<class T>
void BinaryTree<T>::setRoot(const T &value) {
    root = root->makeNode(value);
}
template<class T>
NodeTree<T>* BinaryTree<T>::getRoot(){
    return root;
}

#endif //LAB7_BINARYTREE_H

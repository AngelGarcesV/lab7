//
// Created by angel on 25/05/23.
//

#ifndef LAB7_BINARYSEARCHTREE_H
#define LAB7_BINARYSEARCHTREE_H
#include "binaryTree.h"
#include <iostream>
#include <stack>
using namespace std;
template<class T>
class BinarySearchTree: public BinaryTree<T>{
    int count;
    void insert(const T& value, NodeTree<T>*& ptr); // Helper
    void inorder(NodeTree<T> *ptr) const; // Helper
    void preorder(NodeTree<T> *ptr) const; // Helper
    void postorder(NodeTree<T> *ptr) const; // Helper
    bool search(const T& value, NodeTree<T> *ptr) const; // Helper
    bool deleteNode(const T& value, NodeTree<T> *&ptr);
    stack<NodeTree<T>*> pilaPadres;
public:
    BinarySearchTree(const T& value);
    ~BinarySearchTree();
    void insert(const T& value);
    bool search(const T& value) const;
    void inorder() const;
    void preorder() const;
    void postorder() const;

    bool deleteNode(const T &value);
};

template<class T>
BinarySearchTree<T>::BinarySearchTree(const T &value): BinaryTree<T>(value)
{
    count = 0;
}
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
}
template<class T>
void BinarySearchTree<T>::insert(const T &value, NodeTree<T>*& ptr) {
    if(!ptr){
        ptr = ptr->makeNode(value);
        return;
    }else if(value < ptr->data){
        insert(value, ptr->left);
    }else{
        insert(value, ptr->right);
    }
}
template<class T>
void BinarySearchTree<T>::insert(const T &value) {
    insert(value, this->root);
    count++;
}
template<class T>
void BinarySearchTree<T>::inorder(NodeTree<T> *ptr) const {
    if(!ptr) return;
    inorder(ptr->left);
    cout << ptr->data << endl;
    inorder(ptr->right);
}
template<class T>
void BinarySearchTree<T>::inorder() const {
    inorder(this->root);
}
template<class T>
void BinarySearchTree<T>::preorder(NodeTree<T> *ptr) const {
    if(!ptr) return;
    cout << ptr->data << endl;
    preorder(ptr->left);
    preorder(ptr->right);
}
template<class T>
void BinarySearchTree<T>::preorder() const {
    preorder(this->root);
}
template<class T>
void BinarySearchTree<T>::postorder(NodeTree<T> *ptr) const {
    if(!ptr) return;
    postorder(ptr->left);
    postorder(ptr->right);
    cout << ptr->data << endl;
}
template<class T>
void BinarySearchTree<T>::postorder() const {
    postorder(this->root);
}
template<class T>
bool BinarySearchTree<T>::search(const T &value, NodeTree<T> *ptr) const {
    if(!ptr) return false;
    else if(ptr->data == value) return true;
    else if(value < ptr->data) return search(value, ptr->left);
    else return search(value, ptr->right);
}
template<class T>
bool BinarySearchTree<T>::search(const T &value) const {
    return search(value, this->root);
}
template<class T>
bool BinarySearchTree<T>::deleteNode(const T &value, NodeTree<T> *&ptr){
    NodeTree<T> *nodopadre;
    if(!ptr)
    {
        return false;
    }else if(ptr->data == value) {
        //------no tiene hijos------//
        if(!ptr->right && !ptr->left){
            delete ptr;
            ptr = nullptr;

        }
        //------tiene hijio derecho------//
        else if(ptr->right){

            nodopadre = pilaPadres.top();
            nodopadre->right = ptr->right;
        }
        //------tiene hijio izquierdo------//
        else if(ptr->left){
            nodopadre = pilaPadres.top();
            nodopadre->left = ptr->left;
        }
        return true;
    }
    else if(value < ptr->data){
        this->pilaPadres.push(ptr);
        return deleteNode(value, ptr->left);}
    else {
        this->pilaPadres.push(ptr);
        return deleteNode(value, ptr->right);}
};

template <class T>
bool BinarySearchTree<T>::deleteNode(const T &value){
    return deleteNode(value,this->root);
}


#endif //LAB7_BINARYSEARCHTREE_H

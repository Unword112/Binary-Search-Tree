#include "BinarySearchTree.h"

#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    removeTree(root);
}

void BinarySearchTree::removeTree(BinarySearchTree *&p){
    if(p != NULL){
        if(p->left != NULL) removeTree(p->left);
        if(p->right != NULL) removeTree(p->right);
        delete p;
        p = NULL;
    }
}

void BinarySearchTree::insert(int e){

}

void BinarySearchTree::remove(int e){

}

void BinarySearchTree::display(ORDER o = IN_ORDER){
    if(o == PRE_ORDER) displayPreOrder(root);
    else if(o == POST_ORDER) displayPostOrder(root);
    else dispalyInOrder(root);
}

void BinarySearchTree::displayPreOrder(BinaryTreeNode *p){
    cout << "( ";
    cout << p->element;
    cout << " , ";
    if(p->left != NULL) displayPreOrder(p->left);
    cout << " , ";
    if(p->right != NULL) displayPreOrder(p->right);
    cout << " )";
}

void BinarySearchTree::dispalyInOrder(BinaryTreeNode *p){
    cout << "( ";
    if(p->left != NULL) dispalyInOrder(p->left);
    cout << " , ";
    cout << p->element;
    cout << " , ";
    if(p->right != NULL) dispalyInOrder(p->right);
    cout << " )";
}

void BinarySearchTree::displayPostOrder(BinaryTreeNode *p){

}
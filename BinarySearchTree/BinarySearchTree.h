#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

#include "../BinaryTreeNode/BinaryTreeNode.h"

enum ORDER {PRE_ORDER, IN_ORDER, POST_ORDER};

#include <iostream>

class BinarySearchTree {
    private:
        BinarySearchTree *root;

        void removeTree(BinarySearchTree *&p);
        void displayPreOrder(BinaryTreeNode *p);
        void dispalyInOrder(BinaryTreeNode *p);
        void displayPostOrder(BinaryTreeNode *p);
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(int e);
        void remove(int e);
        void display(ORDER o = IN_ORDER);
};

#endif
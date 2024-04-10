#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

#include "../BinaryTreeNode/BinaryTreeNode.h"

#define DEFAULT_SIZE_RANDOM 5

enum ORDER {PRE_ORDER, IN_ORDER, POST_ORDER};

#include <iostream>

class BinarySearchTree {
    private:
        BinaryTreeNode *root;

        void removeTree(BinaryTreeNode *&p);
        void insert(BinaryTreeNode *p, int e);

        BinaryTreeNode* getParent(BinaryTreeNode *root, BinaryTreeNode *p);
        BinaryTreeNode *find(int e);
        void deleteDegree(int degree, BinaryTreeNode *p);

        int findMax(BinaryTreeNode *p);
        int findMin(BinaryTreeNode *p);
        int findDepth(BinaryTreeNode *p, int curDepth);

        void displayPreOrder(BinaryTreeNode *p);
        void dispalyInOrder(BinaryTreeNode *p);
        void displayPostOrder(BinaryTreeNode *p);
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(int e);
        void remove(int e);
        void display(ORDER o = IN_ORDER);

        int findMax();
        int findMin();
        int findDepth();
};

#endif
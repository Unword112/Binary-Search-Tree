#ifndef _BinaryTreeNode_H_
#define _BinaryTreeNode_H_

#include <iostream>

class BinaryTreeNode {
    public:
        int element;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
    public:
        BinaryTreeNode(int element = 0, BinaryTreeNode *left = NULL, BinaryTreeNode *right = NULL);
};

#endif
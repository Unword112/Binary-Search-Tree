#include "BinarySearchTree.h"

#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    removeTree(root);
}

void BinarySearchTree::removeTree(BinaryTreeNode *&p){
    if(p != NULL){
        if(p->left != NULL) removeTree(p->left);
        if(p->right != NULL) removeTree(p->right);
        delete p;
        p = NULL;
    }
}

void BinarySearchTree::insert(int e){
    insert(root, e);
}

void BinarySearchTree::insert(BinaryTreeNode *p, int e){
    if(p == NULL) root = new BinaryTreeNode(e);
    else if(e < p->element){
        if(p->left != NULL) insert(p->left, e);
        else p->left = new BinaryTreeNode(e);
    } else {
        if(p->right != NULL) insert(p->right, e);
        else p->right = new BinaryTreeNode(e);
    }
}

/*void BinarySearchTree::remove(int e) {
    BinaryTreeNode *p = find(e);

    if (p != NULL) {
        if (p->left == NULL && p->right == NULL) 
            deleteDegree(0, p);
        else if (p->left != NULL && p->right != NULL) 
            deleteDegree(2, p);
        else 
            deleteDegree(1, p);
    }
}

BinaryTreeNode* BinarySearchTree::find(int e) {
    BinaryTreeNode *p = root;

    while (p != NULL && e != p->element) {
        if (e < p->element) 
            p = p->left;
        else 
            p = p->right;
    }
    return p;
}

void BinarySearchTree::deleteDegree(int degree, BinaryTreeNode *p) {
    if (degree == 0) {
        if (p == root) {
            root = NULL;
        } else {
            BinaryTreeNode *parent = getParent(root, p);
            if (parent->left == p) 
                parent->left = NULL;
            else 
                parent->right = NULL;
        }
        delete p;
    } else if (degree == 1) {
        BinaryTreeNode *child = (p->left != NULL) ? p->left : p->right;
        if (p == root) {
            root = child;
        } else {
            BinaryTreeNode *parent = getParent(root, p);
            if (parent->left == p) 
                parent->left = child;
            else 
                parent->right = child;
        }
        delete p;
    } else if (degree == 2) {
        // ขั้นตอนการลบโหนดที่มีลูกสองตัว
        // ในกรณีนี้จะใช้วิธีการหาโหนดที่มากที่สุดในส่วนซ้ายของต้นไม้ย่อยของโหนดที่ต้องการลบ
        // หรือโหนดที่น้อยที่สุดในส่วนขวาของต้นไม้ย่อยของโหนดที่ต้องการลบ
        BinaryTreeNode *maxLeft = findMax(p->left);
        p->element = maxLeft->element;
        remove(maxLeft->element);
    }
}

BinaryTreeNode* BinarySearchTree::getParent(BinaryTreeNode *root, BinaryTreeNode *p) {
    BinaryTreeNode *parent = NULL;
    while (root != NULL && root != p) {
        parent = root;
        if (p->element < root->element) 
            root = root->left;
        else 
            root = root->right;
    }
    return parent;
}*/

void BinarySearchTree::display(ORDER o){
    if(root == NULL) cout << "Tree:  - , - , - " << endl;
    else {
        cout << "Tree: ";
        if(o == PRE_ORDER) displayPreOrder(root);
        else if(o == POST_ORDER) displayPostOrder(root);
        else dispalyInOrder(root);
        cout << endl;
    }
}

void BinarySearchTree::displayPreOrder(BinaryTreeNode *p){
    if (p == NULL) {
        cout << "- , ";
        return;
    }

    cout << p->element << " , ";
    displayPreOrder(p->left);
    displayPreOrder(p->right);
}

void BinarySearchTree::dispalyInOrder(BinaryTreeNode *p){
    if (p == NULL) {
        cout << "- , ";
        return;
    }

    dispalyInOrder(p->left);
    cout << p->element << " , ";
    dispalyInOrder(p->right);
}

void BinarySearchTree::displayPostOrder(BinaryTreeNode *p){
    if (p == NULL) {
        cout << "- , ";
        return;
    }

    displayPostOrder(p->left);
    displayPostOrder(p->right);
    cout << p->element << " , ";

}

int BinarySearchTree::findMax(){
    if(root == NULL) {
        cerr << "Error : Empty Tree..." << endl;
        return -1;
    } else return findMax(root);
}

int BinarySearchTree::findMin(){
    if(root == NULL) {
        cerr << "Error : Empty Tree..." << endl;
        return -1;
    } else return findMin(root);
}

int BinarySearchTree::findDepth(){
    if(root == NULL) {
        cerr << "Error : Empty Tree..." << endl;
        return 0;
    } else return findDepth(root, 0);
}

int BinarySearchTree::findMax(BinaryTreeNode *p){
    if(p->right != NULL) return findMax(p->right);
    else return p->element;
}

int BinarySearchTree::findMin(BinaryTreeNode *p){
    if(p->left != NULL) return findMin(p->left);
    else return p->element;
}

int BinarySearchTree::findDepth(BinaryTreeNode *p, int curDepth){
    int leftDepth, rightDepth;

    if(p->left != NULL) leftDepth = findDepth(p->left, curDepth + 1);
    else leftDepth = curDepth;

    if(p->right != NULL) rightDepth = findDepth(p->right, curDepth + 1);
    else rightDepth = curDepth;

    return max(leftDepth, rightDepth); // Return the maximum depth among left and right subtrees
}
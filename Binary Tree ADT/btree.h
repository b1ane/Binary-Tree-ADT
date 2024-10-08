//
//  btree.h
//  Binary Tree ADT
//
//  Created by blane on 9/28/22.
//

#ifndef btree_h
#define btree_h
#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class btree {
private:
    node* root;
public:
    //tree is empty when created
    btree() {
        root = nullptr;
    }
    
    //check if tree is empty
    bool isEmpty() {
        if (root == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    
    //user can create node and inserts
    void insert(int val) {
        //node created
        node* newNode = new node;
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        
        //node* r = root;
        
        //if list is Empty set value to root
        if (root == nullptr) {
            root = newNode;
        }
        else {
            //call recursive insert function
            insert2(root, newNode);
        }
    }
    
    // insert at check node, inserts new node
    // recursive function
    void insert2(node* &checkN, node* newN) {
        //BASE CASE -- set value when node is empty
        if (checkN == nullptr) {
            checkN = newN;
            return;
        }
        
        //node is not empty, check left of node -- if empty
        if (checkN->left != nullptr) {
            insert2(checkN->left, newN);
        }
        else {
            insert2(checkN->right, newN);
        }
    }
    
    
    //output tree
    void print(node* r) {
        //if node is empty, do nothing
        if(r == nullptr) {
            return;
        }
        //otherwise -- output data
        cout << r->data << " ";
        //recursive call for rest of tree
        print(r->left);
        print(r->right);
    }
    
    //user facing print
    void print() {
        //call recursive print function
        print(root);
    }
    
    //check if node is a leaf
    bool isLeaf(node* l) {
        //if left and right node is empty, node is a leaf
        if (l->left == nullptr && l->right == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void RtoL (node* r, int val, int &retVal) {
        //BASE CASE -- if node is empty, do nothing
        if (r == nullptr) {
            return;
        }
        
        //holds value of node to equal
        int temp = val;
        //subtracts node value from val to equal
        temp = temp - r->data;
        
        //when temp is zero AND node is a leaf -- update ans;
        if (isLeaf(r) && temp == 0) {
            retVal = 1;
        }
        else {
            retVal = 0;
        }
        
        RtoL(r->left, val, retVal);
        RtoL(r->right, val, retVal);
    }
    
    int eval(int val) {
        int returnValue = 0;
        RtoL(root, val, returnValue);
        return returnValue;
    }
    
    
    
    
};


#endif /* btree_h */

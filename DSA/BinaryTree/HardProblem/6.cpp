#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int isSumProperty(Node *root) {
        // code here
        if(!root) return true;
        if(root->left==NULL && root->right==NULL) return true;
        int left = 0;
        if(root->left) left = root->left->data;
        int right = 0;
        if(root->right) right = root->right->data;
        if((left+right) == root->data) return (isSumProperty(root->left) && isSumProperty(root->right));
        return false;
    }
};
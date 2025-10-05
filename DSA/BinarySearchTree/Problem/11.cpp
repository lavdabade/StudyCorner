#include<iostream>

using namespace std;

class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* suc = NULL;
        while(root) {
            if(root->data == key) break;
            else if(root->data < key) {
                pre = root;
                root = root->right;
            }
            else {
                suc = root;
                root = root->left;
            }
        }
        if(!root) return {pre, suc};
        if(root->left) {
            pre = root->left;
            while(pre->right) pre = pre->right;
        }
        if(root->right) {
            suc = root->right;
            while(suc->left) suc = suc->left;
        }
        return {pre, suc};
    }
};
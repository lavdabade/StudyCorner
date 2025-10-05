#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = right = NULL;
    }

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root==NULL || root->data==n1 || root->data==n2) return root;
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
};
#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(n1->data > n2->data) return LCA(root, n2, n1);
        if(n1->data <= root->data && n2->data >= root->data) return root;
        if(n1->data < root->data) return LCA(root->left, n1, n2);
        return LCA(root->right, n1, n2);
    }
};
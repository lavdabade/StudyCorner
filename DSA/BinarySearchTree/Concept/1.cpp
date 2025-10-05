#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node* root, int x) {
    // Your code here
    while(root) {
        if(root->data == x) return true;
        else if(root->data < x) root=root->right;
        else root=root->left;
    }
    return false;
}
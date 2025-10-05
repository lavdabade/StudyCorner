#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* insert(Node* root, int key) {
        //  code  here
        Node* prev = root;
        Node* head = root;
        while(root) {
            if(root->data == key) return head;
            prev = root;
            if(root->data < key) root = root->right;
            else root = root->left;
        }
        if(prev->data < key) prev->right = new Node(key);
        else prev->left = new Node(key);
        return head;
    }
};
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

Node* constructTree(int &idx, int minLimit, int maxLimit, int post[], int size) {
    if(idx < 0 || post[idx] < minLimit || post[idx] > maxLimit) return NULL;
    Node* newNode = new Node(post[idx--]);
    newNode->right = constructTree(idx, newNode->data, maxLimit, post, size);
    newNode->left = constructTree(idx, minLimit, newNode->data, post, size);
    return newNode;
}

Node *constructTree(int post[], int size) {
    // code here
    int idx = size-1;
    return constructTree(idx, INT_MIN, INT_MAX, post, size);
}
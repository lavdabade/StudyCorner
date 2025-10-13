#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    void correctBST(Node* root, Node* &firstNode, Node* &secondNode, Node* &prev) {
        if(!root) return;
        correctBST(root->left, firstNode, secondNode, prev);
        if(prev!=NULL && prev->data > root->data) {
            if(firstNode==NULL) 
                firstNode = prev;
            secondNode = root;
        }
        prev = root;
        correctBST(root->right, firstNode, secondNode, prev);
    }
    
  public:
    void correctBST(Node* root) {
        // add code here.
        Node* prev = NULL;
        Node* firstNode = NULL;
        Node* secondNode = NULL;
        correctBST(root, firstNode, secondNode, prev);
        swap(firstNode->data, secondNode->data);
    }
};
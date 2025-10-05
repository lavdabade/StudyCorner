#include<iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution {
  private:
    Node* Bst(int pre[], int &idx, int size, int lowLimit, int highLimit) {
        if(idx > (size-1) || pre[idx]<lowLimit || pre[idx]>highLimit) return NULL;
        Node* newN = newNode(pre[idx++]);
        newN->left = Bst(pre, idx, size, lowLimit, newN->data);
        newN->right = Bst(pre, idx, size, newN->data, highLimit);
        return newN;
    }
    
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        int idx=0;
        return Bst(pre, idx, size, INT_MIN, INT_MAX);
    }
};
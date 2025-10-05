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
  private:
    bool isLeafNode(Node* root) {
        return (root->left==NULL && root->right==NULL);
    }
    
    vector<int> leftTraverse(Node* root) {
        vector<int> ans;
        while(root) {
            if(!isLeafNode(root)) ans.push_back(root->data);
            if(root->left) root = root->left;
            else root = root->right;
        }
        return ans;
    }
    
    vector<int> rightTraverse(Node* root) {
        vector<int> ans;
        while(root) {
            if(!isLeafNode(root)) ans.push_back(root->data);
            if(root->right) root = root->right;
            else root = root->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> getLeafNode(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* node = st.top();
            st.pop();
            if(isLeafNode(node)) ans.push_back(node->data);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
    }
  
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!isLeafNode(root)) ans.push_back(root->data);
        vector<int> left = leftTraverse(root->left);
        vector<int> leaf = getLeafNode(root);
        vector<int> right = rightTraverse(root->right);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), leaf.begin(), leaf.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};
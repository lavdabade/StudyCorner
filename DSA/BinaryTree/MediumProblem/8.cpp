#include<iostream>
#include<vector>

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
  private:
    void leftViewUtil(Node* root, vector<int> &ans, int level) {
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->data);
        leftViewUtil(root->left, ans, level+1);
        leftViewUtil(root->right, ans, level+1);
    }
  
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        leftViewUtil(root, ans, 0);
        return ans;
    }
};
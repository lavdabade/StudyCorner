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
  public:
    vector<int> rightView(Node *root) {
        //  Code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            ans.push_back(q.front()->data);
            int sz = q.size();
            while(sz--) {
                Node* node = q.front();
                q.pop();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return ans;
    }
};
#include<iostream>
#include<map>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level] = node->data;
            if(node->left) q.push({node->left, level-1});
            if(node->right) q.push({node->right, level+1});
        }
        for(auto it: mp) ans.push_back(it.second);
        return ans;
    }
};
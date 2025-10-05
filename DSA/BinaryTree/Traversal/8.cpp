#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        bool reverse = false;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int qsz = sz;
            vector<int> levelNode(sz);
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                levelNode[reverse ? sz : qsz-sz-1] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            reverse = !reverse;
            ans.push_back(levelNode);
        }
        return ans;
    }
};
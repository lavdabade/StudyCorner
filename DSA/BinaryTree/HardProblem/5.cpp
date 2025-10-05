#include<iostream>

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        int ans=0;
        while(!q.empty()) {
            int n = q.size();
            int mini=q.front().second;
            int maxi=0;
            while(n--) {
                TreeNode* node = q.front().first;
                long idx = q.front().second;
                q.pop();
                if(n==0) maxi = idx;
                if(node->left) q.push({node->left, 2*(idx-mini)});
                if(node->right) q.push({node->right, 2*(idx-mini)+1});
            }
            ans=max(ans, maxi-mini+1);
        }
        return ans;
    }
};
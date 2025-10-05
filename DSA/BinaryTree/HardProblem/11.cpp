#include<iostream>
#include<vector>
#include<map>

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
private:
    TreeNode* buildTreeUtil(int inStart, int inEnd, vector<int> &inOrder, 
                            int postStart, int postEnd, vector<int> &postOrder,
                            map<int, int> &inOrderIdxMap) {
        if(inStart > inEnd || postStart > postEnd) return NULL;
        TreeNode* node = new TreeNode(postOrder[postEnd]);
        int inOrderLeftNodeCount = inOrderIdxMap[postOrder[postEnd]] - inStart;
        node->left = buildTreeUtil(inStart, inStart + inOrderLeftNodeCount - 1, inOrder,
                                   postStart, postStart + inOrderLeftNodeCount - 1, postOrder,
                                   inOrderIdxMap);
        node->right = buildTreeUtil(inStart + inOrderLeftNodeCount + 1, inEnd, inOrder,
                                    postStart + inOrderLeftNodeCount, postEnd - 1, postOrder,
                                    inOrderIdxMap);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
        int n = inOrder.size();
        map<int, int> inOrderIdxMap;
        for(int i=0; i<n; i++) inOrderIdxMap[inOrder[i]]=i;
        return buildTreeUtil(0, n-1, inOrder, 0, n-1, postOrder, inOrderIdxMap);
    }
};
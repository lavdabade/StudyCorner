#include<iostream>
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
    TreeNode* buildTreeUtil(int preStart, int preEnd, vector<int> &preOrder, 
                            int inStart, int inEnd, vector<int> &inOrder,
                            map<int, int> &inOrderIdxMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(preOrder[preStart]);
        int preOrderLeftNodeCount = inOrderIdxMap[preOrder[preStart]]-inStart;
        node->left = buildTreeUtil(preStart+1, preStart+preOrderLeftNodeCount, preOrder,
                                   inStart, inStart+preOrderLeftNodeCount-1, inOrder,
                                   inOrderIdxMap);
        node->right = buildTreeUtil(preStart+preOrderLeftNodeCount+1, preEnd, preOrder,
                                    inStart+preOrderLeftNodeCount+1, inEnd, inOrder,
                                    inOrderIdxMap);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        map<int, int> inOrderIdxMap;
        int n = inOrder.size();
        for(int i=0; i<n; i++) {
            inOrderIdxMap[inOrder[i]]=i;
        }
        return buildTreeUtil(0, n-1, preOrder, 0, n-1, inOrder, inOrderIdxMap);
    }
};
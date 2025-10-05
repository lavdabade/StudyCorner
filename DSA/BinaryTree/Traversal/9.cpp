#include<iostream>
#include<vector>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

enum Order {
    PRE,
    IN,
    POST
};

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    stack<pair<TreeNode*, Order>> st;
    st.push({root, PRE});
    while(!st.empty()) {
        TreeNode* node = st.top().first;
        Order oder = st.top().second;
        st.pop();
        if(oder == PRE) {
            ans[1].push_back(node->data);
            st.push({node, IN});
            if(node->left) st.push({node->left, PRE});
        }
        else if(oder == IN) {
            ans[0].push_back(node->data);
            st.push({node, POST});
            if(node->right) st.push({node->right, PRE});
        }
        else {
            ans[2].push_back(node->data);
        }
    }
    return ans;
}
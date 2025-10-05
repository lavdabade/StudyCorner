#include<iostream>

using namespace std;

template<typename T>
class TreeNode
{
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

void pathInATreeUtil(TreeNode<int>* root, int x, vector<int> &ans) {
	if(!root || (!ans.empty() && ans.back()==x)) return;
	ans.push_back(root->data);
	pathInATreeUtil(root->left, x, ans);
	pathInATreeUtil(root->right, x, ans);
	if(!ans.empty() && ans.back()==x) return;
	ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	pathInATreeUtil(root, x, ans);
	return ans;
}

#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  private:
    void pathsUtil(Node* root, vector<int> &path, vector<vector<int>> &ans) {
        if(!root) return;
        if(root->left==NULL && root->right==NULL) {
            path.push_back(root->data);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->data);
        pathsUtil(root->left, path, ans);
        pathsUtil(root->right, path, ans);
        path.pop_back();
    }
  
  public:
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> path;
        pathsUtil(root, path, ans);
        return ans;
    }
};
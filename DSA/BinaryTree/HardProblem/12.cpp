#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> serialize(Node *root) {
        //  code here
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            ans.push_back(node->data);
            if(node->data == -1) continue;
            q.push(node->left ? node->left : new Node(-1));
            q.push(node->right ? node->right : new Node(-1));
        }
        return ans;
    }

    Node *deSerialize(vector<int> &arr) {
        //  code here
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int idx=1;
        while(idx<arr.size()) {
            Node* node = q.front();
            q.pop();
            if(arr[idx]==-1) {
                node->left=NULL;
            }
            else {
                node->left=new Node(arr[idx]);
                q.push(node->left);
            }
            idx++;
            if(arr[idx]==-1) {
                node->right=NULL;
            }
            else {
                node->right=new Node(arr[idx]);
                q.push(node->right);
            }
            idx++;
        }
        return root;
    }
};
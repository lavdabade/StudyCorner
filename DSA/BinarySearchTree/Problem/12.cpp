#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class TreeIterator {
  private:
    stack<Node*> st;
  public:
    TreeIterator(Node* root) {
        putAll(root);
    }
    void putAll(Node* root) {
        while(root) {
            st.push(root);
            root=root->left;
        }
    }
    bool hasNext() {
        return !st.empty();
    }
    int getTop() {
        return st.top()->data;
    }
    int removeTop() {
        Node* ansNode = st.top();
        st.pop();
        putAll(ansNode->right);
        return ansNode->data;
    }
};

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> ans;
        TreeIterator t1(root1);
        TreeIterator t2(root2);
        while(t1.hasNext() && t2.hasNext()) {
            if(t1.getTop() < t2.getTop()) {
                ans.push_back(t1.getTop());
                t1.removeTop();
            }
            else {
                ans.push_back(t2.getTop());
                t2.removeTop();
            }
        }
        while(t1.hasNext()) {
            ans.push_back(t1.getTop());
            t1.removeTop();
        }
        while(t2.hasNext()) {
            ans.push_back(t2.getTop());
            t2.removeTop();
        }
        return ans;
    }
};
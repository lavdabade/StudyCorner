#include<iostream>

using namespace std;

class Node {
  public:
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
    bool reverseFlag;
  public:
    TreeIterator(Node* root, bool reverseFlag) {
        this->reverseFlag = reverseFlag;
        putAll(root);
    }
    void putAll(Node* root) {
        while(root) {
            st.push(root);
            if(reverseFlag) root = root->right;
            else root = root->left;
        }
    }
    bool hasNext() {
        return !st.empty();
    }
    Node* getTop() {
        return st.top();
    }
    void removeTop() {
        Node* top = st.top();
        st.pop();
        putAll(reverseFlag ? top->left : top->right);
    }
};

class Solution {
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        TreeIterator t1(root, false);
        TreeIterator t2(root, true);
        while(t1.hasNext() && t2.hasNext()) {
            if(t1.getTop()!=t2.getTop() && t1.getTop()->data + t2.getTop()->data == target) {
                return true;
            }
            else if((t1.getTop()->data + t2.getTop()->data) < target) {
                t1.removeTop();
            }
            else {
                t2.removeTop();
            }
        }
        return false;
    }
};
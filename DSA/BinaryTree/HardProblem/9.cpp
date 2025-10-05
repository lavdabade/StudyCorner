#include<iostream>
#include<map>
#include<set>

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

class Solution {
  private:
    Node* getTargetNode(Node* root, int target) {
        if(!root) return root;
        if(root->data == target) return root;
        Node* left = getTargetNode(root->left, target);
        if(left) return left;
        return getTargetNode(root->right, target);
    }
  
    void populateParentMap(Node* root, map<Node*, Node*> &parentMap) {
        if(!root) return;
        if(root->left) parentMap[root->left]=root;
        if(root->right) parentMap[root->right]=root;
        populateParentMap(root->left, parentMap);
        populateParentMap(root->right, parentMap);
    }
    
  public:
    int minTime(Node* root, int target) {
        // code here
        set<Node*> vis;
        map<Node*, Node*> parentMap;
        queue<Node*> q;
        Node* targetNode = getTargetNode(root, target);
        q.push(targetNode);
        vis.insert(targetNode);
        int ans=0;
        populateParentMap(root, parentMap);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                Node* node = q.front();
                q.pop();
                if(node->left && vis.find(node->left)==vis.end()) {
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && vis.find(node->right)==vis.end()) {
                    vis.insert(node->right);
                    q.push(node->right);
                }
                if(parentMap.count(node) > 0 && vis.find(parentMap[node])==vis.end()) {
                    vis.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
            ans++;
        }
        return ans-1;
    }
};
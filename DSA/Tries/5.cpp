#include<iostream>
#include<vector>

using namespace std;

class Node {
  private:
    Node* node[2];
    
  public:
    Node() {
        for(int i=0; i<2; i++) {
            node[i] = NULL;
        }
    }
    
    bool isNode(int i) {
        return node[i]!=NULL;
    }
    
    Node* getNode(int i) {
        return node[i];
    }
    
    void setNode(int i) {
        node[i] = new Node();
    }
};

class Trie {
  private:
    Node* root;
  
  public:
    Trie() {
        root = new Node();
    }
    
    void insert(int n) {
        Node* head = root;
        for(int i=31; i>=0; i--) {
            int bit = ((n & (1<<i)) == 0) ? 0 : 1;
            if(!head->isNode(bit)) head->setNode(bit);
            head = head->getNode(bit);
        }
    }
    
    int getXOR(int n) {
        int ans = 0;
        Node* head = root;
        for(int i=31; i>=0; i--) {
            int bit = ((n & (1<<i)) == 0) ? 0 : 1;
            if(head->isNode(1-bit)) {
                head = head->getNode(1-bit);
                ans = ans | (1<<i);
            }
            else {
                head = head->getNode(bit);
            }
        }
        return ans;
    }
};

// User function Template for C++
class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        Trie trie;
        for(auto it: arr) {
            trie.insert(it);
        }
        int ans = 0;
        for(auto it: arr) {
            ans = max(ans, trie.getXOR(it));
        }
        return ans;
    }
};

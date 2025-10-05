#include<iostream>
#include<vector>

using namespace std;

class Node {
  private:
    Node* node[2];
    
  public:
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
                ans |= (1<<i);
            } 
            else {
                head = head->getNode(bit);
            }
        }
        return ans;
    }
};

class Solution {
  private:
    static bool comp(vector<int> a, vector<int> b) {
      return a[1]<b[1];
  }
  
  public:
    vector<int> maxXor(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> q;
        int qn = queries.size();
        for(int i=0; i<qn; i++) {
            q.push_back({queries[i][0], queries[i][1], i});
        }
        sort(q.begin(), q.end(), comp);
        int idx = 0;
        int n = arr.size();
        vector<int> ans(qn, -1);
        Trie trie;
        for(auto it: q) {
            int num = it[0];
            int limit = it[1];
            int queryIdx = it[2];
            while(idx < n && arr[idx] <= limit) {
                trie.insert(arr[idx++]);
            }
            if (idx != 0) ans[queryIdx] = trie.getXOR(num);
        }
        return ans;
    }
};
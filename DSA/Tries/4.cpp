#include<iostream>

using namespace std;

class Node {
  private:
    Node* node[26];

  public:
    Node() {
        for(int i=0; i<26; i++) {
            node[i] = NULL;
        }
    }
    
    Node* getNode(char ch) {
        return node[ch - 'a'];
    }
    
    bool isNode(char ch) {
        return node[ch - 'a']!=NULL;
    }
    
    void setNode(char ch) {
        node[ch - 'a'] = new Node();
    }
};

class Trie {
  private:
    Node* root;
  
  public:
    Trie() {
        root = new Node();
    }
    
    int insert(string word) {
        int insertCount = 0;
        Node* head = root;
        for(auto it: word) {
            if(!head->isNode(it)) {
                insertCount++;
                head->setNode(it);
            }
            head = head->getNode(it);
        }
        return insertCount;
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s) {
    // Your code here
    int ans = 1;
    int n = s.size();
    Trie trie;
    for(int i=0; i<n; i++) {
        ans += trie.insert(s.substr(i, n-i));
    }
    return ans;
}
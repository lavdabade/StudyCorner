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
    
    void setNode(char ch) {
        node[ch - 'a'] = new Node();
    }
    
    Node* getNode(char ch) {
        return node[ch - 'a'];
    }
    
    bool isNode(char ch) {
        return node[ch - 'a'] != NULL;
    }
};

class Trie {
  private:
    Node* root;
    
  public:
    Trie() {
        root = new Node();
    }
    
    void checkAndInsert(string word, string &ans) {
        Node* head = root;
        int n = word.size();
        for(int i=0; i<n; i++) {
            if(head->getNode(word[i])==NULL){
                if ((n-i)>1) return;
                head->setNode(word[i]);
            }
            head = head->getNode(word[i]);
        }
        if(ans.size() < n) {
            ans = word;
        }
    }
};

class Solution {
  public:
    string longestValidWord(vector<string>& words) {
        // code here
        string ans = "";
        sort(words.begin(), words.end());
        Trie trie;
        for(auto it: words) {
            trie.checkAndInsert(it, ans);
        }
        return ans;
    }
};

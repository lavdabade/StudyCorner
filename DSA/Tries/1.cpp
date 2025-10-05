#include<iostream>

using namespace std;

// User function template for C++
class Node {
  private:
    Node* node[26];
    bool isEnd;
  public:
    Node() {
        isEnd = false;
        for(int i=0; i<26; i++) {
            node[i] = NULL;
        }
    }
    Node* getNode(char ch) {
        return node[ch - 'a'];
    }
    bool isNode(char ch) {
        return node[ch - 'a'] != NULL;
    }
    void setNode(char ch) {
        node[ch - 'a'] = new Node();
    }
    bool getIsEnd() {
        return isEnd;
    }
    void setIsEnd() {
        isEnd = true;
    }
};

class Trie {
  private:
    Node* root;
  
  public:

    Trie() {
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node = root;
        for(auto it: word) {
            if(!node->isNode(it)) node->setNode(it);
            node = node->getNode(it);
        }
        node->setIsEnd();
    }

    bool search(string &word) {
        // search word in the Trie
        Node* node = root;
        for(auto it: word) {
            if(!node->isNode(it)) return false;
            node = node->getNode(it);
        }
        return node->getIsEnd();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* node = root;
        for(auto it: word) {
            if(!node->isNode(it)) return false;
            node = node->getNode(it);
        }
        return true;
    }
};

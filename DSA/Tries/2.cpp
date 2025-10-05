#include<iostream> 

using namespace std;

class Node {
  private:
    Node* node[26];
    int endCount;
    int startWithCount;

  public:
    Node() {
        for(int i=0; i<26; i++) {
            node[i] = NULL;
        }
        endCount = 0;
        startWithCount = 0;
    }

    bool isNode(char ch) {
        return node[ch - 'a'] != NULL;
    }

    void setNode(char ch) {
        node[ch - 'a'] = new Node();
    }

    Node* getNode(char ch) {
        return node[ch - 'a'];
    }

    int getEndCount() {
        return endCount;
    }

    void addEndCount() {
        endCount++;
    }

    void subEndCount() {
        endCount--;
    }

    int getStartWithCount() {
        return startWithCount;
    }

    void addStartEndCount() {
        startWithCount++;
    }

    void subStartEndCount() {
        startWithCount--;
    }
};

class Trie{
  private:
    Node* root;

  public:
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* head = root;
        for(auto it: word) {
            if(!head->getNode(it)) head->setNode(it);
            head = head->getNode(it);
            head->addStartEndCount();
        }
        head->addEndCount();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* head = root;
        for(auto it: word) {
            if(!head->getNode(it)) return 0;
            head = head->getNode(it);
        }
        return head->getEndCount();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* head = root;
        for(auto it: word) {
            if(!head->getNode(it)) return 0;
            head = head->getNode(it);
        }
        return head->getStartWithCount();
    }

    void erase(string &word){
        // Write your code here.
        Node* head = root;
        for(auto it: word) {
            head = head->getNode(it);
            head->subStartEndCount();
        }
        head->subEndCount();
    }
};

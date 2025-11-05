#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* tempHead = head;
        while(tempHead!=NULL) {
            Node* newNode = new Node(tempHead->val);
            newNode->next = tempHead->next;
            tempHead->next = newNode;
            tempHead = newNode->next;
        }
        tempHead = head;
        while(tempHead!=NULL) {
            if(tempHead->random) tempHead->next->random = tempHead->random->next;
            tempHead = tempHead->next->next;
        }
        Node* ans = head->next;
        Node* main = head;
        Node* copy = head->next;
        while(main!=NULL) {
            main->next = copy->next;
            main = main->next;
            if(copy->next) copy->next = copy->next->next;
            copy = copy->next;
        }
        return ans;
    }
};
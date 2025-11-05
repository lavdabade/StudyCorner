#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* tempHead = head;
        while(tempHead != NULL) {
            if(tempHead->child) {
                Node* child = flatten(tempHead->child);
                Node* childEnd = child;
                while(childEnd->next != NULL) {
                    childEnd = childEnd->next;
                }
                if(tempHead->next) tempHead->next->prev = childEnd;
                childEnd->next = tempHead->next;
                tempHead->child->prev = tempHead;
                tempHead->next = tempHead->child;
                tempHead->child = NULL;
            }
            tempHead = tempHead->next;
        }
        return head;
    }
};
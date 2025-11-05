#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* insertPos = head;
        Node* checkPos = head;
        while(checkPos!=NULL) {
            if(checkPos->data == insertPos->data) {
                checkPos = checkPos->next;
                continue;
            }
            else {
                insertPos->next = checkPos;
                checkPos->prev = insertPos;
                insertPos = insertPos->next;
                checkPos = checkPos->next;
            }
        }
        insertPos->next = NULL;
        return head;
    }
};
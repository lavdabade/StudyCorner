#include<iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution {
  public:
    Node* findIntersection(Node *firstHead, Node *secondHead)
    {
        //Write your code here
        Node* first = firstHead;
        Node* second = secondHead;
        bool firstNull = false;
        bool secondNull = false;
        while(first!=NULL && second!=NULL) {
            first = first->next;
            if(first == NULL && (!firstNull)) {
                first = secondHead;
                firstNull = true;
            }
            second = second->next;
            if(second == NULL && (!secondNull)) {
                second = firstHead;
                secondNull = true;
            }
            if(first == second) return first;
        }
        return NULL;
    }
};

#include<iostream>
#include<vector>

using namespace std;

class Node
{
  public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>> ans;
        Node* front = head;
        Node* back = head;
        while(back->next!=NULL) back = back->next;
        while(front!=back && front->data < back->data) {
            if(front->data + back->data == target) {
                ans.push_back({front->data, back->data});
                front = front->next;
                back = back->prev;
            }
            else if(front->data + back->data < target) {
                front = front->next;
            }
            else {
                back = back->prev;
            }
        }
        return ans;
    }
};
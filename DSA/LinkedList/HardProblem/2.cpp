#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            n++;
        }
        k %= n;
        if(k==0) return head;
        ListNode* prev = head;
        ListNode* next = head;
        while(k--) {
            next = next->next;
        }
        while(next->next!=NULL) {
            next = next->next;
            prev = prev->next;
        }
        next->next = head;
        head = prev->next;
        prev->next = NULL;
        return head;
    }
};
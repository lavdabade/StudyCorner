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
private:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* headPtr = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return headPtr;
    }

    ListNode* getKthNode(ListNode* node, int k) {
        while(--k && node!=NULL) {
            node = node->next;
        }
        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* ans = NULL;
        while(head) {
            ListNode* kth = getKthNode(head, k);
            if(kth == NULL) {
                if(prev==NULL) return head;
                prev->next = head;
                return ans;
            }
            ListNode* next = kth->next;
            kth->next = NULL;
            ListNode* rev = reverseList(head);
            if(ans == NULL) ans = rev;
            if(prev != NULL) prev->next = rev;
            prev = head;
            head = next;
        }
        return ans;
    }
};
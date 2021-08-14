#include <bits/stdc++.h>
#include <iostream>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy, *cur, *nex;
        int cnt = length(head);
        // continue till more than k groups left
        while(cnt>=k){
            // maintain the order [ pre->cur->nex ] 
            cur = pre->next;
            nex = cur->next;
            // reverse (k-1) links in the group
            for(int i = 1; i < k; ++i)
                reverseSingleLink(pre, cur, nex);
            cnt -= k;
            // to move to next group, pre will now be cur
            pre = cur;
        }
        return dummy->next;
    }
private:
    void reverseSingleLink(ListNode* &pre, ListNode* &cur, ListNode* &nex){
        // to move forward in the group
        nex = cur->next;
        // those three magical lines
        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
    }
    // to find the length of the list
    int length(ListNode* head){
        int cnt = 0;
        while(head){
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    
};

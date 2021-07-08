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
        int cnt = 0;
        ListNode* curr = head;
        while(curr){
            ++cnt;
            curr = curr->next;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy, *cur = dummy, *nex = dummy;
        // reverse the group only if more than equal to k nodes left
        while(cnt>=k){
            // before starting the next group reversal
            // maintain the sliding pointers, pre->cur->nex
            cur = pre->next;
            nex = cur->next;
            //reverse group of k, total k-1 links will be reversed
            for(int i=1; i<k; ++i){
                // before manipulating nex next, dont lose it
                cur->next = nex->next;
                // reverse one link
                nex->next = pre->next;
                // still couldn't get the intuition
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            cnt-=k;
        }
        return dummy->next;
    }
};
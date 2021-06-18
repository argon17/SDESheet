#include <bits/stdc++.h>
#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tmp = dummy;
        int carry = 0;
        // pretty straight forward
        while(l1!=NULL || l2!=NULL || carry){
            int s = 0;
            if(l1!=NULL){
                s += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                s += l2->val;
                l2 = l2->next;
            }
            s += carry;
            carry = s/10;
            ListNode* node = new ListNode(s%10);
            tmp->next = node;
            tmp = tmp->next;
        }
        // at dummy it was default 0, we keep appending nodes to dummy
        // eg : 5->2->3 & 2->9, ans will be 0->7->1->4
        // need to return 7, hence dummy->next
        return dummy->next;
    }
};
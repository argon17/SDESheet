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
        // reverse k-1 links in each group of k
        while(cnt >= k){
            cur = pre->next;
            nex = cur->next;
            for(int i = 1; i < k; ++i)
                reverseSingleLink(pre, cur, nex);
            cnt -= k;
            pre = cur;
        }
        return dummy->next;
    }
private:
    void reverseSingleLink(ListNode* &pre, ListNode* &cur, ListNode* &nex){
        nex = cur->next;
        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
    }
    int length(ListNode* head){
        int cnt = 0;
        while(head){
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    
};

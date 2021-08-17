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

// 4->5 & 3->4->5 = 3->9->0

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* a = reverse(first);
        Node* b = reverse(second);
        Node* dummy = new Node(0), *cur = dummy;
        int carry = 0;
        while(a || b || carry){
            int s = 0;
            if(a) s += a->data, a = a->next;
            if(b) s += b->data, b = b->next;
            s += carry;
            carry = s/10;
            Node* tmp = new Node(s%10);
            cur->next = tmp;
            cur = cur->next;
        }
        Node* ans = reverse(dummy->next);
        return ans;
    }
    private:
    struct Node* reverse(struct Node* head){
        Node* p = head, *q = NULL, *r = NULL;
        while(p){
            r = q;
            q = p;
            p = p->next;
            q -> next = r;
        }
        return q;
    }
};

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if(head == NULL || head -> next == NULL) return true;
    ListNode *slow = head, *fast = head;
    // find the middle (1 2 3 2 1) => 3; (1 2 3 1) => 2
    while (fast->next && fast->next->next)
        slow = slow->next, fast = fast->next->next;
    // reverse after the middle (1 2 3 2 1) => (1 2 3 1 2); (1 2 3 1) => (1 2 1 3)
    slow->next = reverseList(slow->next);
    // now check for palindrome from slow->next and head
    ListNode* dummy = head;
    slow = slow->next;
    while(slow){
        if(slow->val != dummy->val) return false;
        slow = slow -> next;
        dummy = dummy -> next;
    }
    // slow reached to end(everything matched), return true
    return true;
}
ListNode* reverseList(ListNode* head){
    ListNode* p = head;
    ListNode* q = nullptr;
    ListNode* r = nullptr;
    while(p != nullptr ){

        // sliding pointers ... r -> q -> p ...
        r = q;
        q = p;
        p = p -> next;

        // reverse the link
        q -> next = r;
    }
    // return the head
    return q;
}
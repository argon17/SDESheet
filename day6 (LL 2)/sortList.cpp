#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(NlogN) TC and O(N) SC
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head)
            return NULL;
        head = mergeSort(head);
        return head;
    }
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *s = head, *f = head;
        while (f->next && f->next->next)
        {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }

    ListNode *mergeSort(ListNode *head)
    {
        if (!head->next)
            return new ListNode(head->val);
        ListNode *mid = findMiddle(head);
        ListNode *sh = mergeSort(mid->next);
        mid->next = NULL;
        ListNode *fh = mergeSort(head);
        return merge(fh, sh);
    }

    ListNode *merge(ListNode *fh, ListNode *sh)
    {
        ListNode *temp = new ListNode(), *dummy = temp;
        while (fh && sh)
        {
            if (fh->val <= sh->val)
                temp->next = new ListNode(fh->val), fh = fh->next;
            else
                temp->next = new ListNode(sh->val), sh = sh->next;
            temp = temp->next;
        }
        if (fh)
            temp->next = fh;
        if (sh)
            temp->next = sh;
        return dummy->next;
    }
};
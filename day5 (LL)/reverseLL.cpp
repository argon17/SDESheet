
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // maintain three pointers
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
};
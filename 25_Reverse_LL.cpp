class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)    return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw ;

        while(curr){
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
};
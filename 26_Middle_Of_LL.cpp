class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
            if(fast -> next)    fast = fast -> next;
        }

        return slow;
    }
};
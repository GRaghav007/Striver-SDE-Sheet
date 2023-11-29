class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)    return false;
        ListNode* slow = head, *fast = head;
        while(slow && fast){
            slow = slow -> next;
            fast = fast -> next;
            if(fast && fast -> next){    fast = fast -> next;
                if(slow == fast)    return true;
            }
        }

        return false;
    }
};
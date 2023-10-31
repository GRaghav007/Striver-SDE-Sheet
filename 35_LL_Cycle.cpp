class Solution {    

public:
    ListNode *detectCycle(ListNode *head) { 
        if(head == NULL)
            return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        bool x = false;
        while(fast != NULL && slow != NULL){
            fast = fast -> next;
            while(fast != NULL)
                fast = fast -> next;
            slow = slow -> next;
            if(slow == fast){
                x = true;
                break;
            }
        }
        if(!x)
            return NULL;
            slow = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
        return slow;
    }
};
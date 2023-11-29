class Solution {
private:
    ListNode* findMid(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = curr -> next;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL || head == NULL)    return true;
        ListNode* mid = findMid(head); 
        mid -> next = reverse(mid -> next); 
        ListNode* head1 = head;
        ListNode* head2 = mid -> next;
        while(head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};
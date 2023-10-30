/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:

    ListNode* insert(ListNode* l1, int data){
        ListNode* temp = new ListNode(data);
        if(l1 == NULL){
            l1 = temp;
        }
        else{
            ListNode* x1 = l1;
            while(x1 -> next != NULL){
                x1 = x1 -> next;
            }
            x1 -> next = temp;
        }

        return l1;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* ans = NULL;
        int sum = 0, carry = 0;
        while(head1 != NULL && head2 != NULL){
            sum = head1 -> val + head2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans = insert(ans, sum);
            head1 = head1 -> next;
            head2 = head2 -> next;
        }

        while(head1 != NULL){
            sum = head1 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans = insert(ans, sum);
            head1 = head1 -> next;
        }

        while(head2 != NULL){
            sum = head2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans = insert(ans, sum);
            head2 = head2 -> next;
        }

        while(carry != 0){
            sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            ans = insert(ans, sum);
        }

        // ans = reverse(ans);
        return ans; 
    }
};
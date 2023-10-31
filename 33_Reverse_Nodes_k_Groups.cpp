class Solution {
private:
    void rev(ListNode* &x, ListNode* &y){
        if(x == NULL || x -> next == NULL)  return;
        y = x;
        ListNode* prev = NULL, *forw = x -> next;
        while(x){
            x -> next = prev;
            prev = x;
            x = forw;
            if(x)forw = x -> next;
        }
        x = prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)    return head;

        ListNode* x = head, *y = head;
        int cnt = 1;
        while(cnt < k && y -> next){
            y = y -> next;
            cnt++;
        }
        if(cnt != k)    return head;
        else{
            ListNode* z = y -> next;
            y -> next = NULL;
            rev(x, y);
            y -> next = reverseKGroup(z, k);
        }
        return x;
    }
};
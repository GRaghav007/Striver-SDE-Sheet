class Solution {
private:
    int findLength(ListNode* head){
        ListNode* x = head;
        int cnt = 0;
        while(x){
            x = x -> next;
            cnt++;
        }

        return cnt;
    }

    ListNode* makeList(ListNode* &head, ListNode* newL, int pos){
        ListNode* y;
        y = new ListNode(head -> val);
        head = head -> next;
        newL = y;
        int cnt = 1;
        while(cnt < pos){
            y -> next = new ListNode(head -> val);
            cnt++;
            head = head -> next;
            y = y -> next;
        }

        return newL;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)    return head;
        int len = findLength(head);
        k %= len;
        if(k == 0)  return head;

        ListNode* newL = makeList(head, newL, len-k);

        ListNode* tail = head;
        while(tail -> next != NULL) tail = tail -> next;

        tail -> next = newL;

        return head;
    }
};
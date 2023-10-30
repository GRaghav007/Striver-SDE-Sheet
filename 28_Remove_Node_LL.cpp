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
private:
    int len(ListNode* head){
        if(head == NULL)    return 0;
        ListNode* x = head;
        int cnt = 1;
        while(x -> next){
            x = x -> next;
            cnt++;
        }

        return cnt;
    }
    
    void del(ListNode* &head, int pos){
        if(pos == 1)    head = head -> next;
        else{int cnt = 1;
        ListNode* x = head;

        while(cnt < pos - 1 && x){
            x = x -> next;
            cnt++;
        }

        if(x -> next -> next)x -> next = x -> next -> next;
        else    x -> next = NULL;}
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = len(head);
        if(length == n && n == 1)   return NULL;
        int pos = length - n + 1;
        del(head, pos);

        return head;
    }
};
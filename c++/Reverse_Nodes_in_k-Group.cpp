/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head||!k) {
            return head;
        }
        ListNode *start=new ListNode(0);
        start->next=head;
        ListNode *prev=start;
        int i=0;
        while(head) {
            head=head->next;
            i++;
            if(i==k) {
                ListNode *last=prev->next;
                ListNode *cur=last->next;
                while(cur!=head) {
                    last->next=cur->next;
                    cur->next=prev->next;
                    prev->next=cur;
                    cur=last->next;
                }
                prev=last;
                i=0;
            }
        }
        head=start->next;
        delete start;
        return head;
    }
};
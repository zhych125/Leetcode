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
    ListNode *swapPairs(ListNode *head) {
        if(!head) {
            return head;
        }
        ListNode* start=new ListNode(0);
        start->next=head;
        head = start;
        while(head->next&&head->next->next) {
            ListNode* current=head->next;
            ListNode* next=head->next->next;
            current->next=next->next;
            head->next=next;
            next->next=current;
            head=head->next->next;
        }
        head=start->next;
        delete start;
        return head;
    }
};
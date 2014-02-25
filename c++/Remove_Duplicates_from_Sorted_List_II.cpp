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
    ListNode *deleteDuplicates(ListNode *head) {
       if(!head) {
           return head;
       }
       ListNode* start=new ListNode(0);
       start->next=head;
       ListNode* prev=start;
       bool duplicate=false;
       while(head->next) {
           if(head->next->val==head->val) {
               duplicate=true;
               head->next=head->next->next;
           }
           else if(duplicate) {
               prev->next=head->next;
               head=head->next;
               duplicate=false;
           }
           else {
               prev=prev->next;
               head=head->next;
           }
       }
       if(duplicate) {
           prev->next=head->next;
       }
       return start->next;
    }
};
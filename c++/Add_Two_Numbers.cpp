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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        int carry=0;
        ListNode *start = new ListNode(0);
        ListNode *head = start;
        while(l1!=NULL&&l2!=NULL) {
            head->next = new ListNode((l1->val+l2->val+carry)%10);
            head = head->next;
            carry = (l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        ListNode *l;
        if(l1!=NULL) {
            l=l1;
        }
        else {
            l=l2;
        }
        while(l!=NULL) {
                head->next = new ListNode((l->val+carry)%10);
                head = head->next;
                carry = (l->val+carry)/10;
                l=l->next;
        }
        if(carry) {
            head->next = new ListNode(1);
        }
        head = start->next;
        delete start;
        return head;
    }
};
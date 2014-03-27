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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL) {
            return head;
        }
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode *node = start;
        for(int i=1;i<m;i++) {
            node = node -> next;            
        }
        ListNode* prev = node;
        node = node->next;
        int i = m;
        for(int i=m;i<n;i++) {
            ListNode *next = node->next;
            node->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        head = start->next;
        delete start;
        return head;
    }
};
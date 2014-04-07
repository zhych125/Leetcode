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
    void reorderList(ListNode *head) {
        if(head==NULL) {
            return;
        }
        ListNode *node=head;
        int len=0;
        while(node) {
            len++;
            node=node->next;
        }
        node=head;
        reorderHelper(node,len);
        return;
    }
    ListNode *reorderHelper(ListNode *&head,int len) {
        if(len==0) {
            return NULL;
        }
        if(len==1) {
            ListNode *node=head;
            head=head->next;
            node->next=NULL;
            return node;
        }
        ListNode *node=head;
        head=head->next;
        ListNode *next=reorderHelper(head,len-2);
        node->next=head;
        head=head->next;
        node->next->next=next;
        return node;
    }
};
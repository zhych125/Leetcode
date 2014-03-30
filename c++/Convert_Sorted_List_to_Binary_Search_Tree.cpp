/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL) {
            return NULL;
        }
        ListNode* node = head;
        int len=1;
        while(node->next!=NULL) {
            node = node->next;
            len++;
        }
        return listToBSTHelper(head,len);
    }
private:
    TreeNode* listToBSTHelper(ListNode *&head, int len) {
        if(len==0) {
            return NULL;
        }
        TreeNode *left = listToBSTHelper(head,len/2);
        TreeNode *node = new TreeNode(head->val);
        node->left = left;
        head = head->next;
        node->right = listToBSTHelper(head,len-len/2-1);
        return node;
    }
    
};
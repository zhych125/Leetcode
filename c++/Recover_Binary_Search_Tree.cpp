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
    void recoverTree(TreeNode *root) {
        if(root==NULL) {
            return;
        }
        TreeNode *n1=NULL,*n2=NULL,*prev=NULL;
        recoverHelper(root,n1,n2,prev);
        swap(n1,n2);
        
    }
    void recoverHelper(TreeNode *root, TreeNode* &n1, TreeNode* &n2, TreeNode* &prev) {
        if(!root) {
            return;
        }
        recoverHelper(root->left,n1,n2,prev);
        if(prev&&prev->val>=root->val) {
            if(!n1) {
                n1=prev;
            }
            n2=root;
        }
        prev=root;
        recoverHelper(root->right,n1,n2,prev);
    }
    void swap(TreeNode *n1,TreeNode *n2) {
        int temp=n1->val;
        n1->val=n2->val;
        n2->val=temp;
    }
};
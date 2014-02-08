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
    bool isSymmetric(TreeNode *root) {
        if(!root) {
            return true;
        }
        return isSymHelper(root->left,root->right);
    }
    bool isSymHelper(TreeNode *left, TreeNode *right) {
        if(!left) {
            return !right;
        }
        if(!right) {
            return false;
        }
        if(left->val==right->val) {
            return isSymHelper(left->left,right->right)&&isSymHelper(left->right,right->left);
        }
        return false;
    }
};
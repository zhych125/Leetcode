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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) {
            return false;
        }
        return pathHelper(root,sum);
    }
    bool pathHelper(TreeNode *root, int sum) {
        sum=sum-root->val;
        if(root->left==NULL&&root->right==NULL) {
            if(sum==0) {
                return true;
            } else {
                return false;
            }
        } else {
            if(root->left) {
                if(pathHelper(root->left,sum)) {
                    return true;
                }
            }
            if(root->right) {
                if(pathHelper(root->right,sum)) {
                    return true;
                }
            }
            return false;
        }
    }
};
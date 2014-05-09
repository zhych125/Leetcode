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
    bool isValidBST(TreeNode *root) {
        return validHelper(root,false,false,0,0);
    }
    bool validHelper(TreeNode *root, bool maxValid,bool minValid,int maxValue,int minValue) {
        if (root==NULL) {
            return true;
        }
        if(maxValid) {
            if(root->val>=maxValue) {
                return false;
            }
        }
        if(minValid) {
            if(root->val<=minValue) {
                return false;
            }
        }
        if(validHelper(root->left,true,minValid,root->val,minValue)&&validHelper(root->right,maxValid,true,maxValue,root->val)) {
            return true;
        } else  {
            return false;
        }
    }
};
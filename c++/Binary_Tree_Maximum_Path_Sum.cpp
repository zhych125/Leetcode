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
    int maxPathSum(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        int maximum = root->val;
        maxPathHelper(root,maximum);
        return maximum;
    }
    int maxPathHelper(TreeNode *root, int& maximum) {
        if(root == NULL) {
            return 0;
        }
        int left = maxPathHelper(root->left,maximum);
        int right = maxPathHelper(root->right,maximum);
        int sum = root->val;
        if(left>0) {
            sum+=left;
        }
        if(right>0) {
            sum+=right;
        }
        if(sum>maximum) {
            maximum=sum;
        }
        return max(left,right)>0?root->val+max(left,right):root->val;
    }
};
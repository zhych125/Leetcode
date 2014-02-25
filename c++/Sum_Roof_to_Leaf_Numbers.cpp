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
    int sumNumbers(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int sum=0;
        sumHelper(root,sum,0);
        return sum;
        
    }
    void sumHelper(TreeNode *root, int &sum, int num) {
        num*=10;
        num+=root->val;
        if(root->left) {
            sumHelper(root->left,sum,num);
        }
        if(root->right) {
            sumHelper(root->right,sum,num);
        }
        if(!root->left&&!root->right) {
            sum+=num;
        }
    }
};
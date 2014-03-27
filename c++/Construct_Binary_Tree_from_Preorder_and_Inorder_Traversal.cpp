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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int index = 0;
        return buildHelper(preorder,inorder,index,0,preorder.size()-1);
    }
    TreeNode *buildHelper(vector<int> &preorder,vector<int> &inorder,int &index,int begin, int end) {
        if(begin>end) {
            return NULL;
        }
        for(int i=begin;i<=end;i++) {
            if(preorder[index]==inorder[i]) {
                TreeNode *root = new TreeNode(preorder[index]);
                index++;
                root->left = buildHelper(preorder,inorder,index,begin,i-1);
                root->right = buildHelper(preorder,inorder,index,i+1,end);
                return root;
            }
        }
    }
};
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty()||postorder.empty()) {
            return NULL;
        }
        int index=postorder.size()-1;
        int begin=0;
        int end = inorder.size()-1;
        return buildHelper(inorder,postorder,index,begin,end);
    }
    TreeNode *buildHelper(vector<int> &inorder,vector<int> &postorder,int &index,int begin, int end) {
        if(begin>end) {
            return NULL;
        }
        for(int i=begin;i<=end;i++) {
          if(inorder[i]==postorder[index]) {
              TreeNode *root=new TreeNode(postorder[index]);
              index--;
              root->right=buildHelper(inorder,postorder,index,i+1,end);
              root->left=buildHelper(inorder,postorder,index,begin,i-1);
              return root;
          }  
        }
    }
};
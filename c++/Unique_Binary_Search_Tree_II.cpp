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
    vector<TreeNode *> generateTrees(int n) {
        return genHelper(1,n);
    }
    vector<TreeNode *> genHelper(int begin,int end) {
        vector<TreeNode *> ret;
        if(begin>end) {
            ret.push_back(NULL);
            return ret;
        }
        for(int i=begin;i<=end;i++) {
            vector<TreeNode *> leftVector=genHelper(begin,i-1);
            vector<TreeNode *> rightVector=genHelper(i+1,end);
            for(int j=0;j<leftVector.size();j++) {
                for(int k=0;k<rightVector.size();k++) {
                    TreeNode *node=new TreeNode(i);
                    node->left=leftVector[j];
                    node->right=rightVector[k];
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
};
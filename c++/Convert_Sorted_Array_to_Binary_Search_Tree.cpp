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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty()) {
            return NULL;
        }
        int length=num.size();
        int index=0;
        return aToB(num,index,length);
    }
    TreeNode* aToB(vector<int> &num, int &index, int length) {
        if(length==0) {
            return NULL;
        }
        TreeNode* left=aToB(num,index,length/2);
        TreeNode* root=new TreeNode(num[index]);
        index++;
        root->left=left;
        root->right=aToB(num,index,length-length/2-1);
        return root;
    }
};
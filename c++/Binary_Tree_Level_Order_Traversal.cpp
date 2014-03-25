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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(root==NULL) {
            return ret;
        }
        list<TreeNode *> level[2];
        level[0].push_back(root);
        while(level[0].size()||level[1].size()) {
            vector<int> levelList;
            int i;
            if(level[0].size()) {
                i=0;
            } else {
                i=1;
            }
            while(level[i].size()) {
                TreeNode *node=level[i].front();
                level[i].pop_front();
                levelList.push_back(node->val);
                if(node->left) {
                    level[(i+1)%2].push_back(node->left);
                }
                if(node->right) {
                    level[(i+1)%2].push_back(node->right);
                }
            }
            ret.push_back(levelList);
        }
        return ret;
    }
};
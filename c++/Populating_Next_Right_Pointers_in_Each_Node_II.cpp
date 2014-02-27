/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) {
            return;
        }
        TreeLinkNode *node=NULL;
        if(root->left) {
            root->left->next=root->right;
            node=root->left;
        }
        if(root->right) {
            node=root->right;
        }
        if(!node) {
            return;
        }
        TreeLinkNode *upNode=root;
        while(upNode->next) {
            if(upNode->next->left) {
                node->next=upNode->next->left;
                break;
            }
            else if(upNode->next->right) {
                node->next=upNode->next->right;
                break;
            }
            else {
                upNode=upNode->next;
            }
        }
        connect(root->right);
        connect(root->left);
    }
};
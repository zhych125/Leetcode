# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        def helper(root):
            if root is None:
                return 0
            return max(helper(root.left),helper(root.right))+1
        return helper(root)
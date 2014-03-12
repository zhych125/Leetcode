# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        lists=[]
        if root is None:
            return lists
        queue1=[]
        queue2=[]
        queue1.append(root)
        while len(queue1) is not 0:
            list=[]
            for i in queue1:
                list.append(i.val);
                if i.left is not None:
                    queue2.append(i.left)
                if i.right is not None:
                    queue2.append(i.right)
            lists.append(list)
            list=[]
            queue1=[]
            if len(queue2) is not 0:
                for i in queue2:
                    list.append(i.val)
                    if i.left is not None:
                        queue1.append(i.left)
                    if i.right is not None:
                        queue1.append(i.right)
                lists.append(list)
                list=[]
                queue2=[]
        return lists
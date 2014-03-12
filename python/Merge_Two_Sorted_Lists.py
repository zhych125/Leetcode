# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        start=ListNode(0)
        list=start
        while l1 is not None and l2 is not None:
            if l1.val<l2.val:
                list.next=l1
                l1=l1.next
                list=list.next
            else:
                list.next=l2
                l2=l2.next
                list=list.next
        if l1 is not None:
            list.next=l1
        if l2 is not None:
            list.next=l2
        return start.next
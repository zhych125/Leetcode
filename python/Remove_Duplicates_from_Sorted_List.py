# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head is None:
            return head
        start=head
        while head.next is not None:
            if head.val==head.next.val:
                head.next=head.next.next
            else:
                head=head.next
        return start
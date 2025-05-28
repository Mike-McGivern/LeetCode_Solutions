# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        for _ in range(left - 1):
            if prev.next:
                prev = prev.next
        
        current = prev.next
        for _ in range(right - left):
            if not current or not current.next:
                break
            nextNode = current.next
            current.next = nextNode.next
            nextNode.next = prev.next
            prev.next = nextNode
        return dummy.next

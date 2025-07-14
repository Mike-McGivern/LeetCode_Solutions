# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        arr = []
        result = 0
        while head != None:
            arr.append(head.val)
            head = head.next
        count = len(arr) - 1
        for val in arr:
            if val == 0:
                count -= 1
            elif val == 1:
                result += 2 ** count
                count -= 1
        return result

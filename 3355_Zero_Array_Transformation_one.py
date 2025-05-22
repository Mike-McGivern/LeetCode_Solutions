from typing import List
class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        d = [0] * (n + 1)
        for l, r in queries:
            d[l] += 1
            d[r + 1] -= 1
        
        s = 0
        for i in range(n):
            s += d[i]
            if nums[i] > s:
                return False
        
        return True

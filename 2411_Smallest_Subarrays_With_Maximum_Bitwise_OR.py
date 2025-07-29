from typing import List
class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n
        lastSeen = [-1] * 32

        for i in reversed(range(n)):
            maxLen = 1
            for bit in range(32):
                if (nums[i] >> bit) & 1:
                    lastSeen[bit] = i
                elif lastSeen[bit] != -1:
                    maxLen = max(maxLen, lastSeen[bit] - i + 1)
            result[i] = maxLen
        
        return result

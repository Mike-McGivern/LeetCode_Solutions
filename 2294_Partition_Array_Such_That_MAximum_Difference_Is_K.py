from typing import List
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        partitions = 1
        minVal = nums[0]

        for num in nums:
            if num - minVal > k:
                partitions += 1
                minVal = num
        
        return partitions

from typing import List
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        maxOr = 0
        for num in nums:
            maxOr |= num
        
        self.count = 0

        def dfs(index: int, currentOr: int):
            if index == len(nums):
                if currentOr == maxOr:
                    self.count += 1
                
                return;
            dfs(index + 1, currentOr)

            dfs(index + 1, currentOr | nums[index])
        dfs(0,0)
        return self.count

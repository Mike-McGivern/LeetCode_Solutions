class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        maxDiff = 0 
        for i in range(len(nums)):
            if i == len(nums):
                comp = abs(nums[i] - nums[0])
                if comp > maxDiff:
                    maxDiff = comp
            if abs(nums[i - 1] - nums[i]) > maxDiff:
                maxDiff = abs(nums[i - 1] - nums[i])
        return maxDiff

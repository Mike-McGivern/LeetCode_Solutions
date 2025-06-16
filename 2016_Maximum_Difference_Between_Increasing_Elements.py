class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        maxDiff = -1
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if nums[j] - nums[i] > maxDiff:
                    maxDiff = nums[j] - nums[i]
        if maxDiff == 0:
            maxDiff = -1
        return maxDiff

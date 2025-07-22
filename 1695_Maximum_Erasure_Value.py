class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        seen = set()
        left = total = maxTotal = 0
        for right in range(len(nums)):
            while nums[right] in seen:
                seen.remove(nums[left])
                total -= nums[left]
                left += 1
            seen.add(nums[right])
            total += nums[right]
            maxTotal = max(maxTotal, total)
        
        return maxTotal

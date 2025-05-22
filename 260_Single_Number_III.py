class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        a_xor_b = 0
        for num in nums:
            a_xor_b ^= num

        # Get the rightmost significant bit (mask)
        mask = a_xor_b & (~(a_xor_b - 1))

        result = [0, 0]
        for num in nums:
            if num & mask == 0:
                result[0] ^= num
            else:
                result[1] ^= num

        return result

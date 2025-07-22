class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        from math import log2, ceil

        opsCount = ceil(log2(k))
        shift = 0

        for i in reversed(range(opsCount)):
            half = 1 << i
            if k > half:
                k -= half
                shift += operations[i]

        return chr((ord('a') + shift % 26))

class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        def calc(a: str, b: str) -> int:
            maxDist = curr = changes = 0
            for ch in s:
                if ch == a or ch == b:
                    curr += 1
                elif changes < k:
                    changes += 1
                    curr += 1
                else:
                    curr -= 1
                maxDist = max(maxDist, curr)
            return maxDist
        return max(calc('N', 'E'), calc('N', 'W'), calc('S', 'E'), calc('S', 'W'))
        

class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def countSteps(curr, n):
            steps = 0
            first = curr
            last = curr
            while first <= n:
                steps += min(last, n) - first + 1
                first *= 10
                last = last * 10 + 9
            
            return steps

        curr = 1
        k -= 1
        while k > 0:
            steps = countSteps(curr, n)
            if steps <= k:
                k -= steps
                curr += 1
            else:
                curr *= 10
                k -= 1
        return curr

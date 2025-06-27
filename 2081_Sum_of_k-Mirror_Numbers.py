class Solution:
    def kMirror(self, k: int, n: int) -> int:
        def isPalindrome(s: str) -> bool:
            return s == s[::-1]
        
        def toBaseK(num: int, base: int) -> str:
            res = ''
            while num > 0:
                res = str(num % base) + res
                num //= base
            return res

        def generatePalindromes():
            length = 1
            while True:

                for half in range(10 **(length - 1), 10**length):
                    s = str(half)
                    yield int(s + s[-2::-1])

                for half in range(10**(length - 1), 10**length):
                    s = str(half)
                    yield int(s + s[::-1])
                length += 1

        count = 0
        total = 0  
        for num in generatePalindromes():
            if isPalindrome(toBaseK(num, k)):
                total += num
                count += 1
                if count == n:
                    break
        return total 

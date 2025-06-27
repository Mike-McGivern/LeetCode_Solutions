from collections import Counter
class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        frequencies = Counter(word).values()

        def deletionsNeeded(threshold: int) -> int:
            deletions = 0
            for freq in frequencies:
                if freq < threshold:
                    deletions += freq
                elif freq > threshold + k:
                    deletions += freq - threshold - k
            return deletions

        return min(deletionsNeeded(v) for v in range(len(word) + 1))

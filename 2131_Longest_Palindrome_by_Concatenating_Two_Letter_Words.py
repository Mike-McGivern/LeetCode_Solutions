from collections import Counter
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        word_count = Counter(words)
        palindrome_length = 0
        central_word_used = False

        for word, count in word_count.items():
            # Case 1: The word is a palindrome itself (e.g., "aa", "bb")
            if word[0] == word[1]:
                if count % 2 == 0:
                    palindrome_length += count * 2
                else:
                    palindrome_length += (count - 1) * 2
                    central_word_used = True
            else:
                # Case 2: The word has a reverse counterpart (e.g., "ab" and "ba")
                reverse_word = word[::-1]
                if reverse_word in word_count:
                    pairs = min(count, word_count[reverse_word])
                    palindrome_length += pairs * 4
                    word_count[reverse_word] = 0  # Avoid double counting

        # Add a central palindrome word if available
        if central_word_used:
            palindrome_length += 2

        return palindrome_length

from collections import Counter

class Solution:
    def robotWithString(self, s: str) -> str:
        # Counter to keep track of how many of each character are left in the string
        char_count = Counter(s)
      
        # Output list to store the characters for the final result
        result = []
      
        # Stack to simulate the robot's hand
        stack = []
      
        # Variable to keep track of the smallest character not exhausted in the string
        min_char = 'a'
      
        # Iterate over the characters in the string
        for char in s:
            # Decrement the count for the current character
            char_count[char] -= 1
          
            # Update the smallest character ('min_char') if the current one runs out
            while min_char < 'z' and char_count[min_char] == 0:
                min_char = chr(ord(min_char) + 1)
              
            # Append the current character to the stack (robot's hand)
            stack.append(char)
          
            # Append characters to the result from the stack if they are smaller
            # or equal to 'min_char'. This ensures the lexicographically smallest
            # result possible at each step.
            while stack and stack[-1] <= min_char:
                result.append(stack.pop())
      
        # Join the list of characters to form the final string result
        return ''.join(result)

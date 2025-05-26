class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        toReturn = []
        for word in range(0, len(words)):
            for char in range(0, len(words[word])):
                if (words[word])[char:char+1] == x:
                    toReturn.append(word)
                    break
        return toReturn

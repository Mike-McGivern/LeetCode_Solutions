class Solution {

  /**
   * Calculates the maximum score achievable by forming words from the given letters.
   *
   * @param words   An array of words to be considered for scoring.
   * @param letters An array of letters available to form words.
   * @param score   An array representing the score for each alphabet letter.
   * @return The maximum score achievable.
   */
  public int maxScoreWords(String[] words, char[] letters, int[] score) {
    // Keep track of letter counts in the given letters array.
    int[] letterCounts = new int[26];
    for (char letter : letters) {
      // Increment the count for encountered letter.
      letterCounts[letter - 'a']++;
    }

    int wordCount = words.length;
    int maxScore = 0; // Keep track of the maximum score.

    // Loop through each combination of words possible.
    for (int i = 0; i < (1 << wordCount); ++i) {
      int[] currentCount = new int[26]; // To hold the count for current combination.
      // Check each word in the current combination.
      for (int j = 0; j < wordCount; ++j) {
        if (((i >> j) & 1) == 1) { // Check if the j-th word is included.
          for (char c : words[j].toCharArray()) {
            currentCount[c - 'a']++; // Count the characters for the word.
          }
        }
      }

      // Verify if current combination can be made from available letters.
      boolean isCombinationValid = true;
      int currentScore = 0;
      for (int j = 0; j < 26; ++j) {
        if (currentCount[j] > letterCounts[j]) { // More letters required than available.
          isCombinationValid = false;
          break;
        }
        currentScore += currentCount[j] * score[j]; // Accumulate score for the current combination.
      }

      // Update maxScore if this combination is valid and its score is higher.
      if (isCombinationValid && maxScore < currentScore) {
        maxScore = currentScore;
      }
    }

    // Return the maximum score after evaluating all combinations.
    return maxScore;
  }
}

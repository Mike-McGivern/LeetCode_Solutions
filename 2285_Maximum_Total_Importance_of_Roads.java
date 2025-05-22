class Solution {
  
    // Function to calculate the maximum importance of the city network
    public long maximumImportance(int n, int[][] roads) {
        // Array to store the degree (number of roads) of each city
        int[] degree = new int[n];
      
        // Increment the degree for both cities involved in each road
        for (int[] road : roads) {
            ++degree[road[0]];
            ++degree[road[1]];
        }
      
        // Sort the array to process cities with smaller degrees first
        Arrays.sort(degree);
      
        // Initialize answer to calculate the sum of importances
        long answer = 0;
      
        // Assign importance values to cities. The importance starts from 1 and goes up to n.
        // The cities with the smallest degrees get the smallest importance values.
        for (int i = 0; i < n; ++i) {
            // Calculate importance for current city and add it to the answer.
            // Importance is calculated by multiplying the city's degree with its importance value.
            answer += (long) (i + 1) * degree[i];
        }
      
        // Return the total importance for all cities
        return answer;
    }
}

import java.util.Arrays;

public class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[1] - b[1]);
        int n = events.length;
        int[] dp = new int[n];
        dp[0] = events[0][2];
        
        for (int i = 1; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], events[i][2]);
        }
        
        int maxSum = dp[n - 1];
        
        for (int i = 0; i < n; i++) {
            int left = 0, right = i - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < events[i][0]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (right >= 0) {
                maxSum = Math.max(maxSum, events[i][2] + dp[right]);
            }
        }
        
        return maxSum;
    }
}

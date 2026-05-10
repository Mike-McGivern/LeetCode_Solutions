class Solution {
    fun maximumJumps(nums: IntArray, target: Int): Int {
        val n = nums.size
        val dp = IntArray(n) { -1}
        dp[0] = 0

        for(i in 0 until n) {
            if(dp[i] == -1) continue
            for(j in i + 1 until n) {
                if(kotlin.math.abs(nums[j] - nums[i]) <= target) {
                    dp[j] = maxOf(dp[j], dp[i] + 1)
                }
            }
        }
        return dp[n - 1]
    }
}

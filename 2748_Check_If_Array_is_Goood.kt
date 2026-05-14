class Solution {
    fun isGood(nums: IntArray): Boolean {
        val n = nums.maxOrNull() ?: return false

        if(nums.size != n + 1) return false

        val freq = IntArray(n + 1)
        for(x in nums) {
            if(x > n) return false
            freq[x]++
        }

        for(i in 1 until n) {
            if(freq[i] != 1) return false
        }

        return freq[n] == 2
}
}

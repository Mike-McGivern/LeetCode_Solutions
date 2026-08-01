object Solution {
    def predictTheWinner(nums: Array[Int]): Boolean = {
        val n = nums.length
        val memo = Array.fill(n, n)(Int.MinValue)

        def scoreDiff(l: Int, r: Int): Int = {
            if(l == r) return nums(l)
            if(memo(l)(r) != Int.MinValue) return memo(l)(r)

            val pickLeft = nums(l) - scoreDiff(l + 1, r)
            val pickRight = nums(r) - scoreDiff(l, r - 1)

            memo(l)(r) = math.max(pickLeft, pickRight)
            memo(l)(r)
        }

        scoreDiff(0, n - 1) >= 0
    }
}

impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
        let max_sum: i64 = nums.iter().map(|&num| num.max(num ^ k) as i64).sum();
        let changed_count: i64 = nums.iter().map(|&num| ((num ^ k) > num) as i64).sum();

        if changed_count % 2 == 0 {
            return max_sum;
        } else {
            let min_change_diff = nums.iter()
                .map(|&num| (num - (num ^ k)).abs() as i64)
                .min()
                .unwrap_or(0);

            return max_sum - min_change_diff;
        }

    }
}

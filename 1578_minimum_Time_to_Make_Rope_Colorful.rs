impl Solution {
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
        let mut total_time = 0;
       let mut prev_char = colors.chars().next().unwrap();
       let mut prev_time = needed_time[0];

       for(i, c) in colors.chars().enumerate().skip(1) {
        if c == prev_char {
            total_time += prev_time.min(needed_time[i]);

            prev_time = prev_time.max(needed_time[i]);
        } else {
            prev_char = c;
            prev_time = needed_time[i];
        }
       }

       total_time
    }
}

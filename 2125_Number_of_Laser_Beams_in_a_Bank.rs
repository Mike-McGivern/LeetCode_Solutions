impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut prev_count = 0;
        let mut total_beams = 0;
        for row in bank {
            let curr_count = row.chars().filter(|&c| c == '1').count() as i32;
            if curr_count > 0 {
                total_beams += prev_count * curr_count;
                prev_count = curr_count;
            }
        }

        total_beams
    }
}

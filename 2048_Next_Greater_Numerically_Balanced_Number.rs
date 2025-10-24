impl Solution {
    pub fn next_beautiful_number(n: i32) -> i32 {
        fn is_balanced(mut num: i32) -> bool {
            let mut count = [0; 10];
            while num > 0 {
                let digit = (num % 10) as usize;
                if digit == 0 || digit > 9 {
                    return false;
                }
                count[digit] += 1;
                num /= 10;
            }

            for i in 1..10 {
                if count[i] != 0 && count[i] != i {
                    return false;
                }
            }
            true
        }

        let mut x = n + 1;
        while !is_balanced(x) {
            x += 1;
        }
        x
    }
}

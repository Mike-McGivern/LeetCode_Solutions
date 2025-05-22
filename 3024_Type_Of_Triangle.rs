impl Solution {
    pub fn triangle_type(nums: Vec<i32>) -> String {
        if(nums[0] + nums[1] <= nums[2] || nums[1] + nums[2] <= nums[0] || nums[0] + nums[2] <= nums[1]) {
            return "none".to_string();
        }
        else if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral".to_string();
        }
        else if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles".to_string();
        }
        else {
            return "scalene".to_string();
        }
    }
}

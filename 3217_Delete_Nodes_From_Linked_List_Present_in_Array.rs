// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::HashSet;
impl Solution {
    pub fn modified_list(nums: Vec<i32>, head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode {val: 0, next: head});
        let mut current = &mut dummy;
        let toDelete: HashSet<i32> = nums.into_iter().collect();

        while let Some(ref mut node) = current.next {
            if toDelete.contains(&node.val) {
                current.next = node.next.take();
            } else {
                current = current.next.as_mut().unwrap();
            }
        }

        dummy.next
    }
}

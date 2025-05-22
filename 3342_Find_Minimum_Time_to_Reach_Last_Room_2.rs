use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn min_time_to_reach(move_time: Vec<Vec<i32>>) -> i32 {
        let (n, m) = (move_time.len(), move_time[0].len());
        let mut dist = vec![vec![i32::MAX; m]; n];
        dist[0][0] = 0;
        let mut pq = BinaryHeap::new();
        pq.push(Reverse((0, 0, 0)));

        let dirs = [-1, 0, 1, 0, -1];

        while let Some(Reverse((d, i, j))) = pq.pop() {
            if i == n - 1 && j == m - 1 {
                return d;
            }
            if d > dist[i][j] {
                continue;
            }
            for k in 0..4 {
                let x = i as isize + dirs[k];
                let y = j as isize + dirs[k + 1];
                if x >= 0 && x < n as isize && y >= 0 && y < m as isize {
                    let x = x as usize;
                    let y = y as usize;
                    let t = std::cmp::max(move_time[x][y], dist[i][j]) + (i + j) as i32 % 2 + 1;
                    if dist[x][y] > t {
                        dist[x][y] = t;
                        pq.push(Reverse((t, x, y)));
                    }
                }
            }
        }
        -1 // Shouldn't reach here, but provides fallback.
    }
}

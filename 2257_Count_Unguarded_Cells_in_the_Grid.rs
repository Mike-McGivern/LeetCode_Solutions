use std::collections::HashSet;
impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let m = m as usize;
        let n = n as usize;
        let mut grid = vec![vec![0; n]; m];

        for wall in &walls {
            grid[wall[0] as usize][wall[1] as usize] = 1;
        }

        for guard in &guards {
            grid[guard[0] as usize][guard[1] as usize] = 2;
        }

        let directions = vec![(0, 1), (0, -1), (1, 0), (-1, 0)];

        for guard in &guards {
            let (r, c) = (guard[0] as usize, guard[1] as usize);
            for (dr, dc) in &directions {
                let mut nr = r as i32 + dr;
                let mut nc = c as i32 + dc;

                while nr >= 0 && nr < m as i32 && nc >= 0 && nc < n as i32 {
                    let (ur, uc) = (nr as usize, nc as usize);
                    if grid[ur][uc] == 1 || grid[ur][uc] == 2 {
                        break;
                    }
                    if grid[ur][uc] == 0 {
                        grid[ur][uc] = 3;
                    }

                    nr += dr;
                    nc += dc;
                }
            }
        }

        let mut count = 0;
        for r in 0..m {
            for c in 0..n {
                if grid[r][c] == 0 {
                    count += 1
                }
            }
        }
        count
    }
}

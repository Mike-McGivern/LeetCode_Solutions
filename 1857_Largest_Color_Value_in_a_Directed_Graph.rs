use std::collections::{VecDeque, HashMap};

impl Solution {
    pub fn largest_path_value(colors: String, edges: Vec<Vec<i32>>) -> i32 {
        let n = colors.len();
        let mut graph: Vec<Vec<usize>> = vec![vec![]; n];
        let mut in_degrees = vec![0; n];
        let mut queue = VecDeque::new();
        let mut count = vec![vec![0; 26]; n];

        // Build the graph.
        for edge in edges.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            graph[u].push(v);
            in_degrees[v] += 1;
        }

        // Perform topological sorting.
        for i in 0..n {
            if in_degrees[i] == 0 {
                queue.push_back(i);
            }
        }

        let mut processed = 0;
        let mut ans = 0;

        while let Some(out) = queue.pop_front() {
            processed += 1;
            let color_idx = colors.as_bytes()[out] as usize - b'a' as usize;
            count[out][color_idx] += 1;
            ans = ans.max(count[out][color_idx]);

            for &in_node in &graph[out] {
                for i in 0..26 {
                    count[in_node][i] = count[in_node][i].max(count[out][i]);
                }
                in_degrees[in_node] -= 1;
                if in_degrees[in_node] == 0 {
                    queue.push_back(in_node);
                }
            }
        }

        if processed == n {
            ans
        } else {
            -1
        }
    }
}

from itertools import product
class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        MOD = 1_000_000_007

    # Generate all valid column states
        def valid_columns(m):
            colors = [1, 2, 3]  # Red, Green, Blue
            return [col for col in product(colors, repeat=m) if all(col[i] != col[i-1] for i in range(1, m))]

        valid_cols = valid_columns(m)
        col_map = {col: i for i, col in enumerate(valid_cols)}
    
    # Fix: Transition dictionary must iterate through column pairs
        transitions = {col_map[c1]: [col_map[c2] for c2 in valid_cols if all(c1[i] != c2[i] for i in range(m))] for c1 in valid_cols}  

    # DP table with rolling array
        prev_dp = [1] * len(valid_cols)
    
        for _ in range(n - 1):
            curr_dp = [0] * len(valid_cols)
            for i in range(len(valid_cols)):
                for j in transitions[i]:
                    curr_dp[j] = (curr_dp[j] + prev_dp[i]) % MOD
            prev_dp = curr_dp  # Rolling array update

        return sum(prev_dp) % MOD

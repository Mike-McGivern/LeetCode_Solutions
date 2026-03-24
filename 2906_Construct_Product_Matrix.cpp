class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        int total = n * m;

        vector<int> flat(total);

        for(int i = 0, k = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                flat[k++] = grid[i][j] % MOD;
            }
        }
        vector<int> pref(total), suff(total);

        pref[0] = flat[0] % MOD;
        for(int i = 1; i < total; i++) {
            pref[i] = (pref[i - 1] * flat[i]) % MOD;
        }

        suff[total - 1] = flat[total - 1] % MOD;
        for(int i = total - 2; i>= 0; i--) {
            suff[i] = (suff[i + 1] * flat[i]) % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0, k = 0; i < n; i++) {
            for(int j = 0; j < m; j++, k++) {
                long long left = (k == 0 ? 1 : pref[k - 1]);
                long long right = (k == total - 1 ? 1 : suff[k + 1]);
                ans[i][j] = (left * right) % MOD;
            }
        }

        return ans;
    }
};

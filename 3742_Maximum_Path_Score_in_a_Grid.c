#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxPathScore(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];

    //allocate DP dp[m][n][k+1]
    int ***dp = (int***)malloc(m * sizeof(int**));
    for(int i = 0; i < m; i++) {
        dp[i] = (int**)malloc(n * sizeof(int*));
        for(int j = 0; j < n; j++) {
            dp[i][j] = (int*)malloc((k + 1) * sizeof(int));
            for(int c = 0; c <= k; c++)
                dp[i][j][c] = -1;
        }
    }

    //start cell 0, 0
    dp[0][0][0];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            int score = grid[i][j];
            int cost = (grid[i][j] == 0 ? 0 : 1);

            for(int c = cost; c <= k; c++) {
                int best = -1;

                if(i > 0 && dp[i-1][j][c - cost] != -1)
                    best = max(best, dp[i-1][j][c - cost] + score);

                if(j > 0 && dp[i][j - 1][c - cost] != -1)
                    best = max(best, dp[i][j-1][c - cost] + score);

                if(i == 0 & j == 0 && c == 0)
                    best = 0;

                dp[i][j][c] = max(dp[i][j][c], best);
            }
        }
    }
    int ans = -1;
    for(int c = 0; c <= k; c++) {
        ans = max(ans, dp[m-1][n-1][c]);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return ans;
}

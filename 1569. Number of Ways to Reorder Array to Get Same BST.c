#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

static long long comb[1001][1001];

void build_combinations(int n) {
    for(int i = 0; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }
}

long long countWays(int* nums, int size) {
    if(size <= 2) return 1;
    int root = nums[0];

    int* left = malloc(size * sizeof(int));
    int* right = malloc(size * sizeof(int));
    int lsize = 0, rsize = 0;

    for(int i = 1; i < size; i++) {
        if(nums[i] < root) left[lsize++] = nums[i];
        else right[rsize++] = nums[i];
    }

    long long leftWays = countWays(left, lsize);
    long long rightWays = countWays(right, rsize);

    free(left);
    free(right);

    long long ways = comb[lsize + rsize][lsize];
    ways = (ways * leftWays) % MOD;
    ways = (ways * rightWays) % MOD;

    return ways;
}

int numOfWays(int* nums, int numsSize) {
    build_combinations(numsSize);
    long long result = countWays(nums, numsSize);
    return (int)((result - 1 + MOD) % MOD);
}

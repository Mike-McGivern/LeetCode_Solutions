#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;
    
    int *nums = (int *)malloc(sizeof(int) * total);
    if(!nums) return -1; //simple guard

    int mod = grid[0][0] % x;
    int idx = 0;

    //flatten and check modulo condition
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] % x != mod) {
                free(nums);
                return -1;
            }
            nums[idx++] = grid[i][j];
        }
    }

    //sort flattened array
    qsort(nums, total, sizeof(int), cmpInt);

    //median as target
    int median = nums[total / 2];

    long long ops = 0;
    for(int i = 0; i < total; ++i) {
        long long diff = llabs((long long)nums[i] - (long long)median);
        ops += diff / x;
    }

    free(nums);
    return (int)ops;
}

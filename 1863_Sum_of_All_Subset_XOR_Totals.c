#include <stdio.h>

int subsetXORSum(int* nums, int numsSize){
    int sum = 0;
    int subsets = 1 << numsSize; // Total number of subsets is 2^n

    for (int i = 0; i < subsets; i++) {
        int XOR = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) { // If jth bit in the subset is set
                XOR ^= nums[j];
            }
        }
        sum += XOR;
    }

    return sum;
}

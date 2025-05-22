class Solution {
    public int subarraysDivByK(int[] A, int K) {
        int[] count = new int[K];
        count[0] = 1;
        int prefixSum = 0, res = 0;
        for (int a : A) {
            prefixSum = (prefixSum + a % K + K) % K;
            res += count[prefixSum]++;
        }
        return res;
    }
}

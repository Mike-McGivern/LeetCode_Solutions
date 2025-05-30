class Solution {
public:
    int kthFactor(int n, int k) {
        int factor = 1;
        int i = 0;
        for(; factor * factor < n; ++factor) {
            if(n % factor == 0 && ++i == k) {
                return factor;
            }
        }
        for(factor = n / factor; factor >= 1; --factor) {
            if(n % factor == 0 && ++i == k) {
            return n / factor;
            }
        }
        return -1;
    }
};

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int need = 1 << k;          // total number of binary codes of size k
        vector<bool> seen(need, false);
        int mask = need - 1;

        int hash = 0;

        // Build the first window
        for (int i = 0; i < k; i++) {
            hash = (hash << 1) | (s[i] - '0');
        }
        seen[hash] = true;
        int count = 1;

        // Slide the window
        for (int i = k; i < n; i++) {
            // Remove leftmost bit, add new bit
            hash = ((hash << 1) & mask) | (s[i] - '0');

            if (!seen[hash]) {
                seen[hash] = true;
                count++;
                if (count == need) return true;
            }
        }

        return count == need;
    }
};

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        for (int i = s.size() - 1; i > 0; --i) {
            ++steps;
            if (s[i] - '0' + carry == 1) {
                carry = 1;
                ++steps;
            }
        }
        return steps + carry;
    }
};

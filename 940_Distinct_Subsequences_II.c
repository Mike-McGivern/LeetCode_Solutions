#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int distinctSubseqII(char* s) {
    long long dp = 1;
    long long last[26];
    memset(last, 0, sizeof(last));

    for(int i = 0; s[i]; i++) {
        int c = s[i] - 'a';

        long long new_dp = (dp * 2 % MOD - last[c] + MOD) % MOD;

        last[c] = dp;
        dp = new_dp;
    }

    return (int)((dp - 1 + MOD) % MOD);
}

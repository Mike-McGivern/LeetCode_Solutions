#include <stdbool.h>
bool stoneGameIX(int* stones, int stonesSize) {
    int cnt[3] = {0, 0, 0};
    for(int i = 0; i < stonesSize; ++i) {
        cnt[stones[i] % 3]++;
    }

    if(cnt[1] == 0 && cnt[2] == 0) return false;

    int a = cnt[1], b = cnt[2], z = cnt[0];
   
   if(a == 0 && b == 0) return false;
   
   if(z % 2 == 0) {
    return (a > 0 && b > 0);
   } else {
    return (abs(a - b) >= 3);
   }
}

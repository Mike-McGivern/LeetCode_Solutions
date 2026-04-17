int reverse_int(int x) {
    int y = 0;
    while(x > 0) {
        y = y * 10 + x % 10;
        x /= 10;
    }

    return y;
}

typedef struct {
    int key;
    int val;
} Entry;

int minMirrorPairDistance(int* nums, int numsSize) {
    int n = numsSize;
    if(n <= 1) return -1;

    int cap = 1;
    while(cap < n * 2) cap <<= 1;
    Entry* table = (Entry*)malloc(sizeof(Entry) * cap);

    if(!table) return -1;

    for(int i = 0; i < cap; ++i) {
        table[i].key = 0;
        table[i].val = -1;
    }

    int ans = n + 1;

    for(int i = 0; i < n; ++i) {
        int x = nums[i];

        int h = x & (cap - 1);
        int idx = h;

        while(table[idx].key != 0) {
            if(table[idx].key == x) {
                int dist = i - table[idx].val;
                if(dist < ans) ans = dist;
                break;
            }

            idx = (idx + 1) & (cap - 1);
        }

        int rx = reverse_int(x);
        h = rx & (cap - 1);
        idx = h;
        while(table[idx].key != 0 && table[idx].key != rx) {
            idx = (idx + 1) & (cap - 1);
        }

        table[idx].key = rx;
        table[idx].val = i;
    }

    free(table);
    return (ans == n + 1) ? -1 : ans;
}

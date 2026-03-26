#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

/* ---------- Simple hash set for ints ---------- */
typedef struct {
    int *keys;
    int cap;
} HashSet;

HashSet* hs_create(int cap) {
    HashSet *h = malloc(sizeof(HashSet));
    h->cap = cap * 2 + 5;
    h->keys = malloc(sizeof(int) * h->cap);
    for (int i = 0; i < h->cap; i++) h->keys[i] = 0x7fffffff;
    return h;
}

void hs_insert(HashSet *h, int x) {
    int i = (x & 0x7fffffff) % h->cap;
    while (h->keys[i] != 0x7fffffff && h->keys[i] != x)
        i = (i + 1) % h->cap;
    h->keys[i] = x;
}

bool hs_contains(HashSet *h, int x) {
    int i = (x & 0x7fffffff) % h->cap;
    while (h->keys[i] != 0x7fffffff) {
        if (h->keys[i] == x) return true;
        i = (i + 1) % h->cap;
    }
    return false;
}

void hs_free(HashSet *h) {
    free(h->keys);
    free(h);
}

/* ---------- Grid utilities ---------- */
int** copyGrid(int **g, int m, int n) {
    int **r = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        r[i] = malloc(sizeof(int) * n);
        memcpy(r[i], g[i], sizeof(int) * n);
    }
    return r;
}

int** reverseGrid(int **g, int m, int n) {
    int **r = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        r[i] = malloc(sizeof(int) * n);
        memcpy(r[i], g[m - 1 - i], sizeof(int) * n);
    }
    return r;
}

int** transposeGrid(int **g, int m, int n, int *outM, int *outN) {
    int **r = malloc(sizeof(int*) * n);
    for (int j = 0; j < n; j++) {
        r[j] = malloc(sizeof(int) * m);
        for (int i = 0; i < m; i++)
            r[j][i] = g[i][j];
    }
    *outM = n;
    *outN = m;
    return r;
}

/* ---------- Core editorial logic ---------- */
bool canPartitionOne(int **g, int m, int n, ll total) {
    ll topSum = 0;
    HashSet *seen = hs_create(m * n);

    for (int i = 0; i < m - 1; i++) {
        ll rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += g[i][j];
            hs_insert(seen, g[i][j]);
        }
        topSum += rowSum;

        ll botSum = total - topSum;
        ll diff = topSum - botSum;

        if (diff == 0) {
            hs_free(seen);
            return true;
        }

        /* Border cells in this orientation */
        if (diff == g[0][0] ||
            diff == g[0][n - 1] ||
            diff == g[i][0]) {
            hs_free(seen);
            return true;
        }

        /* Interior cells allowed only if height >= 2 */
        if (n > 1 && i > 0 && hs_contains(seen, (int)diff)) {
            hs_free(seen);
            return true;
        }
    }

    hs_free(seen);
    return false;
}

/* ---------- Main wrapper ---------- */
bool canPartitionGrid(int **grid, int gridSize, int *gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    ll total = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            total += grid[i][j];

    /* Orientation 1: original */
    if (canPartitionOne(grid, m, n, total)) return true;

    /* Orientation 2: reversed vertically */
    int **rev = reverseGrid(grid, m, n);
    if (canPartitionOne(rev, m, n, total)) return true;

    /* Orientation 3: transposed */
    int tm, tn;
    int **tr = transposeGrid(grid, m, n, &tm, &tn);
    if (canPartitionOne(tr, tm, tn, total)) return true;

    /* Orientation 4: reversed transposed */
    int **trrev = reverseGrid(tr, tm, tn);
    if (canPartitionOne(trrev, tm, tn, total)) return true;

    return false;
}


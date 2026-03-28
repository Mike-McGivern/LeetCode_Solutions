#include <stdlib.h>
#include <string.h>

static int find(int *parent, int x) {
    return parent[x] == x ? x : (parent[x] = find(parent, parent[x]));
}

static void unite(int *parent, int *rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return;
    if(rank[a] < rank[b]) parent[a] = b;
    else if(rank[a] > rank[b]) parent[a] = b;
    else parent[b] = a, rank[a]++;
}

char* findTheString(int** lcp, int n, int* colSize) {
    int *parent = malloc(sizeof(int) * n);
    int *rank = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) parent[i] = i;

    for(int i = 0; i < n; i++) {
        if(lcp[i][i] != n - i) {
            free(parent); free(rank);
            return strdup("");
        }
        for(int j = i + 1; j < n; j++) {
            if(lcp[i][j] > 0) {
                unite(parent, rank, i, j);
            }
        }
    }

    char *res = malloc(n + 1);
    memset(res, 0, n + 1);

    char nextChar = 'a';
    for(int i = 0; i < n; i++) {
        int p = find(parent, i);
        if(res[p] == 0) {
            if(nextChar > 'z') {
                free(parent); free(rank);
                free(res);
                return strdup("");
            }
            res[p] = nextChar++;
        }
        res[i] = res[p];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int k = 0;
            while(i + k < n && j + k < n && res[i + k] == res[j + k]) k++;
            if(k != lcp[i][j]) {
                free(parent); free(rank);
                free(res);
                return strdup("");
            }
        }
    }

    free(parent);
    free(rank);
    return res;
}

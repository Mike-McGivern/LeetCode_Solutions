#include <stdbool.h>
bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int m = matSize;
    int n = matColSize[0];

    k %= n; //all shifts - full cycles

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int expectedCol;
            if(i % 2 == 0) {
                //even row shifted left by k
                //element that ends up at j originally was at (j + k) % n (one cyclic shift ago)
                expectedCol = (j + k) % n;
            } else {
                //odd row, shifted right by k
                //element that ends up at j originally was at (j - k + n) % n
                expectedCol = (j - k + n) % n;
            }

            if(mat[i][j] != mat[i][expectedCol]) {
                return false;
            }
        }
    }

    return true;

}

#include <stdlib.h>

int numberOfStableArrays(int zero, int one, int limit) {
    const int MOD = 1000000007;
    int cols = one + 1;
    int size = (zero + 1) * (one + 1);

    int *dp0 = (int *)calloc(size, sizeof(int));
    int *dp1 = (int *)calloc(size, sizeof(int));

    #define IDX(i, j) ((i) * cols + (j))

    // 只放 0 的情况：长度不能超过 limit
    for (int i = 1; i <= zero && i <= limit; i++) {
        dp0[IDX(i, 0)] = 1;
    }

    // 只放 1 的情况：长度不能超过 limit
    for (int j = 1; j <= one && j <= limit; j++) {
        dp1[IDX(0, j)] = 1;
    }

    for (int i = 1; i <= zero; i++) {
        for (int j = 1; j <= one; j++) {
            long long v0 = (long long)dp0[IDX(i - 1, j)] + dp1[IDX(i - 1, j)];
            if (i - limit - 1 >= 0) {
                v0 -= dp1[IDX(i - limit - 1, j)];
            }
            v0 %= MOD;
            if (v0 < 0) v0 += MOD;
            dp0[IDX(i, j)] = (int)v0;

            long long v1 = (long long)dp0[IDX(i, j - 1)] + dp1[IDX(i, j - 1)];
            if (j - limit - 1 >= 0) {
                v1 -= dp0[IDX(i, j - limit - 1)];
            }
            v1 %= MOD;
            if (v1 < 0) v1 += MOD;
            dp1[IDX(i, j)] = (int)v1;
        }
    }

    int ans = dp0[IDX(zero, one)] + dp1[IDX(zero, one)];
    if (ans >= MOD) ans -= MOD;

    free(dp0);
    free(dp1);
    return ans;
}
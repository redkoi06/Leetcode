//
// Created by GPT on 2026/3/9.
//

#define MOD 1000000007

int numberOfStableArrays(int zero, int one, int limit) {
    long long dp0[zero + 1][one + 1];
    long long dp1[zero + 1][one + 1];

    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) {
            dp0[i][j] = 0;
            dp1[i][j] = 0;
        }
    }

    // 只有 0
    for (int i = 1; i <= zero && i <= limit; i++) {
        dp0[i][0] = 1;
    }

    // 只有 1
    for (int j = 1; j <= one && j <= limit; j++) {
        dp1[0][j] = 1;
    }

    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) {
            if (i == 0 && j == 0) continue;

            if (i > 0 && j > 0) {
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % MOD;
                if (i > limit) {
                    dp0[i][j] = (dp0[i][j] - dp1[i - limit - 1][j] + MOD) % MOD;
                }

                dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1]) % MOD;
                if (j > limit) {
                    dp1[i][j] = (dp1[i][j] - dp0[i][j - limit - 1] + MOD) % MOD;
                }
            }
        }
    }

    return (dp0[zero][one] + dp1[zero][one]) % MOD;
}
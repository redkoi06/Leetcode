int concatenatedBinary(int n) {
    const int MOD = 1000000007;
    long long res = 0;
    int len = 0;

    for (int i = 1; i <= n; ++i) {
        // i 是 2 的幂 -> 二进制长度增加
        if ((i & (i - 1)) == 0) ++len;

        res = ((res << len) + i) % MOD;
    }
    return (int)res;
}
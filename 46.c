// GPT

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool hasAllCodes(char * s, int k) {
    int n = (int)strlen(s);
    int need = 1 << k;

    // 剪枝：长度不够不可能覆盖所有长度为k的子串
    if (n < need + k - 1) return false;

    // seen[code] = 是否出现过该长度k的二进制串
    unsigned char *seen = (unsigned char*)calloc(need, sizeof(unsigned char));
    if (!seen) return false; // 内存分配失败就直接返回

    int mask = need - 1;
    int x = 0;

    // 初始化第一个窗口
    for (int i = 0; i < k; i++) {
        x = (x << 1) | (s[i] - '0');
    }
    seen[x] = 1;
    int cnt = 1;

    // 滑动窗口：保留低k位
    for (int i = k; i < n; i++) {
        x = ((x << 1) & mask) | (s[i] - '0');
        if (!seen[x]) {
            seen[x] = 1;
            cnt++;
            if (cnt == need) {  // 已集齐所有 2^k 种
                free(seen);
                return true;
            }
        }
    }

    free(seen);
    return cnt == need;
}
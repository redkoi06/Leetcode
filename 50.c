//
// Created by GPT on 2026/2/27.
//

#include <stdlib.h>
#include <string.h>

static int dsu_find(int* parent, int x) {
    if (parent[x] == x) return x;
    parent[x] = dsu_find(parent, parent[x]);
    return parent[x];
}

// 从未访问集合中“删除”元素 x：parent[x] -> find(x+1)
static void dsu_erase(int* parent, int x) {
    parent[x] = dsu_find(parent, x + 1);
}

int minOperations(char* s, int k) {
    int n = (int)strlen(s);
    if (n == 0) return 0;

    int zeros = 0;
    for (int i = 0; i < n; i++) if (s[i] == '0') zeros++;

    if (zeros == 0) return 0;
    if (k == 0) return -1;
    if (k > n) return -1;

    // dist[0..n]
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) dist[i] = -1;

    // 队列（BFS）
    int* q = (int*)malloc((n + 1) * sizeof(int));
    int head = 0, tail = 0;

    // 并查集：分别维护偶数点(0,2,4,...) 和奇数点(1,3,5,...)
    int evenSize = n / 2 + 1; // 0..n 中偶数个数
    int oddSize = (n + 1) / 2; // 0..n 中奇数个数（不含0）
    int* parEven = (int*)malloc((evenSize + 1) * sizeof(int)); // +1 sentinel
    int* parOdd = (int*)malloc((oddSize + 1) * sizeof(int));

    for (int i = 0; i <= evenSize; i++) parEven[i] = i;
    for (int i = 0; i <= oddSize; i++) parOdd[i] = i;

    // 初始化
    dist[zeros] = 0;
    q[tail++] = zeros;
    if ((zeros & 1) == 0) dsu_erase(parEven, zeros / 2);
    else dsu_erase(parOdd, (zeros - 1) / 2);

    while (head < tail){
        int i = q[head++];
        int d = dist[i];
        if (i == 0) break;

        int ones = n - i;

        // a 的可行范围：a_min <= a <= a_max
        int a_min = k - ones; // a >= k - ones
        if (a_min < 0) a_min = 0;
        int a_max = (i < k) ? i : k; // a <= min(i,k)
        if (a_min > a_max) continue;

        int L = i + k - 2 * a_max; // 最小 j
        int R = i + k - 2 * a_min; // 最大 j
        if (L < 0) L = 0;
        if (R > n) R = n;

        int p = (i + k) & 1; // j 的奇偶固定为 (i+k)%2

        if (p == 0){
            if (L & 1) L++;
            if (R & 1) R--;
            if (L <= R){
                int l = L / 2;
                int r = R / 2;
                int t = dsu_find(parEven, l);
                while (t <= r){
                    int j = 2 * t;
                    dist[j] = d + 1;
                    q[tail++] = j;
                    dsu_erase(parEven, t);
                    t = dsu_find(parEven, t);
                }
            }
        }
        else{
            if ((L & 1) == 0) L++;
            if ((R & 1) == 0) R--;
            if (L <= R){
                int l = (L - 1) / 2;
                int r = (R - 1) / 2;
                int t = dsu_find(parOdd, l);
                while (t <= r){
                    int j = 1 + 2 * t;
                    dist[j] = d + 1;
                    q[tail++] = j;
                    dsu_erase(parOdd, t);
                    t = dsu_find(parOdd, t);
                }
            }
        }
    }

    int ans = dist[0];

    free(dist);
    free(q);
    free(parEven);
    free(parOdd);
    return ans;
}

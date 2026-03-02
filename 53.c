//
// Created by GPT on 2026/2/27.
//

int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int* tz = (int*)malloc(sizeof(int) * n);
    if (!tz) return -1;

    // count trailing zeros for each row
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (grid[i][j] == 0) cnt++;
            else break;
        }
        tz[i] = cnt;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int need = n - 1 - i;

        int j = i;
        while (j < n && tz[j] < need) j++;
        if (j == n) {
            free(tz);
            return -1;
        }

        // bubble row j up to i by adjacent swaps
        while (j > i) {
            int tmp = tz[j];
            tz[j] = tz[j - 1];
            tz[j - 1] = tmp;
            ans++;
            j--;
        }
    }

    free(tz);
    return ans;
}
//
// Created by HONGLI on 2026/3/4.
//

int numSpecial(int** mat, int matSize, int* matColSize)
{
    int result = 0;
    int *cnt_row = malloc(sizeof(int) * matSize);
    int *cnt_col = malloc(sizeof(int) * *matColSize);
    for (int i = 0; i < matSize; i++)
    {
        cnt_row[i] = 0;
    }
    for (int i = 0; i < *matColSize; i++)
    {
        cnt_col[i] = 0;
    }
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < *matColSize; j++)
        {
            if (mat[i][j] == 1)
            {
                cnt_row[i]++;
                cnt_col[j]++;
            }
        }
    }
    for (int i = 0;i < matSize;i++)
    {
        for (int j = 0; j < *matColSize; j++)
        {
            if (mat[i][j] == 1 && cnt_row[i] == 1 && cnt_col[j] == 1) result++;
        }
    }
    free(cnt_row);
    free(cnt_col);
    return result;
}
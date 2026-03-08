//
// Created by HONGLI on 2026/3/8.
//

#include <stdlib.h>

char* findDifferentBinaryString(char** nums, int numsSize) {
    char* result = (char*)malloc((numsSize + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i][i] == '0' ? '1' : '0';
    }
    result[numsSize] = '\0';
    return result;
}

//
// Created by lhl on 2026/2/25.
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

struct node
{
    int data;
    int bitcnt;
};

int bit_cnt(int num) {
    int result = 0;
    while (num > 0){
        if (num & 1){
            result++;
        }
        num >>= 1;
    }
    return result;
}

int comp(const void* a, const void* b) {
    struct node node_x = *(const struct node*)a;
    struct node node_y = *(const struct node*)b;
    if (node_x.bitcnt < node_y.bitcnt) return -1;
    if (node_x.bitcnt > node_y.bitcnt) return 1;
    if (node_x.data < node_y.data) return -1;
    if (node_x.data > node_y.data) return 1;
    return 0;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    struct node* nodes = (struct node*)malloc(sizeof(struct node) * arrSize);
    for (int i = 0; i < arrSize; i++){
        nodes[i].data = arr[i];
        nodes[i].bitcnt = bit_cnt(arr[i]);
    }
    qsort(nodes, arrSize, sizeof(nodes[0]), comp);
    for (int i = 0; i < arrSize; i++){
        arr[i] = nodes[i].data;
    }
    *returnSize = arrSize;
    free(nodes);
    return arr;
}

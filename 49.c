//
// Created by GPT on 2026/2/26.
//

#include <string.h>

int numSteps(char* s) {
    int n = (int)strlen(s);
    long long steps = 0;
    int carry = 0;

    // 从最低位扫到下标 1，保留最高位在最后处理
    for (int i = n - 1; i >= 1; --i){
        int bit = (s[i] - '0') + carry;
        if (bit == 1){
            // 奇数：+1 再 /2
            steps += 2;
            carry = 1;
        }
        else{
            // 偶数：/2
            steps += 1;
            carry = bit / 2; // 0->0, 2->1
        }
    }

    // 如果最后还有进位，最高位需要额外一步
    steps += carry;

    return (int)steps;
}

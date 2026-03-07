//
// Created by HONGLI on 2026/3/7.
//

// !!!!!偶数长度可以直接提前返回

#include <stdlib.h>
#include<string.h>

int minFlips(char* s){
    int length = strlen(s);
    char *double_s = malloc(length * 2 + 1);
    strcpy(double_s, s);
    strcat(double_s,s);
    int result_1 = 0;//01
    int result_2 = 0;//10
    for (int i = 0;i < length;i++)
    {
        if (s[i] - '0' != i % 2)
        {
            result_1++;
        }else
        {
            result_2++;
        }
    }
    int result = result_1 < result_2 ? result_1 : result_2;
    for (int i = 1;i < length;i++){
        //01
        if (double_s[i - 1] - '0' != (i - 1) % 2)
        {
            result_1--;
        }else
        {
            result_2--;
        }
        if (double_s[i + length - 1] - '0'!= (i + length - 1) % 2)
        {
            result_1++;
        }else
        {
            result_2++;
        }
        int temp = result_1 < result_2 ? result_1 : result_2;
        result = result < temp ? result : temp;
    }
    free(double_s);
    return result;
}
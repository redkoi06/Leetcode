//
// Created by HONGLI on 2026/3/5.
//

int minOperations(char* s) {
    int result_1 = 0;
    int result_2 = 0;\
    int status = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] - '0' != status)
        {
            result_1++;
        }else
        {
            result_2++;
        }
        status = status == 0 ? 1 : 0;
    }
    return result_1 < result_2 ? result_1 : result_2;
}
int binaryGap(int n) {
    int index = 0;
    int former = -1;
    int result = 0;
    while(n > 0){
        int cur = (n & 1);
        if(cur == 1 && former != -1){
            int temp = index - former;
            result = temp > result ? temp : result;
        }
        if(cur == 1){
            former = index;
        }
        index++;
        n >>= 1;
    }
    return result;
}
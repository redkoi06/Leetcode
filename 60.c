int bitwiseComplement(int n) {
    if(n == 0) return 1;
    int cnt = 0;
    int box[32] = {0};
    while(n != 0){
        if(n % 2 == 0){
            box[cnt++] = 0;
        }else{
            box[cnt++] = 1;
        }
        n /= 2;
    }
    int result = 0;
    for(int i = cnt - 1;i >= 0;i--){
        result = result * 2 + (box[i] == 0 ? 1 : 0);
    }
    return result;
}
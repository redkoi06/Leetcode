int minPartitions(char* n) {
    int result = 1;
    for(int i = 0;n[i] != '\0';i++){
        if(n[i] - '0' > result){
            result = n[i] - '0';
        }
    }
    return result;
}
int numJewelsInStones(char* jewels, char* stones) {
    int c=0;
    for(int i=0;*(jewels +i)!='\0';i++){
        for(int j=0;*(stones+j)!='\0';j++){
            if((*(jewels+i)) == (*(stones+j))){
                c=c+1;
            }
        }
    }
    return c;
}

int scoreOfString(char* s) {
    int score=0;
    int i=0;
    while(*(s+i)!='\0'){
        i++;
    }
    for(int j=0;j<i-1;j++){
        int term=s[j]-s[j+1];
        if(term<0){
            term= term *(-1);
        }
        score=score+term;
    }
    return score;
}

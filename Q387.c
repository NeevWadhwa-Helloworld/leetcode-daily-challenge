int firstUniqChar(char* s) {
    int find;
    for(int i=0;s[i]!='\0';i++){
        for(int j=0;s[j]!='\0';j++){
            find=0;
            if(s[i]==s[j] && i!=j){
                find=1;
                break;
            }
        }
        if(find==0){
            return i;
        }
    }
    return -1;
}

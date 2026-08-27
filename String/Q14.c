char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix=(char*)malloc(strlen(strs[0])+1);
    int i=0;
    strcpy(prefix,strs[0]);
    for(i=1;i<strsSize;i++){
        int j=0;
        while(strs[i][j]==prefix[j] && strs[i][j]!='\0' && prefix[j]!='\0'){
            j++;
        }
        prefix[j]='\0';
    }
    return prefix;
}

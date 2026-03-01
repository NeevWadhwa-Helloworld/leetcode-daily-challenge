int strStr(char* haystack, char* needle) {
    int l=strlen(needle);
    for(int i=0;haystack[i]!='\0';i++){
        int j=0;
        if(haystack[i]==needle[j]){
            int k=i;
            while(needle[j]!='\0' && needle[j]==haystack[k] && haystack[k]!='\0'){
                j++;
                k++;
            }
            if(j==l){
                return i;
            }
        }
    }
    return -1;
}

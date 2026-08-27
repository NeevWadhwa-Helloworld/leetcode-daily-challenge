int lengthOfLastWord(char* s) {
    int l=0;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]!=' '){
            if(i>0 && s[i-1]==' '){
                l=1;
            }else{
                l++;
            }
        }
    }
    return l;
}

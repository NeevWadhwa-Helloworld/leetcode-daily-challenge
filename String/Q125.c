
bool isPalindrome(char* s) {
    char* phrase=(char*)malloc(strlen(s)+1);
    char* rev=(char*)malloc(strlen(s)+1);
    int j=0;
    for(int i=0;i<strlen(s);i++){
        if(isalnum(s[i])){
            phrase[j]=tolower(s[i]);
            j++;
        }
    }
    phrase[j]='\0';
    for(int i=strlen(phrase)-1,k=0;i>=0;i--,k++){
        rev[k]=phrase[i];
    }
    rev[j]='\0';
    int flag=0;
    for(int i=0;i<strlen(phrase);i++){
        if(phrase[i]!=rev[i]){
            flag++;
            free(phrase);
            free(rev);
            return false;
        }
    }
    return true;
}

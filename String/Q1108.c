

char * defangIPaddr(char * address){
    char *new=(char*)malloc(strlen(address)+7 *sizeof(char));
    int i=0;
    int j=0;
    for(i=0,j=0;*(address+i)!='\0';i++,j++){
        if(*(address+i)=='.'){
            *(new+j)='[';
            j++;
            *(new+j)='.';
            j++;
            *(new+j)=']';
        }else{
            new[j]=*(address+i);
        }
    }
    *(new+j)='\0';
    return new;
}

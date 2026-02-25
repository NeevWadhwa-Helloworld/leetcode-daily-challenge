int mostWordsFound(char** sentences, int sentencesSize) {
    int m_now=0;
    int now=0;
    for(int i=0;i<sentencesSize;i++){
        
        now=1;
        for(int j=0;sentences[i][j]!='\0';j++){
            if(sentences[i][j]==' '){
                now++;
            }
        }
        if(m_now<now){
            m_now=now;
        }
    }
    return m_now; 
}

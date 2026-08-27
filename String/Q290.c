bool wordPattern(char * pattern, char * s) {
    char *map[26] = {NULL};
    int n = strlen(pattern);
    char *s_copy = strdup(s);
    char *word = strtok(s_copy, " ");
    
    for (int i = 0; i < n; i++) {
        if (word == NULL) {
            free(s_copy);
            return false;
        }

        int idx = pattern[i] - 'a';

        if (map[idx] == NULL) {
            for (int j = 0; j < 26; j++) {
                if (map[j] != NULL && strcmp(map[j], word) == 0) {
                    free(s_copy);
                    return false;
                }
            }
            map[idx] = strdup(word);
        } else {
            if (strcmp(map[idx], word) != 0) {
                free(s_copy);
                for(int k=0; k<26; k++) if(map[k]) free(map[k]);
                return false;
            }
        }
        word = strtok(NULL, " ");
    }
    if (word != NULL) {
        free(s_copy);
        for(int k=0; k<26; k++) if(map[k]) free(map[k]);
        return false;
    }
    free(s_copy);
    for(int k=0; k<26; k++) if(map[k]) free(map[k]);
    
    return true;
}

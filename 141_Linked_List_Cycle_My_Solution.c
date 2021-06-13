char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    int i;
    char **ret;
    ret = malloc(0);
    *returnSize = 0;
    
    if (*s == 0) {
        return 0;
    }
    
    for (i = 0 ; i < wordDictSize ; i++) {
        char *ch = s;
        char *wd = wordDict[i];
        int cnt = 0;
        
        while(*wd != 0 && *ch == *wd) {
            cnt++;
            ch++;
            wd++;
        }
        
        if (*wd == 0) {
            int j, under_returnSize;
            char **under_ret = wordBreak(s + cnt, wordDict, wordDictSize, &under_returnSize);
            
            if (under_ret == 0) {
                if (*(s + cnt) == 0) {
                    (*returnSize) += 1;

                    ret = realloc(ret, sizeof(char *) * (*returnSize));
                    ret[*returnSize - 1] = malloc(sizeof(char) * (cnt + 1));
                    for (j = 0 ; j < cnt ; j++) {
                        ret[*returnSize - 1][j] = wordDict[i][j];
                    }
                    ret[*returnSize - 1][j] = 0;
                } else {
                    return 0;
                }

            } else {
                ret = realloc(ret, sizeof(char *) * ((*returnSize) + under_returnSize));
                //printf("[%d] ", under_returnSize); 

                for (j = 0 ; j < under_returnSize ; j++) {
                    int k, m;
                    
                    ret[*returnSize + j] = malloc(sizeof(char) * (45));                  
                    for(k = 0 ; k < cnt ; k++) {
                        ret[*returnSize + j][k] = wordDict[i][k];
                    }
                    ret[*returnSize + j][k] = ' ';
                    
                    wd = under_ret[j];
                    while(*wd != 0) {
                        //printf("[%d,%d]", *wd, k);
                        ret[*returnSize + j][++k] = *wd;
                        wd++;
                    }
                    ret[*returnSize + j][++k] = 0;
                    //printf("%s\n", ret[*returnSize + j]);
                }
                (*returnSize) += under_returnSize;
            }
        }
    }
    
    return ret;
}
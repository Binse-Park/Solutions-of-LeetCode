int minDistance(char * word1, char * word2){
    int map[501][501] = {0, };
    int i = 0, idx1 = 1, idx2 = 1;
    char *ch1 = word1, *ch2 = word2;
    
    for (i = 0 ; i < 501 ; i++) {
        map[i][0] = i;
        map[0][i] = i;
    }
    
    if (*ch1 == 0) {
        while (*ch2 != 0) {
            ch2++;
            idx2++;
        }
    }
    
    idx1 = 1;
    while (*ch1 != 0) {
        idx2 = 1;
        ch2 = word2;
        
        while (*ch2 != 0) {
            int insert = map[idx1][idx2 - 1] + 1;
            int remove = map[idx1 - 1][idx2] + 1;
            int replace = map[idx1 - 1][idx2 - 1] + ((*ch1 == *ch2) ? 0 : 1);
            
            if (insert < remove) {
                if (insert < replace) {
                    map[idx1][idx2] = insert;
                } else {
                    map[idx1][idx2] = replace;
                }
            } else {
                if (remove < replace) {
                    map[idx1][idx2] = remove;
                } else {
                    map[idx1][idx2] = replace;
                }
            }
            
            printf("%d ", map[idx1][idx2]);

            ch2++;
            idx2++;
        }
        
        printf("\n");
        ch1++;
        idx1++;
    }
    
    return map[idx1 - 1][idx2 - 1];
}

int cmp(char *a, char *b) {
    int cnt = 0;

    while(*a != 0 && *b != 0) {
        if (*b != *a) {
            cnt++;
        }
        a++;
        b++;
    }
    
    return cnt;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    char *p;
    int pi = 0;
    char *q[5000] = {0, };
    int qs = 0, ql = 0;
    int vi[5000] = {0, };
    int i, j, cnt = 0;

    q[(qs + ql) % 5000] = beginWord;
    ql++;
    
    while(ql > 0) {
        int tmp = ql;
        for (j = 0 ; j < tmp ; j++) {
            p = q[qs];
            qs++;
            ql--;
            //printf("-%s- ", p);
            if (cmp(endWord, p) == 0) {
                return cnt + 1;
            }

            for (i = 0 ; i < wordListSize ; i++) {
                //printf("[%s] ", wordList[i]);
                if (vi[i] == 1) {
                    continue;
                }
                
                if (cmp(p, wordList[i]) == 1) {
                    vi[i] = 1;
                    q[(qs + ql) % 5000] = wordList[i];
                    ql++;

                    //printf("+%s+ ", wordList[i]);
                }
            }
        }
        //printf("\n");
        ++cnt;
    }  

    return 0;
}
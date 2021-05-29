
int traversal(char * s, int *dp){
    char *p = s;
    int min = 2000;
    
    if (*p == 0) {
        return 0;
    }

    while(*p != 0) {
        char *sp = s, *ep = p;
        
        while(*sp == *ep && sp < ep) {
            sp++;
            ep--;
        }
        
        if (sp >= ep) {
            int ret_cuts;
/*
            {
                char *tmp = s;

                while(*tmp != 0 && tmp != p) {
                    printf("%c", *tmp);
                    tmp++;
                }
                printf("%c,", *tmp);
            }
*/
            if (*(dp + 1) == 0) {
                *(dp + 1) = traversal(p + 1, dp + 1);
            } else {
                //printf("<%d,%d>", depth + 1, *(dp + 1));
            }

            if (*(dp + 1) < min) {
                min = *(dp + 1);
            }
        }
        
        p++;
        dp++;
    }

    //printf("[%d,%d]", depth, min + 1);
    return min + 1;
}

int minCut(char * s){
    int dp[2000] = {0, };
    int ret = traversal(s, dp);
/*
    printf("\n");
    for (int i = 0; i < 5 ; i++) {
        printf("%d ", dp[i]);
    }
*/
    return ret - 1;
}
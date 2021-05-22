

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


char *** traversal(char * s, int* returnSize, int** returnColumnSizes, int curidx, char*** dp[20], int dp_rS[20], int* dp_rCs[20]){
    char ***re = 0, *p = s;
    int dpi = curidx;
    
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize > 0 ? *returnSize : 1));
    (*returnColumnSizes)[0] = 0;
    re = malloc(sizeof(int) * (*returnSize));
//    return re;
    
    while(*p != 0) {
        char *sp = s, *ep = p;
        
        while(*sp == *ep && sp < ep) {
            sp++;
            ep--;
        }
        
        if (sp >= ep) {
            char *tmp = s, ***subRe;
            char newStr[20] = {0, };
            int i, j, rS, *rCS, newLen = 0;
            int idx = *returnSize;
 
            if (dp[dpi + 1] != 0) {
                subRe = dp[dpi + 1];
                rS = dp_rS[dpi + 1];
                rCS = dp_rCs[dpi + 1];
                //printf("-%d- ", dpi + 1);
            } else {
                subRe = traversal(p + 1, &rS, &rCS, dpi + 1, dp, dp_rS, dp_rCs);
                dp[dpi + 1] = subRe;
                dp_rS[dpi + 1] = rS;
                dp_rCs[dpi + 1] = rCS;
                //printf("%d+%d ", dpi + 1, rS);
            }
            
            if (rS == 0) {
                rS = 1;
            }

            (*returnSize) += rS;
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
            re = realloc(re, sizeof(int **) * (*returnSize));

            for(i = 0 ; i < rS ; i++) {
                (*returnColumnSizes)[idx + i] = rCS[i] + 1;
                re[idx + i] = malloc(sizeof(int *) * ((*returnColumnSizes)[idx + i]));
                re[idx + i][0] = malloc(sizeof(int) * (p - s + 2));

                tmp = s;
                newLen = 0;
                while(tmp <= p) {
                    re[idx + i][0][newLen++] = *tmp;
                    tmp++;
                }
                re[idx + i][0][newLen] = 0;

                for(j = 0 ; j < rCS[i] ; j++) {
                    re[idx + i][j + 1] = subRe[i][j];
                }
            }   
/*
            {
                int i, j;

                printf("+[");
                for(i = 0 ; i < (*returnSize) ; i++) {
                    printf("[");
                    for(j = 0 ; j < (*returnColumnSizes)[i] ; j++) {
                        printf("%s ", re[i][j]);
                    }
                    printf("]");
                }
                printf("]+ ");
            }
*/


        }
        
        p++;
        dpi++;
    }

    return re;
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    char*** dp[20] = {0, };
    int dp_rS[20] = {0, };
    int* dp_rCs[20] = {0, };

    return traversal(s, returnSize, returnColumnSizes, 0, dp, dp_rS, dp_rCs);
}
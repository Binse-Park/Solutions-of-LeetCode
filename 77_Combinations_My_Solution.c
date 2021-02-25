int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int **result;
    int i, j, m;
    unsigned long den = 1, num = 1;
    int size;
    
    for (i = n - k + 1 ; i <= n ; i++) {
        den *= i;
    }
    
    for (i = 1 ; i <= k ; i++) {
        num *= i;
    }
    
    size = (unsigned long)(den / num);
    result = malloc(sizeof(int *) * size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    *returnSize = den / num;
    //printf("%d / %d = %d", den, num, den / num);
    
    for (i = 0 ; i < size ; i++) {
        result[i] = malloc(sizeof(int) * k);
        (*returnColumnSizes)[i] = k;

        if (i == 0) {
            for (j = 0 ; j < k ; j++) {
                result[i][j] = j + 1;
                //printf("%d ", result[i][j]);
            }
        } else {
            for (j = 0 ; j < k ; j++) {
                result[i][j] = result[i - 1][j];
            }
            
            for (j = 0 ; j < k ; j++) {
                int pos = k - 1 - j;
                if (result[i][pos] < (n - j)) {
                    result[i][pos]++;
                    for (m = pos + 1; m < k ; m++) {
                        result[i][m] = result[i][m - 1] + 1;
                    }
                    break;
                }
            }
        }
        
        //printf("\n");
    }

    return result;
}
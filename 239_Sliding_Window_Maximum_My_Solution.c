int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *ret = malloc(sizeof(int) * 100000);
    int q[100000] = {0, };
    int qs = 0, qe = 0, i, j;
    
    *returnSize = 0;
    
    for (i = 0 ; i < numsSize ; i++) {
        if (qs == qe) {
            q[qe++] = nums[i];
        } else {
            if (i >= k) {
                if (q[qs] == nums[i - k]) {
                    qs++;
                }
            }
            while (qs < qe && q[qe - 1] < nums[i]) {
                qe--;
            }
            q[qe++] = nums[i];

        }
        
        if (i >= k - 1) {
            ret[*returnSize] = q[qs];
            (*returnSize)++;
            /*
            for (j = qs ; j < qe ; j++) {
                printf("%d ", q[j]);
            }
            printf("\n");  
            */
        }

    }
    

    
    return ret;
}
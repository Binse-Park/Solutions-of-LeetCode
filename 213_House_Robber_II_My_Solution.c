int rob(int* nums, int numsSize){
    int i, dp[101] = {0, }, dp2[101] = {0, }, visitedZero[101] = {0, }, max = 0;
    
    dp[0] = nums[0];
    visitedZero[0] = 1;
    max = dp[0];
    i = numsSize - 1;
    
    for(i = 1 ; i < numsSize ; i++) {
        if (i < numsSize - 1) {
            if (i == 1) {
                dp[i] = nums[i];
            } else if (i == 2) {
                dp[i] = nums[i] + dp[i - 2];
            } else{
                if (i < numsSize - 1) {
                    if (dp[i - 2] > dp[i - 3]) {
                        dp[i] = nums[i] + dp[i - 2]; 
                    } else {
                        dp[i] = nums[i] + dp[i - 3]; 
                    }                
                }
            }
        }

        if (i == 1) {
            dp2[i] = nums[i];
        } else if (i == 2) {
            dp2[i] = nums[i];
        } else if (i == 3) {
            dp2[i] = nums[i] + dp2[i - 2];
        } else {
            if (dp2[i - 2] > dp2[i - 3]) {
                dp2[i] = nums[i] + dp2[i - 2]; 
            } else {
                dp2[i] = nums[i] + dp2[i - 3]; 
            }
        }

        if (dp[i] > max) {
            max = dp[i];
        }
        if (dp2[i] > max) {
            max = dp2[i];
        }
    }

    return max;
}
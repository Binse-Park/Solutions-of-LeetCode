int uniquePaths(int m, int n){
    int dp[102] = {0, };
    int x, y;

    for (x = 1 ; x <= n ; x++) {  
        dp[x] = 1;            
    }
    
    for (y = 2 ; y <= m ; y++) {
        for (x = 1 ; x <= n ; x++) {  
            dp[x] += dp[x - 1];             
        }
    }


    return dp[n];
}

/*
int uniquePaths(int m, int n){
    int **map;//[102][102] = {0, };
    int x, y;
    
    map = malloc(sizeof(int *) * m);
    
    for (y = 0 ; y < m; y++) {
        map[y] = malloc(sizeof(int) * n);
        map[y][0] = 1;
    }
    for (x = 0 ; x < n; x++) {          
        map[0][x] = 1;         
    }
   
    for (y = 1 ; y < m ; y++) {
        for (x = 1 ; x < n ; x++) {  
            map[y][x] = map[y][x - 1] + map[y - 1][x];            
        }
    }
   


    for (y = 0 ; y < m ; y++) {
        for (x = 0 ; x < n; x++) {
            printf("%3d ", map[y][x]);           
        }
        printf("\n");
    }

    return map[m - 1][n - 1];
}
*/
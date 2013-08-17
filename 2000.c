#include <stdio.h>
#include <string.h>
#define MAX(a, b) (((a)>(b))?(a):(b))
#define N 100

int matrix[N][N],n,m,dp[N][N]

int main(void){
    int t,i,j,q,max;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j)
                scanf("%d", matrix[i]+j);
        if(matrix[n-1][m-1]==0)
            dp[n-1][m-1]=1;
        else
            dp[n-1][m-1]=0;
        for(j=m-2; j>-1; --j){
            if(matrix[n-1][j]==0)
                dp[n-1][j]=dp[n-1][j+1]+1;
            else
                dp[n-1][j]=dp[n-1][j+1];
        }
        for(i=n-2; i>-1; --i){
            if(matrix[i][m-1]==0)
                dp[i][m-1]=dp[i][m]+1;
            else
                dp[i][m-1]=dp[i][m];
        }
        for(i=n-2; i>-1; --i)
            for(j=m-2; j>-1; --j){
                max=dp[i-1][j-1];
                max=MAX(max, dp[i-1][j]);
                max=MAX(max, dp[i][j-1]);
                if(matrix[i][j]==1)
                    dp[i][j]=max;
                else if(matrix[i][j]==0){
                }
            }
        printf("%d\n", max);
    }
    return 0;
}

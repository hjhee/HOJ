#include <stdio.h>
#include <string.h>
#define MIN(a, b) (((a)>(b))?(b):(a))

int dp[101][5][33];

int main(void){
    int m,k,i,j,mask,n,min;
    int array[101];
#ifndef ONLINE_JUDGE
    freopen("2156.in", "rb", stdin);
#endif
    while(scanf("%d%d", &m, &k), m||k){
        for(i=0; i<m; ++i){
            scanf("%d", array+i);
            --array[i];
        }
        for(i=0; i<101; ++i)
            for(j=0; j<5; ++j)
                for(mask=0; mask<33; ++mask)
                    dp[i][j][mask]=9999;
        dp[0][array[0]][1<<array[0]]=0;
        n=1<<k;
        for(i=0; i<m-1; ++i){
            dp[i][array[i]][1<<(array[i])]=MIN(dp[i][array[i]][1<<(array[i])], i);
            for(j=0; j<k; ++j)
                for(mask=0; mask<n; ++mask){
                    if(j==array[i+1])
                        dp[i+1][j][mask]=MIN(dp[i+1][j][mask],
                                dp[i][j][mask]);
                    else{
                        if((mask&(1<<array[i+1]))==0)
                            dp[i+1][array[i+1]][mask|(1<<array[i+1])]=MIN(
                                    dp[i+1][array[i+1]][mask|(1<<array[i+1])],
                                    dp[i][j][mask]);
                        dp[i+1][j][mask]=MIN(dp[i+1][j][mask],dp[i][j][mask]+1);
                    }
                }
        }
        /*
        for(i=0; i<m-1; ++i){
            for(j=0; j<k; ++j){
                for(mask=0; mask<n; ++mask)
                    printf("%d ", dp[i][j][mask]);
                putchar('\n');
            }
            puts("-------------");
        }
        */
        min=9999;
        for(j=0; j<k; ++j)
            for(mask=0; mask<n; ++mask)
                min=MIN(min, dp[m-1][j][mask]);
        printf("%d\n", min);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

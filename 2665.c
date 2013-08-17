#include <stdio.h>
#include <string.h>
#define MAX(a, b) ((a)>(b)?(a):(b))

int dp[2][65536][20];

int main(void){
    int m,n,i,j,s,u,k,max;
    int trans[20][20],import[20],export[20];
#ifndef ONLINE_JUDGE
    freopen("2665.in", "rb", stdin);
#endif
    while(scanf("%d%d", &n, &m)==2){
        memset(dp, 0, sizeof(dp));
        for(i=0; i<n; ++i)
            scanf("%d%d", import+i, export+i);
        for(i=0; i<n; ++i)
            for(j=0; j<n; ++j)
                scanf("%d", trans[i]+j);
        dp[0][1<<(m-1)][m-1]=export[m-1]-import[m-1];
        u=1<<n;
        for(i=0; i<n; ++i)
            for(s=0; s<u; ++s)
                for(j=0; j<n; ++j)
                    if(s&(1<<j))
                        for(k=0; k<n; ++k)
                            if((s&(1<<k))==0)
                                dp[(i+1)&1][s|(1<<k)][k]=MAX(dp[(i+1)&1][s|(1<<k)][k],
                                        dp[i&1][s][j]+export[k]-import[k]-trans[j][k]);
        /*
        for(i=0; i<n; ++i){
            for(j=0; j<n; ++j){
                for(s=1; s<u; ++s)
                    printf("%d ", dp[i][s][j]);
                putchar('\n');
            }
            puts("-------------");
        }
        */
        for(max=j=0; j<n; ++j)
            max=MAX(max, dp[(n-1)&1][u-1][j]);
        printf("%d\n", max);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

#include <stdio.h>
#include <string.h>
#define N 60000
#define L 20000

int dp[N+10],list[L+10],tot,sum;

/*
int backtracking(int *n, int p, int m, int c, int cur){
    int i;
    if(c==m)
        return 1;
    if(cur==p)
        return backtracking(n, p, m, c+1, 0);
    else if(cur>p)
        return 0;
    for(i=0; i<6; ++i){
        if(n[i]>0){
            --n[i];
            if(backtracking(n, p, m, c, cur+i+1))
                return 1;
            ++n[i];
        }
    }
    return 0;
}
*/

int reach(void){
    int i,j,p;
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    p=sum/2;
    for(i=0; i<tot; ++i){
        for(j=p; j>=list[i]; --j)
            if(dp[j-list[i]]==1)
                dp[j]=1;
        if(dp[p]==1)
            return 1;
        /*
        for(j=0; j<=sum; ++j)
            printf("%d ", dp[j]);
        putchar('\n');
        */
    }
    return dp[p]==1;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1141.in", "rb", stdin);
#endif
    int i,t,n,j;
    t=0;
    while(1){
        sum=tot=0;
        ++t;
        for(tot=i=0; i<6; ++i){
            scanf("%d", &n);
            sum+=n*(i+1);
            for(j=0; j<n; ++j)
                list[tot++]=i+1;
        }
        if(tot==0)
            break;
        printf("Collection #%d:\n", t);
        if((!(sum%2))&&reach())
            puts("Can be divided.\n");
        else
            puts("Can't be divided.\n");
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

int stick[N],vis[N];
int valid(int n, int l, int rst, int m);

int cmp_integer(const void *a, const void *b){
    return *(int *)b-*(int *)a;
}

int compose(int n, int l, int rst, int c, int m){
    int i;
    if(c==l)
        return valid(n, l, rst-l, 0);
    else if(c>l)
        return 0;
    for(i=0; i<n; ++i)
        if(!vis[i]){
            vis[i]=1;
            if(compose(n, l, rst, c+stick[i], m+1))
                return 1;
            vis[i]=0;
            if(i+1<n){
                while(i+1<n&&stick[i]==stick[i+1])
                    ++i;
            }
            if(m==0)
                return 0;
        }
    return 0;
}

int valid(int n, int l, int rst, int m){
    if(rst<l)
        return 0;
    else if(rst==l)
        return 1;
    return compose(n, l, rst, 0, 0);
}

int len(int n){
    int l,i,sum;
    for(sum=l=i=0; i<n; ++i){
        sum+=stick[i];
        if(l<stick[i])
            l=stick[i];
    }
    for(; l<sum; ++l)
        if(sum%l==0){
            if(valid(n, l, sum, 0))
                return l;
        }
    return sum;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1049.in", "rb", stdin);
#endif
    int n,i;
    while(scanf("%d", &n)==1&&n){
        memset(vis, 0, sizeof(vis));
        for(i=0; i<n; ++i)
            scanf("%d", stick+i);
        qsort(stick, n, sizeof(int), cmp_integer);
        printf("%d\n", len(n));
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

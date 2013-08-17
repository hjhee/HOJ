#include <stdio.h>
#include <string.h>
#define N 16384

int array[N+10];

int lowbit(int x){
    return x&((~x)+1);
}

int sum(int x){
    int s;
    for(s=0; x<=N; x+=lowbit(x))
        s+=array[x];
    return s;
}

void modify_d(int x){
    for(; x>0; x-=lowbit(x))
        --array[x];
}

void modify_i(int x){
    for(; x>0; x-=lowbit(x))
        ++array[x];
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2683.in", "rb", stdin);
#endif
    int n,m,x,y,i,s[4];
    while(scanf("%d%d", &n, &m)==2){
        memset(array, 0, sizeof(array));
        memset(s, 0, sizeof(s));
        while(m--){
            scanf("%d%d", &x, &y);
            modify_d(x-1);
            modify_i(y);
        }
        for(i=1; i<=n; ++i)
            ++s[sum(i)%3];
        printf("%d", s[0]);
        for(i=1; i<3; ++i)
            printf(" %d", s[i]);
        putchar('\n');
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

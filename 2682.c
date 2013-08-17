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

void modify(int x){
    for(; x>0; x-=lowbit(x))
        ++array[x];
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2682.in", "rb", stdin);
#endif
    int n,m,x,y,i,s;
    while(scanf("%d%d", &n, &m)==2){
        memset(array, 0, sizeof(array));
        while(m--){
            scanf("%d%d", &x, &y);
            modify(x-1);
            modify(y);
        }
        for(s=0, i=1; i<=n; ++i)
            if(!(sum(i)&1))
                ++s;
        printf("%d\n", s);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

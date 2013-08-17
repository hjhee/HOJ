#include <stdio.h>
#include <string.h>
#define N 50000

int n;
int array_l[N+10];
int array_r[N+10];
int seq[N+10],rseq[N+10];

long long l[N+10],r[N+10];

int lowbit(int x){
    return x&((~x)+1);
}

int sum(int *array, int x){
    int s;
    for(s=0; x>0; x-=lowbit(x))
        s+=array[x];
    return s;
}

void modify(int *array, int x, int d){
    for(; x<=N; x+=lowbit(x))
        array[x]+=d;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2275.in", "rb", stdin);
#endif
    int i;
    long long s;
    while(scanf("%d", &n)==1){
        memset(array_l, 0, sizeof(array_l));
        memset(array_r, 0, sizeof(array_r));
        for(i=1; i<=n; ++i){
            scanf("%d", seq+i);
            ++seq[i];
            rseq[n-i+1]=seq[i];
        }
        for(i=1; i<=n; ++i){
            l[i]=sum(array_l, seq[i]-1);
            modify(array_l, seq[i], 1);
            r[n-i+1]=sum(array_r, rseq[i]-1);
            modify(array_r, rseq[i], 1);
        }
        for(s=0, i=1; i<=n; ++i)
            s+=l[i]*r[i];
        printf("%lld\n", s);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

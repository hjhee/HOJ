#include <stdio.h>
#include <string.h>
#define N 6000
#define C 11

unsigned long long dollar[N+10];

void init(void){
    int i,k;
    const int currency[]={1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    dollar[0]=1;
    for(i=0; i<C; ++i)
        for(k=0; k+currency[i]<=N; ++k)
            dollar[k+currency[i]]+=dollar[k];
}

int main(void){
    int a,b,u;
    double m;
    init();
    while(scanf("%d.%d", &a, &b)==2){
        u=a*100+b;
        if(!u)
            break;
        m=a+(double)b/100;
        printf("%6.2f%17llu\n", m, dollar[u/5]);
    }
    return 0;
}

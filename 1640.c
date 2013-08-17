#include <stdio.h>
#include <string.h>
#define S 1024
#define LOWBIT(x) ((x)&((~(x))+1))

int table[S+10][S+10],s;

void modify(int x, int y, int d){
    int i,j;
    for(i=x; i<=s; i+=LOWBIT(i))
        for(j=y; j<=s; j+=LOWBIT(j))
            table[i][j]+=d;
}

long long sum(int x, int y){
    int i,j;
    long long sigma;
    for(sigma=0, i=x; i>0; i-=LOWBIT(i))
        for(j=y; j>0; j-=LOWBIT(j))
            sigma+=table[i][j];
    return sigma;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1640.in", "rb", stdin);
#endif
    int ins,x1,y1,x2,y2,d;
    long long sigma;
    while(scanf("%d", &ins)==1){
        switch(ins){
            case 0: scanf("%d", &s); 
                    s+=2;
                    memset(table, 0, sizeof(table));
                    break;
            case 1: scanf("%d%d%d", &x1, &y1, &d); 
                    x1+=2;
                    y1+=2;
                    modify(x1, y1, d);
                    break;
            case 2: scanf("%d%d%d%d", &x1, &y1, &x2, &y2); 
                    x1+=2;
                    y1+=2;
                    x2+=2;
                    y2+=2;
                    sigma=sum(x2, y2)+sum(x1-1, y1-1)-sum(x1-1, y2)-sum(x2, y1-1);
                    printf("%lld\n", sigma);
                    break;
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

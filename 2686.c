#include <stdio.h>
#include <string.h>
#define N 200
#define LOWBIT(x) ((x)&((~(x))+1))

int magic[N+1][N+1][N+1];

void modify(int x, int y, int z, int d){
    int i,j,k;
    for(i=x; i>0; i-=LOWBIT(i))
        for(j=y; j>0; j-=LOWBIT(j))
            for(k=z; k>0; k-=LOWBIT(k))
                magic[i][j][k]+=d;
}

int sum(int x, int y, int z){
    int s,i,j,k;
    for(s=0, i=x; i<=N; i+=LOWBIT(i))
        for(j=y; j<=N; j+=LOWBIT(j))
            for(k=z; k<=N; k+=LOWBIT(k))
                s+=magic[i][j][k];
    return s;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2686.in", "rb", stdin);
#endif
    int n,x1,x2,y1,y2,z1,z2,d;
    char input[100];
    while(scanf("%d", &n)==1){
        memset(magic, 0, sizeof(magic));
        while(n--){
            scanf("%s", input);
            if(input[0]=='A'){
                scanf("%d%d%d%d%d%d%d", &x1, &y1, &z1,
                       &x2, &y2, &z2, &d);
                modify(x2, y2, z2, d);
                modify(x2, y2, z1-1, -d);
                modify(x2, y1-1, z2, -d);
                modify(x1-1, y2, z2, -d);
                modify(x1-1, y1-1, z2, d);
                modify(x1-1, y2, z1-1, d);
                modify(x2, y1-1, z1-1, d);
                modify(x1-1, y1-1, z1-1, -d);
            }else if(input[0]=='Q'){
                scanf("%d%d%d", &x1, &y1, &z1);
                printf("%d\n", sum(x1, y1, z1));
            }
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

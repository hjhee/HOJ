#include <stdio.h>
#include <string.h>
#define N 10000
#define P 7000

int e,f,v,n;
int pig[N+10],coins[P+10][2],top;

void init(void){
    int i,j;
    top=0;
    memset(pig, -1, sizeof(pig));
    scanf("%d%d%d", &e, &f, &n);
    v=f-e;
    for(i=0; i<n; ++i)
        scanf("%d%d", coins[i], coins[i]+1);
    for(top=n, i=0; i<n; ++i){
        for(j=2; j*coins[i][1]<=v; j+=j){
            coins[top][0]=coins[i][0]*j;
            coins[top][1]=coins[i][1]*j;
            ++top;
        }
    }
    n=top;
    /*
    for(i=0; i<n; ++i)
        printf("%d %d\n", coins[i][0], coins[i][1]);
    */
}

void dynamic_programming(void){
    int i,j;
    pig[0]=0;
    for(i=0; i<n; ++i){
        /*
        for(j=0; j<=v; ++j)
            printf("%d ", pig[j]);
        putchar('\n');
        */
        for(j=v; j>=coins[i][1]; --j)
            if(pig[j-coins[i][1]]!=-1&&(pig[j]==-1||pig[j]>pig[j-coins[i][1]]+coins[i][0]))
                pig[j]=pig[j-coins[i][1]]+coins[i][0];
    }
    if(pig[v]==-1)
        puts("This is impossible.");
    else
        printf("The minimum amount of money in the piggy-bank is %d.\n", pig[v]);
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1031.in", "rb", stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        dynamic_programming();
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

#include <stdio.h>
#include <string.h>
#define H 1000
#define N 10000

int food[N+10][2],score[H+10];
int k,f;

void dynamic_programming(void){
    int i,j;
    memset(score, -1, sizeof(score));
    score[0]=0;
    for(i=0; i<f; ++i){
        if(food[i][0]>=k)
            score[k]=score[k]>0?score[k]:0;
        if(score[k]>=0)
            score[k]+=food[i][1];
        for(j=k; j>=food[i][0]; --j){
            if(score[j-food[i][0]]>=0)
                score[j-food[i][0]]=score[j-food[i][0]];
        }
        for(j=0; j<=k; ++j)
            printf("%d ", score[j]);
        printf("\n");
    }
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1215.in", "rb", stdin);
#endif
    int t,i;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &k, &f);
        for(i=0; i<f; ++i)
            scanf("%d%d", food[i], food[i]+1);
        dynamic_programming();
        printf("%d\n", score[k]);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

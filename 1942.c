#include <stdio.h>
#include <string.h>

int A,B,C,N;
int DP[20][20][20],stack[20][20][20][100],list[50][3];

void dynamic_programming(void){
    int i,a,b,c;
    memset(DP, 0, sizeof(DP));
    memset(stack, 0, sizeof(stack));
    for(i=0; i<N; ++i){
        for(a=A-list[i][0]; a>=0; --a){
            for(b=B-list[i][1]; b>=0; --b){
                for(c=C-list[i][2]; c>=0; --c){
                    if(DP[a+list[i][0]][b+list[i][1]][c+list[i][2]]<DP[a][b][c]+1){
                        memcpy(stack[a+list[i][0]][b+list[i][1]][c+list[i][2]],
                                stack[a][b][c], sizeof(stack[0][0][0]));
                        stack[a+list[i][0]]
                            [b+list[i][1]][c+list[i][2]]
                            [++stack[a+list[i][0]][b+list[i][1]][c+list[i][2]][0]]=i;
                        DP[a+list[i][0]][b+list[i][1]][c+list[i][2]]=DP[a][b][c]+1;
                    }
                }
            }
        }
    }
    /*
    for(a=0; a<=A; ++a){
        for(b=0; b<=B; ++b){
            for(c=0; c<=C; ++c)
                printf("%d ", DP[a][b][c]);
            putchar('\n');
        }
        printf("----------------\n");
    }
    */
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1942.in", "rb", stdin);
#endif
    int i;
    while(scanf("%d%d%d", &A, &B, &C)==3&&(A||B||C)){
        scanf("%d", &N);
        for(i=0; i<N; ++i)
            scanf("%d%d%d", list[i], list[i]+1, list[i]+2);
        dynamic_programming();
        printf("%d\n", DP[A][B][C]);
        if(stack[A][B][C][0]){
            for(i=1; i<stack[A][B][C][0]; ++i)
                printf("%d ", stack[A][B][C][i]+1);
            printf("%d\n", stack[A][B][C][i]+1);
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

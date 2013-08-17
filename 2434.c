#include <stdio.h>
#include <string.h>
#define N 1000

int n;
int matrix[N][N],vis[N];
int list[N];
int queue[N+N];

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2434.in", "rb", stdin);
#endif
    int m,k,i,j,l,t,front,rear;
    while(scanf("%d%d", &m, &n)==2&&(m||n)){
        memset(matrix, 0, sizeof(matrix));
        memset(vis, 0, sizeof(vis));
        for(i=0; i<m; ++i){
            scanf("%d", &k);
            for(j=0; j<k; ++j)
                scanf("%d", list+j);
            for(j=0; j<k; ++j)
                for(l=0; l<j; ++l)
                    matrix[list[j]][list[l]]=matrix[list[l]][list[j]]=1;
        }
        if(n==1||matrix[0][n-1]==1){
            puts("I do know wywcgs!");
            continue;
        }
        front=rear=0;
        queue[front++]=0;
        while(rear<front){
            t=queue[rear++];
            if(matrix[t][n-1]==1)
                break;
            for(i=1; i<n-1; ++i)
                if(matrix[t][i]&&!vis[i]){
                    vis[i]=vis[t]+1;
                    queue[front++]=i;
                }
        }
        if(matrix[t][n-1]==1)
            printf("I can know wywcgs by at most %d person(s)!\n", vis[t]);
        else
            puts("I can never know wywcgs!");
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

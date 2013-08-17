#include <stdio.h>
#include <string.h>
#define N 1000

int n;
int monas[N],x[N],y[N];
int matrix[N][N],vis[N];

int dis(int a, int b){
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}

int dfs(int x){
    int i,sum;
    vis[x]=1;
    sum=monas[x];
    for(i=0; i<n; ++i)
        if(matrix[x][i]&&!vis[i])
            sum+=dfs(i);
    return sum;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2064.in", "rb", stdin);
#endif
    int i,j,index,max,p;
    while(scanf("%d", &n)==1&&n){
        memset(matrix, 0, sizeof(matrix));
        memset(vis, 0, sizeof(vis));
        for(i=0; i<n; ++i)
            scanf("%d%d%d", x+i, y+i, monas+i);
        for(i=0; i<n; ++i){
            for(j=0; j<i; ++j)
                if(dis(i, j)<=900)
                    matrix[i][j]=matrix[j][i]=1;
        }
        /*
        for(i=0; i<n; ++i){
            for(j=0; j<n; ++j)
                printf("%d ", matrix[i][j]);
            putchar('\n');
        }
        */
        for(max=i=0; i<n; ++i)
            if(!vis[i]){
                p=dfs(i);
                if(p>max){
                    max=p;
                    index=i;
                }
            }
        printf("%d %d\n", index+1, max);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

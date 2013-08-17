#include <stdio.h>
#define N 1000

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int r,c;
int vis[N][N+10];
char labyrinth[N][N+10];
char queue[N*N+10][2];
int dis[N*N+10];

int shortest(int x, int y, int v){
    int i,front,rear,max,tx,ty;
    max=front=rear=0;
    queue[front][0]=x;
    queue[front][1]=y;
    dis[front]=0;
    vis[x][y]=v;
    ++front;
    while(rear<front){
        tx=queue[rear][0];
        ty=queue[rear][1];
        for(i=0; i<4; ++i)
            if(0<=tx+dx[i]&&tx+dx[i]<r&&0<=ty+dy[i]&&ty+dy[i]<c&&
                    labyrinth[tx+dx[i]][ty+dy[i]]=='.'&&
                    vis[tx+dx[i]][ty+dy[i]]<v){
                vis[tx+dx[i]][ty+dy[i]]=v;
                queue[front][0]=tx+dx[i];
                queue[front][1]=ty+dy[i];
                dis[front]=dis[rear]+1;
                if(max<dis[front])
                    max=dis[front];
                ++front;
            }
        ++rear;
    }
    return max;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1030.in", "rb", stdin);
#endif
    int t,i,j,max,p,u;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &c, &r);
        for(i=0; i<r; ++i)
            scanf("%s", labyrinth[i]);
        max=u=0;
        for(i=0; i<r; ++i)
            for(j=0; j<c; ++j)
                if(labyrinth[i][j]=='.'){
                    p=shortest(i, j, ++u);
                    if(max<p)
                        max=p;
                }
        printf("Maximum rope length is %d.\n", max);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

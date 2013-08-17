#include <stdio.h>
#define N 30

typedef struct{
    int x,y,z,step;
}node;

node queue[30000];
char map[N][N][N+10];

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1448.in", "rb", stdin);
#endif
    int l,r,c;
    int i,j,k,front,rear,tx,ty,tz;
    node tmp;
    const int dx[]={-1,1,0,0,0,0};
    const int dy[]={0,0,1,-1,0,0};
    const int dz[]={0,0,0,0,1,-1};
    while(scanf("%d%d%d", &l, &r, &c)==3&&(l||r||c)){
        for(k=0; k<l; ++k)
            for(i=0; i<r; ++i)
                scanf("%s", map[k][i]);
        front=rear=0;
        for(k=0; k<l; ++k)
            for(i=0; i<r; ++i)
                for(j=0; j<c; ++j){
                    if(map[k][i][j]=='S'){
                        queue[front].x=i;
                        queue[front].y=j;
                        queue[front].z=k;
                        queue[front].step=0;
                    }else if(map[k][i][j]=='E'){
                        tx=i;
                        ty=j;
                        tz=k;
                    }
                }
        map[queue[front].z][queue[front].x][queue[front].y]='*';
        ++front;
        while(rear<front){
            tmp=queue[rear++];
            if(tmp.x==tx&&tmp.y==ty&&tmp.z==tz)
                break;
            for(i=0; i<6; ++i)
                if(0<=tmp.x+dx[i]&&tmp.x+dx[i]<r&&
                        0<=tmp.y+dy[i]&&tmp.y+dy[i]<c&&
                        0<=tmp.z+dz[i]&&tmp.z+dz[i]<l&&
                        (map[tmp.z+dz[i]][tmp.x+dx[i]][tmp.y+dy[i]]!='#'&&
                         map[tmp.z+dz[i]][tmp.x+dx[i]][tmp.y+dy[i]]!='*')){
                    map[tmp.z+dz[i]][tmp.x+dx[i]][tmp.y+dy[i]]='*';
                    queue[front].x=tmp.x+dx[i];
                    queue[front].y=tmp.y+dy[i];
                    queue[front].z=tmp.z+dz[i];
                    queue[front].step=tmp.step+1;
                    ++front;
                }
        }
        if(tmp.x==tx&&tmp.y==ty&&tmp.z==tz)
            printf("Escaped in %d minute(s).\n", tmp.step);
        else
            puts("Trapped!");
        /*
        for(k=0; k<l; ++k){
            for(i=0; i<r; ++i)
                printf("%s\n", map[k][i]);
            putchar('\n');
        }
        */

    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

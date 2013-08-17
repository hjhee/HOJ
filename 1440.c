#include <stdio.h>
#include <string.h>

typedef struct{
    int x,y,step;
}node;

node queue[100];

int map[8][8];

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1440.in", "rb", stdin);
#endif
    int tx,ty,front,rear,i;
    char l[10],h[10];
    const int dx[]={1,2,1,2,-1,-2,-1,-2},dy[]={2,1,-2,-1,2,1,-2,-1};
    node tmp;
    while(scanf("%s%s", l, h)!=EOF){
        memset(map, 0, sizeof(map));
        tx=h[0]-'a';
        ty=h[1]-'1';
        front=rear=0;
        queue[front].x=l[0]-'a';
        queue[front].y=l[1]-'1';
        queue[front].step=0;
        map[queue[front].x][queue[front].y]=1;
        ++front;
        while(rear<front){
            tmp=queue[rear++];
            if(tmp.x==tx&&tmp.y==ty)
                break;
            else{
                for(i=0; i<8; ++i){
                    if(0<=tmp.x+dx[i]&&tmp.x+dx[i]<8&&0<=tmp.y+dy[i]&&
                            tmp.y+dy[i]<8&&!map[tmp.x+dx[i]][tmp.y+dy[i]]){
                        queue[front].x=tmp.x+dx[i];
                        queue[front].y=tmp.y+dy[i];
                        queue[front].step=tmp.step+1;
                        map[queue[front].x][queue[front].y]=1;
                        ++front;
                    }
                }
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n",
                l, h, tmp.step);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

#include <stdio.h>
#include <string.h>
#define B 5 
#define W 3

int n;
int map[20][20],bvis[20][20],wvis[20][20];

void flood_fill(int x, int y, int v){
    int i,tx,ty;
    const int dx[]={0,0,1,-1};
    const int dy[]={1,-1,0,0};
    if(v==B)
        bvis[x][y]=1;
    else
        wvis[x][y]=1;
    for(i=0; i<4; ++i){
        tx=x+dx[i];
        ty=y+dy[i];
        if(0<=tx&&tx<n&&0<=ty&&ty<n&&((v==W&&!wvis[tx][ty])||
                    (v==B&&!bvis[tx][ty]))&&
                map[tx][ty]!=B&&map[tx][ty]!=W){
            if(map[tx][ty]==-1)
                map[tx][ty]+=v;
            else if(v==B&&map[tx][ty]==W-1)
                map[tx][ty]+=v;
            else if(v==W&&map[tx][ty]==B-1)
                map[tx][ty]+=v;
            flood_fill(tx, ty, v);
        }
    }
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2581.in", "rb", stdin);
#endif
    int w,b,r,c,i,j,bfill,wfill;
    while(scanf("%d", &n)==1&&n){
        memset(map, -1, sizeof(map));
        memset(bvis, 0, sizeof(bvis));
        memset(wvis, 0, sizeof(wvis));
        scanf("%d%d", &b, &w);
        for(i=0; i<b; ++i){
            scanf("%d%d", &r, &c);
            map[r-1][c-1]=B;
        }
        for(i=0; i<w; ++i){
            scanf("%d%d", &r, &c);
            map[r-1][c-1]=W;
        }
        for(i=0; i<n; ++i)
            for(j=0; j<n; ++j)
                if(map[i][j]==W||map[i][j]==B)
                    flood_fill(i, j, map[i][j]);
        for(bfill=wfill=i=0; i<n; ++i)
            for(j=0; j<n; ++j){
                if(map[i][j]==B-1)
                    ++bfill;
                else if(map[i][j]==W-1)
                    ++wfill;
            }
        /*
        for(i=0; i<n; ++i){
            for(j=0; j<n; ++j)
                printf("%d ", map[i][j]);
            putchar('\n');
        }
        */
        if(bfill==wfill)
            puts("Draw");
        else if(bfill>wfill)
            printf("Black wins by %d\n", bfill-wfill);
        else
            printf("White wins by %d\n", wfill-bfill);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

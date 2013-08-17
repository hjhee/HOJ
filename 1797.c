#include <stdio.h>
#define N 20

int w,h;
char map[N][N+10];

int dfs(int x, int y){
    int m,i;
    static const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    map[x][y]='*';
    m=1;
    for(i=0; i<4; ++i){
        if(0<=x+dx[i]&&x+dx[i]<h&&0<=y+dy[i]&&y+dy[i]<w
                &&map[x+dx[i]][y+dy[i]]=='.')
            m+=dfs(x+dx[i], y+dy[i]);
    }
    return m;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1797.in", "rb", stdin);
#endif
    int i,j,x,y;
    while(scanf("%d%d", &w, &h)==2&&(w||h)){
        for(i=0; i<h; ++i){
            scanf("%s", map[i]);
            for(j=0; j<w; ++j)
                if(map[i][j]=='@'){
                    x=i;
                    y=j;
                }
        }
        printf("%d\n", dfs(x, y));
        /*
        for(i=0; i<h; ++i)
            printf("%s\n", map[i]);
        */
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

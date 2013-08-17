#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 1024
#define N 15000

typedef struct{
    int x,y,z;
}coordinate;

int indx[L+10][L+10],n;
int level[N+10];
coordinate stars[N+10];

int cmp_stars(const void *_a, const void *_b){
    coordinate *a,*b;
    a=(coordinate *)_a;
    b=(coordinate *)_b;
    if(a->z==b->z){
        if(a->x==b->x)
            return a->y-b->y;
        return a->x-b->x;
    }else
        return a->z-b->z;
}

int lowbit(int x){
    return x&((~x)+1);
}

void insert(int x, int y){
    int i,j;
    for(i=x; i<=L; i+=lowbit(i))
        for(j=y; j<=L; j+=lowbit(j))
            ++indx[i][j];
}

int sum(int x, int y){
    int i,j,s;
    s=0;
    for(i=x; i>0; i-=lowbit(i))
        for(j=y; j>0; j-=lowbit(j))
            s+=indx[i][j];
    return s;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2678.in", "rb", stdin);
#endif
    int i;
    while(scanf("%d", &n)==1){
        memset(level, 0, sizeof(level));
        memset(indx, 0, sizeof(indx));
        for(i=0; i<n; ++i){
            scanf("%d%d%d", &stars[i].x, &stars[i].y, &stars[i].z);
            ++stars[i].x;
            ++stars[i].y;
        }
        qsort(stars, n, sizeof(coordinate), cmp_stars);
        /*
        for(i=0; i<n; ++i)
            printf("%d %d %d\n", stars[i].x, stars[i].y, stars[i].z);
        */
        for(i=0; i<n; ++i){
            ++level[sum(stars[i].x, stars[i].y)];
            insert(stars[i].x, stars[i].y);
            /*
            for(j=0; j<n; ++j)
                printf("%d ", level[j]);
            putchar('\n');
            */
        }
        printf("%d", level[0]);
        for(i=1; i<n; ++i)
            printf(" %d", level[i]);
        putchar('\n');
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

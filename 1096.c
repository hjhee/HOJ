#include <stdio.h>
#define EPS 1e-2
#define N 500

typedef struct{
    int x,y,r;
}coordinate;

void block(cooridinate *interval, coordinate *c, coorindate b){
    double x,k;
    k=b.y-c->y;
    k/=b.x-c->x;
    for(x=b.x-b.y/k; ((c->y-b.y)*(c->y-b.y)+k*k*(c->x-b.x)*(c->x-b.x)-2*k*(c->x-b.x)*(c->y-b.y))/(k*k+1)-c->r*c->r<=0; x-=EPS);
    interval->x=x+EPS;
    for(x=b.x-b.y/k; ((c->y-b.y)*(c->y-b.y)+k*k*(c->x-b.x)*(c->x-b.x)-2*k*(c->x-b.x)*(c->y-b.y))/(k*k+1)-c->r*c->r<=0; x+=EPS);
    interval->y=x-EPS;
}

int main(void){
    int n,i;
    coordinate b,c[N],interval[N];
    while(scanf("%d", &n), n){
        scanf("%d%d", &b.x, &b.y);
        for(i=0; i<n; ++i){
            scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].r);
            block(interval+i, c+i, b);
            n=compose(interval, n);
        }
        for(i=0; i<n; ++i)
            printf("%.2f %.2f\n", ((double)interval[i].x)/100, ((double)interval[i].y)/100);
        putchar('\n');
    }
    return 0;
}

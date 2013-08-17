#include <stdio.h>
#define L 262144

typedef struct{
    int l,r;
    int c,i;
}node;

node segment[L+10];

void init(int i, int l, int r){
    if(l>r)
        return;
    segment[i].l=l;
    segment[i].r=r;
    segment[i].c=1;
    segment[i].i=1;
    if(l!=r){
        init(i<<1, l, (l+r)>>1);
        init(i<<1|1, ((l+r)>>1)+1, r);
    }
}

void update(int i){
    if(segment[i].i){
        segment[i<<1].c=segment[i].c;
        segment[i<<1].i=1;
        segment[i<<1|1].c=segment[i].c;
        segment[i<<1|1].i=1;
        segment[i].i=0;
    }
}

void paint(int i, int l, int r, int c){
    int m;
    if(l>r||segment[i].l>r||segment[i].r<l)
        return;
    /*
    printf("[%d, %d, %d]->[%d, %d, %d, %d]\n", l, r, c,
            segment[i].l, segment[i].r, segment[i].c, segment[i].i);
            */
    if(l<=segment[i].l&&segment[i].r<=r){
        segment[i].c=1<<c;
        segment[i].i=1;
        return;
    }
    m=(segment[i].l+segment[i].r)>>1;
    update(i);
    if(l<=m)
        paint(i<<1, l, r, c);
    if(r>m)
        paint(i<<1|1, l, r, c);
    segment[i].c=segment[i<<1].c|segment[i<<1|1].c;
}

int stat(int i, int l, int r){
    int m,c;
    if(l>r||segment[i].l>r||segment[i].r<l)
        return 0;
    /*
    printf("[%d, %d]->[%d, %d, %d, %d]\n", l, r,
            segment[i].l, segment[i].r, segment[i].c, segment[i].i);
            */
    if(l<=segment[i].l&&segment[i].r<=r)
        return segment[i].c;
    update(i);
    m=(segment[i].l+segment[i].r)>>1;
    c=0;
    if(l<=m)
        c|=stat(i<<1, l, r);
    if(r>m)
        c|=stat(i<<1|1, l, r);
    return c;
}

int main(void){
    int l,t,o,x,y,c,u;
    char command[30];
#ifndef ONLINE_JUDGE
    freopen("2685.in", "rb", stdin);
#endif
    while(scanf("%d%d%d", &l, &t, &o)==3){
        init(1, 1, l);
        while(o--){
            scanf("%s", command);
            if(command[0]=='C'){
                scanf("%d%d%d", &x, &y, &c);
                paint(1, x, y, c);
            }else{
                scanf("%d%d", &x, &y);
                u=stat(1, x, y);
                for(c=0; u>0; u>>=1)
                    c+=u&1;
                printf("%d\n", c);
            }
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

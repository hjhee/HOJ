#include <stdio.h>
#include <stdlib.h>
#define N 1000000
#define SGN(p, q) (((p)==(q))?0:(((p)>(q))?1:-1))

typedef struct{
    unsigned a,b;
}segment;

segment seg[N+10];

int cmp_ipseg(const void *_x, const void *_y){
    segment *x,*y;
    x=(segment *)_x;
    y=(segment *)_y;
    if(x->a==y->a)
        return SGN(x->b, y->b);
    return SGN(x->a, y->a);
}

void transform(int (*q)[4], segment *u){
    int i;
    unsigned p;
    for(p=1, u->a=u->b=0, i=3; i>-1; --i, p*=256){
        u->a+=p*q[0][i];
        u->b+=p*q[1][i];
    }
    if(u->a>u->b){
        p=u->a;
        u->a=u->b;
        u->b=p;
    }
}

void combine(segment *seg, int *n){
    int i,j;
    unsigned exr,exl;
    for(exl=seg[i=j=0].a, exr=seg[0].b; i<(*n); ++i){
        if(exr>=seg[i].a){
            if(exr<seg[i].b)
                exr=seg[i].b;
        }else{
            seg[j].a=exl;
            seg[j].b=exr;
            exl=seg[i].a;
            exr=seg[i].b;
            ++j;
        }
    }
    seg[j].a=exl;
    seg[j].b=exr;
    ++j;
    *n=j;
}

int search(long long w, int n){
    int m,r,l;
    l=0;
    r=n-1;
    while(l<=r){
        m=(r+l)/2;
        if(w>seg[m].b)
            l=m+1;
        else if(seg[m].a<=w)
            return m;
        else
            r=m-1;
    }
    return m;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2278.in", "rb", stdin);
#endif
    int n,ip[4],s[2][4],i;
    unsigned p,w;
    char input[200];
    n=0;
    while(1){
        fgets(input, 200, stdin);
        if(input[0]=='#')
            break;
        sscanf(input, "%d.%d.%d.%d %d.%d.%d.%d", s[0], s[0]+1, s[0]+2, s[0]+3,
                s[1], s[1]+1, s[1]+2, s[1]+3);
        transform(s, seg+n);
        ++n;
    }
    qsort(seg, n, sizeof(segment), cmp_ipseg);
#ifdef DEBUG
    for(i=0; i<n; ++i)
        printf("%3d: %17u %17u\n", i, seg[i].a, seg[i].b);
    printf("00000000000\n");
#endif
    combine(seg, &n);
#ifdef DEBUG
    for(i=0; i<n; ++i)
        printf("%3d: %17u %17u\n", i, seg[i].a, seg[i].b);
    printf("-----------\n");
#endif
    while(fgets(input, 200, stdin)!=NULL){
        sscanf(input, "%d.%d.%d.%d", ip, ip+1, ip+2, ip+3);
        for(p=1, w=0, i=3; i>-1; --i, p*=256)
            w+=p*ip[i];
        i=search(w, n);
        printf("%s\n", (seg[i].a<=w&&w<=seg[i].b)?"yes":"no");
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

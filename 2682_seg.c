#include <stdio.h>
#include <string.h>
#define N 16384

typedef struct{
    int l,r,c,lazy;
    int left,right;
}node;

int top;
node seg[N+10];

int init(int l, int r){
    int t;
    /* printf("%d %d\n", l, r); */
    if(l<r){
        t=top;
        ++top;
        seg[t].l=l;
        seg[t].r=r;
        seg[t].c=0;
        seg[t].lazy=0;
        seg[t].left=init(l, (l+r)/2);
        seg[t].right=init((l+r)/2+1, r);
        return t;
    }else if(l==r){
        t=top;
        ++top;
        seg[t].l=l;
        seg[t].r=r;
        seg[t].c=0;
        seg[t].lazy=0;
        seg[t].left=seg[t].right=0;
        return t;
    }
    return 0;
}

void flip(int i, int l, int r){
    /* printf("[%d, %d]->[%d, %d, %d, %d]\n", l, r, seg[i].l, seg[i].r, seg[i].c, seg[i].lazy); */
    if(l>r||seg[i].l>r||seg[i].r<l)
        return;
    if(seg[i].l==seg[i].r){
        ++seg[i].c;
        /* printf("flip\n"); */
    }else{
        if(seg[i].lazy==0){
            if(l<=seg[i].l&&seg[i].r<=r){
                ++seg[i].c;
                seg[i].lazy=1;
            }else{
                if(l<seg[i].l)
                    l=seg[i].l;
                if(r>seg[i].r)
                    r=seg[i].r;
                flip(seg[i].left, l, r);
                flip(seg[i].right, l, r);
            }
        }else{
            seg[i].lazy=0;
            seg[i].c=0;
            /*
            printf("lazy!\n");
            */
            flip(seg[i].left, seg[i].l, seg[i].r);
            flip(seg[i].right, seg[i].l, seg[i].r);
            flip(seg[i].left, l, r);
            flip(seg[i].right, l, r);
            /*
            printf("lazy end\n");
            */
        }
    }
}

int sum(int i, int l, int r){
    if(l>r||seg[i].l>r||seg[i].r<l)
        return 0;
    /*
    printf("[%d, %d]->[%d, %d, %d, %d]\n", l, r, seg[i].l, seg[i].r, seg[i].c, seg[i].lazy);
    */
    if(seg[i].l==seg[i].r)
        return seg[i].c;
    else{
        if(seg[i].lazy==0)
            return sum(seg[i].left, l, r)+sum(seg[i].right, l, r);
        else{
            if(l<seg[i].l)
                l=seg[i].l;
            if(r>seg[i].r)
                r=seg[i].r;
            return seg[i].c+sum(seg[i].left, l, r)+sum(seg[i].right, l, r);
        }
    }
    return 0;
}

void view(int x, int y){
    int i;
    printf("x: %d, y: %d\n", x, y);
    for(i=0; i<top; ++i)
        printf("(%d, %d, %d, %d)\n", seg[i].l, seg[i].r, seg[i].c, seg[i].lazy);
    printf("-------------\n");
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2682.in", "rb", stdin);
#endif
    int n,m,x,y,c,i;
    while(scanf("%d%d", &n, &m)==2){
        top=0;
        memset(seg, 0, sizeof(seg));
        init(1, n);
        /* printf("top: %d\n",  top); */
        while(m--){
            scanf("%d%d", &x, &y);
            flip(0, x, y); 
        }
        /*
        for(i=1; i<=n; ++i)
            printf("%d: %d\n", i, sum(0, i, i));
        */
        for(c=0, i=1; i<=n; ++i)
            if(sum(0, i, i)&1)
                ++c;
        printf("%d\n", n-c);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

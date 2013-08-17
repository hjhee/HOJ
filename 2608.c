#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
#define MAX(a, b) (((a)>(b))?(a):(b))

typedef struct{
    int price;
    long long quality;
}component;

int n;
long long b,qmax;

component device[N+10][N+10];

int ttop;
int typenum[N+10];
char typelist[N+10][30];

int cmp_component(const void *_a, const void *_b){
    component *a,*b;
    a=(component *)_a;
    b=(component *)_b;
    return a->price-b->price;
    /*
    if(a->quality==b->quality)
        return a->price-b->price;
    */
    return (a->quality>b->quality)?1:-1;
}

void list(void){
    int i,j;
    for(i=0; i<ttop; ++i){
        puts(typelist[i]);
        for(j=0; j<typenum[i]; ++j)
            printf("%d %lld\n", device[i][j].price, device[i][j].quality);
        printf("\n");
    }
}

void build(void){
    int i,j,k,price;
    long long quality;
    char type[30];
    memset(typenum, 0, sizeof(typenum));
    qmax=0;
    ttop=0;
    for(i=0; i<n; ++i){
        scanf("%s%*s%d%lld", type, &price, &quality);
        qmax+=quality;
        for(j=0; j<ttop; ++j){
            for(k=0; type[k]!='\0'&&type[k]==typelist[j][k]; ++k);
            if(type[k]=='\0'&&typelist[j][k]=='\0')
                break;
        }
        if(j==ttop){
            ++ttop;
            for(k=0; type[k]!='\0'; ++k)
                typelist[j][k]=type[k];
            typelist[j][k]='\0';
        }
        for(k=0; k<typenum[j]; ++k)
            if(device[j][k].price==price)
                break;
        if(k==typenum[j]){
            device[j][typenum[j]].price=price;
            device[j][typenum[j]].quality=quality;
            ++typenum[j];
        }else
            device[j][k].quality=MAX(device[j][k].quality, quality);
    }
    for(i=0; i<ttop; ++i)
        qsort(device[i], typenum[i], sizeof(component), cmp_component);
}

int confirm(long long q, int l, long long rest){
    int i,j,f;
    for(i=0; i<l; ++i){
        f=0;
        if(rest<0)
            return 0;
        for(j=0; j<typenum[i]&&device[i][j].price<=rest; ++j)
            if(q<=device[i][j].quality){
                f=1;
                rest-=device[i][j].price;
                break;
            }
        if(!f)
            return 0;
    }
    return 1;
    /*
    int i;
    if(l==ttop)
        return 1;
    for(i=0; i<typenum[l]&&device[l][i].price<=rest; ++i)
        if(q<=device[l][i].quality)
            return confirm(q, l+1, rest-device[l][i].price);
    return 0;
    */
}

void test(void){
    int result,found;
    long long l,r,m,q;
    found=0;
    l=0;
    r=qmax;
    while(l<=r){
        m=(r+l)>>1;
        result=confirm(m, ttop, b);
        if(result==1){
            l=m+1;
            q=m;
            found=1;
        }else
            r=m-1;
    }
    if(found)
        printf("%lld\n", q);
    else
        printf("0\n");
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2608.in", "rb", stdin);
#endif
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d%lld", &n, &b);
        build();
        test();
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

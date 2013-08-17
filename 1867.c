#include <stdio.h>
#include <string.h>
#define N 1048576
#define P 4000000
#define T 500

int shop[N+10],array[N+10],c;
int vis[P+10],prime[T+10],top;

/*
void init(void){
    int i,j;
    vis[0]=vis[1]=1;
    for(i=2; i<=P; ++i)
        if(!vis[i]){
            if(top<=T)
                prime[top++]=i;
            prime[top++]=i;
            for(j=i+i; j<=P; j+=i)
                vis[j]=1;
        }
}

int isprime(int x){
    int i;
    if(x<=P)
        return !vis[x];
    for(i=0; i<=T; ++i)
        if(x%prime[i]==0)
            return 0;
    return 1;
}
*/

int isprime(int x){
    int i;
    if(x<=1)
        return 0;
    for(i=2; i*i<=x; ++i)
        if(x%i==0)
            return 0;
    return 1;
}

int lowbit(int x){
    return x&((~x)+1);
}

void modify(int x, int d){
    for(; x<=c; x+=lowbit(x))
        array[x]+=d;
}

int sum(int x){
    int s;
    for(s=0; x>0; x-=lowbit(x))
        s+=array[x];
    return s;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1867.in", "rb", stdin);
#endif
    int n,m,command,x,y,test,i;
    test=1;
    while(scanf("%d%d%d", &c, &n, &m)==3&&(c||n||m)){
        memset(array, 0, sizeof(array));
        memset(shop, 0, sizeof(shop));
        if(isprime(m))
            for(i=1; i<=c; ++i)
                array[i]=lowbit(i);
        for(i=1; i<=c; ++i)
            shop[i]=m;
        printf("CASE #%d:\n", test++);
        while(n--){
            scanf("%d%d%d", &command, &x, &y);
            if(command)
                printf("%d\n", sum(y)-sum(x-1));
            else{
                if(isprime(shop[x])&&!isprime(shop[x]+y))
                    modify(x, -1);
                else if(!isprime(shop[x])&&isprime(shop[x]+y))
                    modify(x, 1);
                shop[x]+=y;
            }
        }
        putchar('\n');
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

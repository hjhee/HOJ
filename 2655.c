#include <stdio.h>
#define M 10000
#define N 1300

int top;
int list[10010],prime[N];
int matrix[N][N];

int adj(int x, int y){
    int i,d;
    char sx[10],sy[10];
    sprintf(sx, "%04d", x);
    sprintf(sy, "%04d", y);
    for(d=i=0; i<4; ++i)
        if(sx[i]!=sy[i])
            ++d;
    return d==1;
}

void build_graph(void){
    int i,j,s;
    for(i=2; i<M; ++i){
        if(!list[i]){
            for(j=i+i; j<=M; j+=i)
                list[j]=1;
            prime[top++]=i;
        }
    }

    for(i=0; prime[i]<1000; ++i);
    for(s=i; i<top; ++i){
        matrix[i][i]=1;
        for(j=s; j<i; ++j)
            matrix[i][j]=matrix[j][i]=adj(prime[i], prime[j]);
    }
}

int search(int x){
    int l,r,m;
    l=0;
    r=1228;
    while(l<=r){
        m=(r+l)/2;
        if(prime[m]>x)
            r=m-1;
        else if(x==prime[m])
            return m;
        else
            l=m+1;
    }
    return m;
}

int dis(int x, int y){
    int front,rear,tmp,i;
    int queue[N],dis[N],vis[N]={0};
    front=rear=0;
    queue[front]=x;
    dis[front]=0;
    vis[x]=1;
    ++front;
    while(rear<front){
        tmp=queue[rear];
        if(matrix[tmp][y])
            return dis[rear]+1;
        for(i=0; i<top; ++i)
            if(!vis[i]&&matrix[tmp][i]){
                vis[i]=1;
                queue[front]=i;
                dis[front]=dis[rear]+1;
                ++front;
            }
        ++rear;
    }
    return -1;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2655.in", "rb", stdin);
#endif
    int test,a,b,ia,ib,d;
    build_graph();
    scanf("%d", &test);
    while(test--){
        scanf("%d%d", &a, &b);
        ia=search(a);
        ib=search(b);
        if(a==b){
            puts("0");
            continue;
        }
        d=dis(ia, ib);
        if(d==-1)
            puts("Impossible");
        else
            printf("%d\n", d);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

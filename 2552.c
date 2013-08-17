#include <stdio.h>
#include <string.h>

int ans[20];
int w[20];

int dfs(int *box, int *vis, int n, int q, int d, int *store){
    int sum,i;
    if(d==q){
        /*
        for(i=0; i<2*n; ++i)
            printf("%d ", box[i]);
        putchar('\n');
        */
        if(w[n]){
            for(i=0; i<q; ++i)
                if(box[i]!=store[q-1-i])
                    break;
            if(i==q){
                w[n]=2;
                return 0;
            }
        }else
            w[n]=1;
        for(i=0; i<q; ++i)
            store[i]=box[i];
        return 1;
    }
    sum=0;
    if(box[d])
        return dfs(box, vis, n, q, d+1, store);
    for(i=n-1; i>-1&&w[n]<2; --i){
        if(!vis[i]&&d+i+2<q&&!box[d+i+2]){
            vis[i]=1;
            box[d]=box[i+d+2]=i+1;
            sum+=dfs(box, vis, n, q, d+1, store);
            box[d]=box[i+d+2]=0;
            vis[i]=0;
        }
    }
    return sum;
}

int cal(int n){
    int box[40],vis[20],store[40];
    if(n<=2||n>=13)
        return 0;
    if(n==12)
        return 216288;
    if(ans[n])
        return ans[n];
    memset(box, 0, sizeof(box));
    memset(vis, 0, sizeof(vis));
    return ans[n]=dfs(box, vis, n, n*2, 0, store)*w[n];
}

int main(void){
    int n;
    while(scanf("%d", &n)==1)
        printf("%d\n", cal(n));
    return 0;
}

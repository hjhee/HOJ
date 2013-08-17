#include <stdio.h>
#include <string.h>
#define N 10000

int n,sequence[N+10],rev[N+10],DPA[N+10],DPB[N+10],stack[N+10],top;

void print_stack(int *seq){
    int i;
    printf("stack: ");
    for(i=0; i<top; ++i)
        printf("%d ", seq[stack[i]]);
    printf("\n");
}

int binsearch(int *stack, int top, int *seq, int x){
    int l,r,m;
    l=0;
    r=top-1;
    while(l<=r){
        m=(l+r)>>1;
        if(x>seq[stack[m]])
            l=m;
        else
            r=m-1;
    }
    /*
    printf("not found: %d, but found %d, \nwhose previous one is %d\n", x, sequence[stack[m]],
            sequence[stack[m-1]]);
    */
    /* ugly fix, looking for better solution */
    while(m<top&&seq[stack[m]]<x)
        ++m;
    return m;
}

void dynamic_programming(int *DP, int *seq){
    int i,t;
    memset(DP, 0, sizeof(DPA));
    top=0;
    for(i=0; i<n; ++i){
        if(top){
            if(seq[i]>seq[stack[top-1]]){
                DP[i]=top;
                stack[top++]=i;
            }else{
                t=binsearch(stack, top, seq, seq[i]);
                DP[i]=t;
                stack[t]=i;
            }
        }else
            stack[top++]=i;
        print_stack(seq);
    }
    /*
    for(i=0; i<n; ++i)
        printf("%d ", seq[i]);
    printf("\n");
    for(i=0; i<n; ++i)
        printf("%d ", DP[i]);
    printf("\n");
    */
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2085.in", "rb", stdin);
#endif
    int i,max,l;
    while(scanf("%d", &n)==1){
        for(i=0; i<n; ++i){
            scanf("%d", sequence+i);
            rev[n-i-1]=sequence[i];
        }
        dynamic_programming(DPA, sequence);
        dynamic_programming(DPB, rev);
        for(max=-1, i=0; i<n; ++i){
            l=DPA[i]>DPB[n-1-i]?DPB[n-1-i]:DPA[i];
            if(l>max)
                max=l;
        }
        printf("%d\n", max*2+1);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

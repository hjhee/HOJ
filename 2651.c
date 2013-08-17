#include <stdio.h>
#define EPS 1e-11
#define N 10000
#define PI 3.14159265358979323846264338327950288419716939

int p[N+10];

double search(int n, int f){
    int i,c;
    double l,r,m;
    l=0;
    r=N+1;
    while(r-l>EPS){
        m=(r+l)/2;
        for(c=i=0; i<n; ++i)
            c+=p[i]/m*p[i]/m;
        if(c<f)
            r=m;
        else
            l=m;
    }
    return m;
}

int main(void){
    int test,n,f,i;
    double q;
    scanf("%d", &test);
    while(test){
        scanf("%d%d", &n, &f);
        for(i=0; i<n; ++i)
            scanf("%d", p+i);
        q=search(n, f+1);
        printf("%.4f\n", q*q*PI);
        --test;
    }
    return 0;
}

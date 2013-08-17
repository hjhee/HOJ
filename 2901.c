#include <stdio.h>

long long mod(long long x, long long b, long long m){
    long long k;
    if(b==0)
        return 1;
    if(b==1)
        return x%m;
    k=((mod(x, b>>1, m)*x)%m);
    if(b&1)
        return ((k*k)%m*x)%m;
    else
        return (k*k)%m;
}

int main(void){
    long long a,b;
    while(scanf("%lld%lld", &a, &b)==2){
        if(a&1)
            puts("0");
        else
            printf("%lld\n", mod(a>>1, b, a));
    }
    return 0;
}

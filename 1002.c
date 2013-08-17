#include <stdio.h>

int main(void){
    long long a,b,c;
    while(scanf("%lld%lld%lld", &a, &b, &c)!=EOF)
        printf("%lld\n", a+b+c);
    return 0;
}


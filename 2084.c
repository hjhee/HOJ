#include <stdio.h>

unsigned long long f(int n){
	unsigned long long ans,tmp;
	ans=0;
	tmp=1;
	tmp=n*n;
	ans+=tmp<<3;
	tmp*=n;
	ans+=tmp*12;
	tmp*=n;
	ans+=tmp*3;
	tmp*=n*n;
	ans+=tmp;
	return ans/24;
}

int main(void){
	int n;
	while(scanf("%d", &n)!=EOF&&n)
		printf("%llu\n", f(n));
	return 0;
}

#include <stdio.h>

void init(int c, unsigned long long power[]){
	int i;
	power[0]=1;
	for(i=1; i<=32; ++i)
		power[i]=power[i-1]*c;
}

int gcd(int a, int b){
	int r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main(void){
	int i,c,s;
	unsigned long long ans,power[40];
	while(scanf("%d%d", &c, &s), c+s){
		init(c, power);
		for(ans=0, i=1; i<=s; ++i)
			ans+=power[gcd(s,i)];
		if(s&1)
			ans+=s*power[(s+1)>>1];
		else
			ans+=(s>>1)*(power[(s+2)>>1]+power[s>>1]);
		printf("%llu\n", ans/(s<<1));	
	}
	return 0;
}

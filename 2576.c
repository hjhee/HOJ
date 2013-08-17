#include <stdio.h>
#define N 12

int x[N],n,m;
unsigned long long delta;

unsigned long long gcd(unsigned long long a, unsigned long long b){
	unsigned long long r;
	if(b>a){
		r=b;
		b=a;
		a=r;
	}
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

void comb(int c, int s, int z){
	int i;
	static unsigned long long factor[N];
	unsigned long long lcm;
	if(c==z){
		for(lcm=1, i=0; i<z; ++i)
			lcm=(lcm*factor[i])/gcd(lcm,factor[i]);
		delta+=m/lcm;
		return;
	}
	for(i=s+1; i<n; ++i){
		factor[c]=x[i];
		comb(c+1, i, z);
	}
}

int main(void){
	int c,i;
	unsigned long long ans;
	scanf("%d", &c);
	while(c--){
		scanf("%d%d", &n, &m);
		for(i=0; i<n; ++i)
			scanf("%d", x+i);
		for(ans=0, i=1; i<=n; ++i){
			delta=0;
			comb(0, -1, i);
			if(i&1)
				ans=ans+delta;
			else
				ans=ans-delta;
		}
		printf("%llu\n", ans);
	}
	return 0;
}

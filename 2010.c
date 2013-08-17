#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 300000
#define Q 3500000

int top,prime[N],vis[Q],dtop;
unsigned long long a,b,p[N][2],base,diff[N][2],gcd,lcm;

void generate_prime(void){
	int i,j;
	prime[0]=2;
	for(top=1, i=3; i<Q; ++i)
		if(i&1&&!vis[i]){
			prime[top++]=i;
			for(j=i; j<Q; j+=i)
				vis[j]=1;
		}
}

void perm(unsigned long long tmpa, int cur){
	unsigned long long tmpb;
	if(cur>=dtop){
		tmpa*=diff[cur][0];
		tmpb=lcm/tmpa*gcd;
		if(tmpa>lcm||tmpb>lcm||tmpa<gcd||tmpb<gcd)
			return;
#ifdef DEBUG
		printf("sum: %12llu, tmpa: %10llu, tmpb: %10llu\n", tmpa+tmpb, tmpa, tmpb);
#endif
		if(tmpa+tmpb<a+b){
			a=tmpa;
			b=tmpb;
		}
	}else{
		perm(tmpa*diff[cur][0],cur+1);
		perm(tmpa*diff[cur][1],cur+1);
	}
}

int main(void){
	int i;
	unsigned long long swap,bound,tgcd,tlcm,tmp;
	generate_prime();
	while(scanf("%llu%llu", &gcd, &lcm)!=EOF){
		if(gcd==lcm){
			printf("%llu %llu\n", gcd, lcm);
			continue;
		}
		bound=sqrt((double)lcm)+3;
		tgcd=gcd;
		tlcm=lcm;
		for(i=0; i<top&&prime[i]<bound; ++i){
			tmp=prime[i];
			for(p[i][0]=1; tgcd%tmp==0; tgcd/=tmp)
				p[i][0]*=tmp;
			for(p[i][1]=1; tlcm%tmp==0; tlcm/=tmp)
				p[i][1]*=tmp;
		}
		bound=i;
		for(base=1, dtop=i=0; i<bound; ++i){
			if(p[i][0]==p[i][1])
				base*=p[i][0];
			else{
				diff[dtop][0]=p[i][0];
				diff[dtop][1]=p[i][1];
				++dtop;
			}
		}
#ifdef DEBUG
		printf("gcd: ");
		for(i=0; i<top&&prime[i]<bound; ++i)
			printf("%llu ", p[i][0]);
		putchar('\n');
		printf("lcm: ");
		for(i=0; i<top&&prime[i]<bound; ++i)
			printf("%llu ", p[i][1]);
		putchar('\n');
		printf("diff: ");
		for(i=0; i<dtop; ++i)
			printf("%llu ", diff[i][0]);
		putchar('\n');
		printf("diff: ");
		for(i=0; i<dtop; ++i)
			printf("%llu ", diff[i][1]);
		putchar('\n');
#endif
		a=b=((unsigned long long)1<<63)-1;
		lcm/=base;
		gcd/=base;
		--dtop;
#ifdef DEBUG
		printf("gcd: %llu, lcm: %llu, base: %llu, dtop=%d\n", gcd, lcm, base, dtop);
#endif
		perm(1,0);
		if(a>b){
			swap=b;
			b=a;
			a=swap;
		}
		printf("%llu %llu\n", a*base, b*base);
	}
	return 0;
}

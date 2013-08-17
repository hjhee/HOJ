#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000

unsigned int q[N+10];
unsigned short w[N+10];

int search(int b, unsigned long long p, unsigned int t){
	int mid,a;
	for(a=0; a<b; ){
		mid=(b-1+a)>>1;
#ifdef DEBUG
		printf("(%d, %d) a[%d]=%c%d, %c%llu\n", a, b, mid, w[mid]?'-':'+', q[mid], t?'-':'+', p);
#endif
		if(q[mid]==p&&w[mid]==t)
			return 1;
		else if((w[mid]==0&&t==1)||(q[mid]>p&&w[mid]==t&&t==0)||(w[mid]==t&&t==1&&q[mid]<p))
			b=mid;
		else
			a=mid+1;
	}
	return 0;
}

int main(void){
	int n,i,timer;
	unsigned st;
	long long s,tmp;
	unsigned long long sp;
	while(scanf("%d%lld", &n, &s)==2){
		for(timer=i=0, sp=s>=0?s:-s, st=s>=0?0:1; i<n; ++i){
			scanf("%lld", &tmp);
			q[i]=tmp>=0?tmp:-tmp;
			w[i]=tmp>=0?0:1;
		}
#ifdef DEBUG
		printf("sp=%c%llu\n", st?'-':'+', sp); 
#endif
		for(i=n-1; i>0; --i){
#ifdef DEBUG
			printf("a[%d]=%c%u\n", i, w[i]?'-':'+', q[i]);
#endif
			if(st^w[i]){
				if(search(i, sp+q[i], st)){
					timer=1;
					break;
				}
			}else{
				if(q[i]>sp){
					if(search(i, q[i]-sp, !st)){
						timer=1;
						break;
					}
				}else{
					if(search(i, sp-q[i], st)){
						timer=1;
						break;
					}
				}
			}
		}
		if(timer)
			puts("Timer is everywhere.");
		else
			puts("Timer is dominating.");
	}
	return 0;
}

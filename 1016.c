#include <stdio.h>
#define N 33000
#define PN 3539

int hash[N],prime[PN],top;

void generate_prime(void){
	int i,j;
	top=1;
	memset(hash, 1, sizeof(hash));
	hash[0]=hash[1]=0;
	for(i=2; i<N; ++i)
		if(hash[i]){
			prime[top++]=i;
			for(j=i+i; j<N; j+=i)
				hash[j]=0;
		}
}

int main(void){
	int n,i,cur,step;
	generate_prime();
	while(scanf("%d", &n)!=EOF&&n){
		for(cur=0,i=1; i<=n; ++i)
			cur=(cur+prime[i])%i;
		printf("%d\n", cur+1);
	}
	return 0;
}
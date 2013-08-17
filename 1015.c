#include <stdio.h>
#define N 32000
#define PN 3500

int hash[N],prime[PN],top;

void generate_prime(void){
	int i,j;
	top=0;
	memset(hash, 1, sizeof(hash));
	hash[0]=hash[1]=0;
	for(i=2; i<N; ++i)
		if(hash[i]){
			prime[top++]=i;
			for(j=i+i; j<N; j+=i)
				hash[j]=0;
		}
}

int is_prime(int r){
	int i;
	for(i=0; i<top; ++i)
		if(r!=prime[i]&&r%prime[i]==0)
			return 0;
	return 1;
}

int main(void){
	int n,i,j,q,r;
	generate_prime();
	scanf("%d", &n);
	for(i=0; i<n; ++i){
		scanf("%d", &q);
		for(j=0; j<top; ++j)
			if((r=q%prime[j])==0&&is_prime(q/prime[j])){
				printf("Yes\n");
				break;
			}
		if(j==top)
			printf("No\n");
	}
	return 0;
}
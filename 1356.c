#include <stdio.h>
#define N 60000
#define PN 7000

unsigned prime[PN],top,table[N];

void generate_prime(void){
	int i,j;
	memset(table, 1, sizeof(table));
	table[0]=table[1]=0;
	for(top=0,i=2; i<N; ++i)
		if(table[i]){
			for(j=i+i; j<N; j+=i)
				table[j]=0;
			prime[top++]=i;
		}
}

int is_prime(unsigned p){
	int i;
	if(p<N)
		return table[p];
	for(i=0; i<top; ++i)
		if(p%prime[i]==0)
			return 0;
	return 1;
}

int main(void){
	unsigned p;
	generate_prime();
	while(scanf("%u", &p)!=EOF)
		printf("%s\n", is_prime(p)?"YES":"NO");
	return 0;
}
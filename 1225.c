#include <stdio.h>
#include <stdlib.h>
#define N 16384

typedef struct{
	int p,d;
}prod;

int A[N+10];
prod product[N+10];

int cmp_prod(const void *a, const void *b){
	return (*(prod *)b).p-(*(prod *)a).p;
}

int accept(int d){
	if(A[d]==d)
		return d;
	return A[d]=accept(A[d]);
}

int main(void){
	int n,i,sum,t;
	while(scanf("%d", &n)==1){
		for(t=i=0; i<n; ++i){
			scanf("%d%d", &product[i].p, &product[i].d);
			if(t<product[i].d)
				t=product[i].d;
		}
		for(i=0; i<=t; ++i)
			A[i]=i;
		qsort(product, n, sizeof(prod), cmp_prod);
		for(sum=i=0; i<n; ++i){
			if((t=accept(product[i].d))){
				A[t]=t-1;
				sum+=product[i].p;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

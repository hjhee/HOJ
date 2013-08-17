#include <stdio.h>

int cmp_milk(const void *a, const void *b){
	return ((int *)a)[0]>((int *)b)[0];
}

int main(void){
	int n,m,i,farmer[5000][2];
	long long price=0;
	scanf("%d%d", &n, &m);
	for(i=0; i<m; ++i)
		scanf("%d%d", farmer[i], farmer[i]+1);
	qsort(farmer, m, sizeof(farmer[0]), cmp_milk);
	for(i=0; n>0&&i<m; ++i){
		if(n>farmer[i][1]){
			price+=farmer[i][0]*farmer[i][1];
			n-=farmer[i][1];
		}else{
			price+=n*farmer[i][0];
			n=0;
		}
	}
	printf("%lld\n", price);
	return 0;
}
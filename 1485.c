#include <stdio.h>
#include <string.h>
#define N 1000

int f[N+N+1];

void print_f(int a, int c){
	int i;
	printf("f[%d]: ", a+c);
	for(i=0; i<=a+c; ++i)
		printf("%d ", f[i]);
	putchar('\n');
}

int dp(int a, int c, int n, int *bags){
	int i,j,q,max;
	memset(f, 0, sizeof(f));
	for(max=i=0; i<n; ++i)
		for(j=a+c-bags[i]; j>-1; --j){
			q=f[j];
			if(f[j+bags[i]]<q+1)
				f[j+bags[i]]=q+1;
		}
	for(j=0; j<=a+c; ++j)
		if(max<f[j])
			max=f[j];
	return max;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("1485.in", "rb", stdin);
#endif
	int a,c,n,i,k,bags[300];
	while(scanf("%d%d%d", &a, &c, &n)==3){
		for(i=0; i<n; ++i)
			scanf("%d", bags+i);
		k=dp(a, c, n, bags);
		if(k>=n)
			puts("Yes");
		else if(k==n-1)
			puts("Need a helper");
		else
			puts("No");
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

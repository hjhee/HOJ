#include <stdio.h>

int d[51][51],s[51][51][51],o[51][51],p[51][51];

int sep(int n, int k, int p){
	/*printf("s(%d, %d, %d)\n", n, k, p);*/
	if(n<0||k<0||p<0)
		return 0;
	/*printf("break 1\n");*/
	if((k==1&&p!=n)||k==0||p==0||n==0||(p>n))
		return s[n][k][p]=0;
	/*printf("break 2\n");*/
	if(s[n][k][p])
		return s[n][k][p];
	/*printf("break 3\n");*/
	if((k==1&&p==n)||(p==1&&k==n))
		return s[n][k][p]=1;
	/*printf("break 4\n");*/
	if(k>n)
		return s[n][k][p]=sep(n, n, p);
	/*printf("break 5\n");*/
	/*if(p>n)*/
		/*return s[n][k][p]=sep(n, k, n);*/
	/*printf("break 6\n");*/
	if(k==n){
		if(p==1)
			return s[n][k][p]=sep(n, k-1, p)+1;
		else
			return s[n][k][p]=sep(n, k-1, p);
	}
	/*printf("break 7\n");*/
	return s[n][k][p]=sep(n, k-1, p)+sep(n-k, k, p-1);
}


int divide(int n, int k){
	if(n<0)
		return 0;
	if(d[n][k])
		return d[n][k];
	if(n==0||k==0)
		return d[n][k]=0;
	if(k==1)
		return d[n][k]=1;
	if(k>n)
		return d[n][k]=divide(n, n);
	if(k==n)
		return d[n][k]=divide(n, k-1)+1;
	return d[n][k]=divide(n, k-1)+divide(n-k, k);
}

int odivide(int n, int k){
	if(n<0)
		return 0;
	if(o[n][k])
		return o[n][k];
	if(n==0||k==0)
		return o[n][k]=0;
	if(k==1)
		return o[n][k]=1;
	if(k>n)
		return o[n][k]=odivide(n, n);
	if((k&1)==0)
		return o[n][k]=odivide(n, k-1);
	if(k==n)
		return o[n][k]=odivide(n, k-1)+1;
	return o[n][k]=odivide(n, k-1)+odivide(n-k, k);
}

void dsep(void){
	int i,j;
	for(i=1; i<=50; ++i)
		p[1][i]=p[0][i]=1;
	for(i=2; i<=50; ++i)
		for(j=1; j<=50; ++j){
			if(i<j)
				p[i][j]=p[i][i];
			else
				p[i][j]=p[i][j-1]+p[i-j][j-1];
		}
}

int main(void){
	int n,k;
	dsep();
	while(scanf("%d%d", &n, &k)==2){
		printf("%d\n", divide(n, n));
		printf("%d\n", sep(n, n, k));
		printf("%d\n", divide(n, k));
		printf("%d\n", odivide(n, n));
		printf("%d\n", p[n][n]);
		putchar('\n');
	}
	return 0;
}

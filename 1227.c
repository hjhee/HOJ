#include <stdio.h>
#include <string.h>
#define N 1000

int DP[N+10][N+10];
char X[N],Z[N];

int main(void){
    int i,j,lx,lz,max;
    while(scanf("%s%s", X, Z)==2){
	memset(DP, 0, sizeof(DP));
	lx=strlen(X);
	lz=strlen(Z);
	max=0;
	if(X[0]==Z[0])
	    DP[0][0]=1;
        for(i=1; i<lx; ++i){
	    DP[i][0]=(X[i]==Z[0])||DP[i-1][0];
	    max|=DP[i][0];
	}
	for(j=1; j<lz; ++j){
	    DP[0][j]=(X[0]==Z[j])||DP[0][j-1];
	    max|=DP[0][j];
	}
	for(i=1; i<lx; ++i)
            for(j=1; j<lz; ++j){
		if(X[i]==Z[j])
		    DP[i][j]=DP[i-1][j-1]+1;
		else
		    DP[i][j]=(DP[i-1][j]>DP[i][j-1])?DP[i-1][j]:DP[i][j-1];
		max=(max<DP[i][j])?DP[i][j]:max;
	    }
	printf("%d\n", max);
    }
    return 0;
}

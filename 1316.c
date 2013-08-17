#include <stdio.h>
#define N 100
#define T(g, i) for((i)=0; (g)[(i)]!='\0'; ++(i)){ \
	switch((g)[(i)]){ \
		case 'A': (g)[(i)]=0; break; \
		case 'C': (g)[(i)]=1; break; \
		case 'G': (g)[(i)]=2; break; \
		case 'T': (g)[(i)]=3; break; \
		case ' ': (g)[(i)]=4; break; \
	} \
}

int DP[N+10][N+10];

int main(void){
#ifndef ONLINE_JUDGE
	freopen("1316.in", "rb", stdin);
#endif
	int set,ls,lg,i,j,a,b,c;
	int score[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2}, 
		{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
	char s[N+10],g[N+10];
	scanf("%d", &set);
	while(set--){
		scanf("%*d%s%*d%s", s, g);
		T(s, ls);
		T(g, lg);
		DP[0][0]=0;
		/*
#ifndef ONLINE_JUDGE
		printf("s: ");
		for(i=0; i<ls; ++i)
			printf("%d ", s[i]);
		putchar('\n');
		printf("g: ");
		for(j=0; j<lg; ++j)
			printf("%d ", g[j]);
		putchar('\n');
#endif
		*/
		for(i=1; i<=ls; ++i)
			DP[i][0]=DP[i-1][0]+score[s[i-1]][4];
		for(j=1; j<=lg; ++j)
			DP[0][j]=DP[0][j-1]+score[4][g[j-1]];
		for(i=1; i<=ls; ++i){
			for(j=1; j<=lg; ++j){
				a=DP[i-1][j-1]+score[s[i-1]][g[j-1]];
				b=DP[i][j-1]+score[4][g[j-1]];
				c=DP[i-1][j]+score[s[i-1]][4];
				DP[i][j]=(a>b)?a:b;
				DP[i][j]=(c>DP[i][j])?c:DP[i][j];
			}
		}
#ifndef ONLINE_JUDGE
		for(i=0; i<=ls; ++i){
			for(j=0; j<=lg; ++j)
				printf("%3d", DP[i][j]);
			putchar('\n');
		}
#endif
		printf("%d\n", DP[ls][lg]);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

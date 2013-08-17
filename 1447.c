#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f[101][101],s[101][101][101],top[101][101];
char texta[100][40],textb[100][40];

int cmp_int(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("1447.in", "rb", stdin);
#endif
	int i,j,ta,tb,m,x,y,p;
	while(scanf("%s", texta[ta=0])==1){
		memset(f, 0, sizeof(f));
		memset(top, 0, sizeof(top));
		memset(s, -1, sizeof(s));
		++ta;
		tb=0;
		while(scanf("%s", texta[ta])==1){
			if(texta[ta][0]=='#')
				break;
			++ta;
		}
		while(scanf("%s", textb[tb])==1){
			if(textb[tb][0]=='#')
				break;
			++tb;
		}
		for(i=1; i<=ta; ++i)
			for(j=1; j<=tb; ++j){
				m=0;
				p=0;
				if(m<f[i-1][j]){
					m=f[i-1][j];
					x=i-1;
					y=j;
				}
				if(m<f[i][j-1]){
					m=f[i][j-1];
					x=i;
					y=j-1;
				}
				if(f[i-1][j-1]+1>m&&
					strcmp(texta[i-1], textb[j-1])==0){
					m=f[i-1][j-1]+1;
					x=i-1;
					y=j-1;
					p=1;
				}
				f[i][j]=m;
				memcpy(s[i][j], s[x][y], sizeof(s[x][y]));
				top[i][j]=top[x][y];
				if(p)
					s[i][j][top[i][j]++]=i-1;
			}
		qsort(s[ta][tb], top[ta][tb], sizeof(int), cmp_int);
		for(i=0; i<top[ta][tb]-1; ++i)
			printf("%s ", texta[s[ta][tb][i]]);
		puts(texta[s[ta][tb][i]]);

	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

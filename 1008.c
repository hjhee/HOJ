#include <stdio.h>
#include <string.h>
#define N 10010

int vis[N];

int main(void){
	int n,m,k,r;
	while(scanf("%d%d", &n, &m)!=EOF){
		memset(vis, 0, sizeof(vis));
		for(k=r=0; k<N; ++k){
			r=(r*10+n);
			r=r%m;
			if(r==0||vis[r])
				break;
			vis[r]=1;
		}
		printf("%d\n", r==0?k+1:0);
	}
	return 0;
}

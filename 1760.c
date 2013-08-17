#include <stdio.h>

int main(void){
	int n,i,s,max,v;
	while(scanf("%d", &n), n){
		for(max=-2147483647, v=0, i=1; i<=n; ++i){
			scanf("%d", &s);
			if(v<0)
				v=0;
			v+=s;
			if(max<v)
				max=v;
		}
		if(max>0)
			printf("The maximum winning streak is %d.\n", max);
		else
			puts("Losing streak.");
	}
	return 0;
}

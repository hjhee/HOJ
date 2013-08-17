#include <stdio.h>
#define N 100000

int candy[N];

int main(void){
	int n,i,ave;
	long long sum,ope;
	while(scanf("%d", &n)!=EOF&&n!=-1){
		for(sum=i=0; i<n; ++i){
			scanf("%d", candy+i);
			sum+=candy[i];
		}
		if(sum%n)
			printf("-1\n");
		else{
			ave=sum/n;
			for(ope=i=0; i<n; ++i)
				if(ave>candy[i])
					ope+=ave-candy[i];
			printf("%d\n", ope);
		}
	}
	return 0;
}
#include <stdio.h>

int main(void){
	int s,d,times,clock[60];
	while(scanf("%d%d", &s, &d)!=EOF){
		if(s==0&&d==0)
			break;
		times=0;
		memset(clock, 0, sizeof(clock));
		while(s){
			if(clock[s])
				break;
			else{
				clock[s]=1;
				s=(s+s*d)%60;
				++times;
			}
		}
		if(s)
			printf("Impossible\n");
		else
			printf("%d\n", times);
	}
	return 0;
}
#include <stdio.h>

int main(void){
	int set,t;
	scanf("%d", &t);
	for(set=1; set<=t; ++set){
		printf("Keypad #%d:\n", set);
		putchar('\n');
	}
	return 0;
}

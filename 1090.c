#include <stdio.h>
#include <math.h>
#include <string.h>

int staircases[501],division[501][100];

void set_amount(void){
	int n,l,i,d;
	for(n=1; n<=500; ++n)
		division[n][1]=1;
	for(l=2; l<40; ++l){
		for(n=2; n<=500; ++n){
			if(n*2>=l*l+l){
				for(d=0.25*(n*2-(l-1)*(l-2)), i=n-l*(l-1)*0.5; i>d; --i){
					if(n==9)
						printf("[%d, %d]=[%d, %d]+%d\n", n, l, n-i, l-1, i);
					division[n][l]+=division[n-i][l-1];
				}
			}
		}
	}
}

int divide(int n, int l, int top){
	int i,s;
	if(top==1||n<l||(l==1&&n>=top))
		return 0;
	if(l==1)
		return division[n][l]=1;
	for(s=0, i=1; i<top; ++i)
		s+=divide(n-i, l-1, i);
	division[n][l]=s;
	printf("division[%d][%d]=%d, %d\n", n, l, s, top);
	return s;
}

int main(void){
	int n,i,j;
	divide(10, 4, 11);
	for(i=1; i<=30; ++i){
		printf("%2d: ", i);
		for(j=0; j<10&&(1||division[i][j]!=0); ++j)
			printf("%3d ", division[i][j]);
		putchar('\n');
	}
	while(scanf("%d", &n), n)
		printf("%d\n", staircases[n]);
	return 0;
}

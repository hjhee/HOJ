#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
#define EPS 1e-9

typedef struct{
	double left,right;
}region;

region island[N+10];

int cmp_region(const void *a, const void *b){
	if(fabs((*(region *)a).left-(*(region *)b).left)>EPS)
		return ((*(region *)a).left-(*(region *)b).left>0)?1:-1;
	else
		return ((*(region *)a).right-(*(region *)b).right>0)?1:-1;
}

int main(void){
	int testcase,installation,n,d,i,flag;
	double radar,x,y;
	for(testcase=1, scanf("%d%d", &n, &d); !(n==0&&d==0); ++testcase){
		flag=1;
		for(i=0; i<n; ++i){
			scanf("%lf%lf", &island[i].left, &island[i].right);
			if(d<island[i].right)
				flag=0;
		}
		if(flag==0){
			printf("Case %d: -1\n", testcase);
			scanf("%d%d", &n, &d);
			continue;
		}
		qsort(island, n, sizeof(region), cmp_region);
#ifdef DEBUG
		printf("---------\n");
		for(i=0; i<n; ++i)
			printf("(%f, %f)\n", island[i].left, island[i].right);
		printf("---------\n");
#endif
		for(i=0; i<n; ++i){
			x=island[i].left;
			y=island[i].right;
			island[i].left=-sqrt(d*d-y*y)+x;
			island[i].right=sqrt(d*d-y*y)+x;
		}
		installation=1;
		radar=island[0].right;
		for(i=1; i<n; ++i){
			if(radar<island[i].left){
				++installation;
				radar=island[i].right;
			}else if(radar>island[i].right)
				radar=island[i].right;
			
		}
		printf("Case %d: %d\n", testcase, installation);
		scanf("%d%d", &n, &d);
	}
	return 0;
}

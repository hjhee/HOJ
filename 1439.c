#include <stdio.h>
#include <math.h>
#define D(u, v) sqrt(((u).x-(v).x)*((u).x-(v).x)+((u).y-(v).y)*((u).y-(v).y))

typedef struct{
	double x,y;
} coordinate;

int main(void){
	int i;
	double a,b,c,r,s;
	coordinate point[3];
	while(scanf("%lf%lf", &point[0].x, &point[0].y)!=EOF){
		for(i=1; i<3; ++i)
			scanf("%lf%lf", &point[i].x, &point[i].y);
		a=D(point[0], point[1]);
		b=D(point[0], point[2]);
		c=D(point[1], point[2]);
		s=((point[1].x-point[0].x)*(point[2].y-point[0].y)-(point[2].x-point[0].x)*(point[1].y-point[0].y))/2;
		r=a*b*c/4/s;
		printf("%.2f\n", 2*acos(-1.0)*fabs(r));
	}
	return 0;
}

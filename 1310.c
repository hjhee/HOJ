#include <stdio.h>
#include <math.h>
#define D(u, v) sqrt(((u).x-(v).x)*((u).x-(v).x)+((u).y-(v).y)*((u).y-(v).y))
#define EPS 1e-1
#define APS 2.0

typedef struct{
	double x,y;
} coordinate;

int length(double a, double b, double c){
	if(fabs(a-b)<=EPS&&fabs(b-c)<=EPS)
		return 3;
	else if(fabs(a-b)<=EPS||fabs(a-c)<=EPS||fabs(b-c)<=EPS)
		return 2;
	else
		return 0;
}

int angle(double A, double B, double C){
	if(A-90.0>APS||B-90.0>APS||C-90.0>APS)
		return 2;
	else if(fabs(A-90.0)<=APS||fabs(B-90.0)<=APS||fabs(C-90.0)<=APS)
		return 1;
	return 0;
}

int main(void){
	double a,b,c,A,B,C,s,convert;
	coordinate point[3];
	convert=180/acos(-1.0);
	while(scanf("%lf%lf%lf%lf%lf%lf", &point[0].x, &point[0].y, &point[1].x, &point[1].y, &point[2].x, &point[2].y)==6){
		a=D(point[0], point[1]);
		b=D(point[0], point[2]);
		c=D(point[1], point[2]);
		s=0.5*fabs((point[1].x-point[0].x)*(point[2].y-point[0].y)-(point[2].x-point[0].x)*(point[1].y-point[0].y));
		A=asin(2*s/b/c)*convert;
		B=asin(2*s/a/c)*convert;
		C=asin(2*s/a/b)*convert;
		if((a+b-c<=EPS)||(a+c-b<=EPS)||(b+c-a<=EPS))
			puts("Not a Triangle");
		else{
			switch(length(a,b,c)){
				case 0: fputs("Scalene ", stdout); break;
				case 2: fputs("Isosceles ", stdout); break;
				case 3: fputs("Equilateral ", stdout); break;
			}
			switch(angle(A,B,C)){
				case 0: puts("Acute"); break;
				case 1: puts("Right"); break;
				case 2: puts("Obtuse"); break;
			}
		}
	}
	puts("End of Output");
	return 0;
}

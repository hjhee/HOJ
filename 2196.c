#include <stdio.h>
#include <string.h>

int main(void){
#ifndef ONLINE_JUDGE
	freopen("2196.in", "rb", stdin);
#endif
	int set,max,n,p,t,at,i,j,task[500],prof[500],f[2001];
	double u;
	for(scanf("%d", &set), p=1; p<=set; ++p){
		memset(f, 0, sizeof(f));
		scanf("%d", &n);
		for(i=0; i<n; ++i){
			scanf("%d%lf", task+i, &u);
			prof[i]=(u+0.005)*100;
		}
		scanf("%d", &t);
		for(i=0; i<n; ++i)
			for(j=t-task[i]; j>-1; --j)
				if(f[j+task[i]]<f[j]+prof[i])
					f[j+task[i]]=f[j]+prof[i];
		for(max=j=0; j<=t; ++j)
			if(max<f[j]){
				max=f[j];
				at=j;
			}
#ifndef ONLINE_JUDGE
		printf("f: ");
		for(j=0; j<=t; ++j)
			printf("%d ", f[j]);
		putchar('\n');
#endif
		printf("Problem %d: %d seconds scheduled for $%.2f\n",
				p, at, (double)max/100);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

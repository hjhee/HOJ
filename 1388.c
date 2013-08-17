#include <stdio.h>
#include <string.h>

int p[200*1000+1][21];

int dp(int n, int *copper, int *price){
        int m,cmin,cmax,c,i,j,min,q;
        memset(p, -1, sizeof(p));
        scanf("%d%d%d", &m, &cmin, &cmax);
        cmin*=m;
        cmax*=m;
        p[0][0]=0;
        for(i=1; i<=n; ++i)
                for(j=m-1; j>-1; --j)
                        for(c=cmax; c>-1; --c){
                                if(p[c][j]==-1)
                                        continue;
                                q=p[c][j];
                                if(c+copper[i-1]<=cmax){
                                        q+=price[i-1];
                                        if(q<p[c+copper[i-1]][j+1]||                                   			 p[c+copper[i-1]][j+1]==-1)
                                                p[c+copper[i-1]][j+1]=q;
                                }
                        }
#ifndef ONLINE_JUDGE
        printf("value: ");
        for(c=cmin; c<=cmax; ++c)
                printf("%d ", p[c][m]);
        putchar('\n');
#endif
        for(min=2147483647, c=cmin; c<=cmax; ++c)
                if(min>p[c][m]&&p[c][m]!=-1)
                        min=p[c][m];
        return min;
}

int main(void){
#ifndef ONLINE_JUDGE
        freopen("1388.in", "rb", stdin);
#endif
        int n,c,q,i,set;
        int copper[300],price[300];
        set=1;
        while(scanf("%d", &n)==1){
                if(set!=1)
                        putchar('\n');
                for(i=0; i<n; ++i)
                        scanf("%d%d", copper+i, price+i);
                scanf("%d", &c);
                for(i=0; i<c; ++i){
                        q=dp(n, copper, price);
                        if(q==2147483647)
                                puts("impossible");
                        else
                                printf("%d\n", q);
                }
                ++set;
        }
#ifndef ONLINE_JUDGE
        fclose(stdin);
#endif
        return 0;
}

/* Another Version

#include <stdio.h>
#include <string.h>

int p[200*1000+1][21];

int dp(int n, int *copper, int *price){
	int m,cmin,cmax,c,i,j,min,q;
	memset(p, -1, sizeof(p));
	scanf("%d%d%d", &m, &cmin, &cmax);
	cmin*=m;
	cmax*=m;
	p[0][0]=0;
	for(i=0; i<n; ++i)
		for(j=m; j>0; --j)
			for(c=cmax; c>=copper[i]; --c){
				q=p[c][j];
				if(p[c-copper[i]][j-1]!=-1&&(q==-1||
					p[c-copper[i]][j-1]+price[i]<q))
					q=p[c-copper[i]][j-1]+price[i];
				p[c][j]=q;
			}
#ifndef ONLINE_JUDGE
	printf("value: ");
	for(c=cmin; c<=cmax; ++c)
		printf("%d ", p[c][m]);
	putchar('\n');
#endif
	for(min=2147483647, c=cmin; c<=cmax; ++c)
		if(min>p[c][m]&&p[c][m]!=-1)
			min=p[c][m];
	return min;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("1388.in", "rb", stdin);
#endif
	int n,c,q,i,set;
	int copper[300],price[300];
	set=1;
	while(scanf("%d", &n)==1){
		if(set!=1)
			putchar('\n');
		for(i=0; i<n; ++i)
			scanf("%d%d", copper+i, price+i);
		scanf("%d", &c);
		for(i=0; i<c; ++i){
			q=dp(n, copper, price);
			if(q==2147483647)
				puts("impossible");
			else
				printf("%d\n", q);
		}
		++set;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

*/

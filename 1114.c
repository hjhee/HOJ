#include <stdio.h>
#include <string.h>
#define N 30

typedef struct{
	int xmin,ymin,xmax,ymax,e;
}frame;

int h,w;
int graph[N][N],d[N],alpha[N][N+10];
char map[N][N+10];
frame p[N];


void init(void){
	int i;
	memset(graph, 0, sizeof(graph));
	memset(d, 0, sizeof(d));
	memset(alpha, 0, sizeof(alpha));
	for(i=0; i<N; ++i){
		p[i].xmin=p[i].ymin=50;
		p[i].xmax=p[i].ymax=-1;
		p[i].e=0;
	}
}

void update(int c, int x, int y){
	if(p[c].xmin>x)
		p[c].xmin=x;
	if(p[c].xmax<x)
		p[c].xmax=x;
	if(p[c].ymin>y)
		p[c].ymin=y;
	if(p[c].ymax<y)
		p[c].ymax=y;
}

void build_graph(int c){
	int i,j;
	for(i=p[c].xmin; i<=p[c].xmax; ++i){
		if(map[i][p[c].ymin]!=c+'A')
			graph[c][map[i][p[c].ymin]-'A']=1;
		if(map[i][p[c].ymax]!=c+'A')
			graph[c][map[i][p[c].ymax]-'A']=1;
	}
	for(j=p[c].ymin; j<=p[c].ymax; ++j){
		if(map[p[c].xmin][j]!=c+'A')
			graph[c][map[p[c].xmin][j]-'A']=1;
		if(map[p[c].xmax][j]!=c+'A')
			graph[c][map[p[c].xmax][j]-'A']=1;
	}
}


/*
void permutation(int u, int l, int z, char *s, char *m){
	int i;
	static int q[N+10],v[N+10];
	if(u==z){
		for(i=0; i<z; ++i)
			s[i]=q[i]+'A';
		if(l)
			permutation(0, l-1, d[l-1], s+d[l], m);
		else{
			s[d[l]]='\0';
			puts(m);
		}
		return;
	}
	for(i=0; i<z; ++i){
		if(!v[alpha[l][i]]&&p[alpha[l][i]].e){
			v[alpha[l][i]]=1;
			q[u]=alpha[l][i];
			permutation(u+1, l, z, s, m);
			v[alpha[l][i]]=0;
		}
	}
}

void toposort(int n){
	int i,j,t,l,vis[N]={0};
	char s[N+10];
	for(t=l=0; t<n; ++l){
		for(i=0; i<26; ++i)
			if(!vis[i]&&p[i].e){
				for(j=0; j<26; ++j)
					if(graph[i][j])
						break;
				if(j==26){
					alpha[l][d[l]++]=i;
					++t;
					vis[i]=1;
				}
			}
		for(i=0; i<d[l]; ++i)
			for(j=0; j<26; ++j)
				graph[j][alpha[l][i]]=0;
	}
	permutation(0, l, d[l], s, s);
#ifndef ONLINE_JUDGE
	for(i=0; i<l; ++i){
		printf("l[%d]:" , i);
		for(j=0; j<d[i]; ++j){
			putchar('A'+alpha[i][j]);
		}
		putchar('\n');
	}
#endif
}
*/

void toposort(int z, int n){
	int i,j;
	static int v[N+10];
	static char s[N+10];
	if(z==n){
		s[z]='\0';
		puts(s);
		return;
	}
	for(i=0; i<26; ++i)
		if(!v[i]&&p[i].e){
			for(j=0; j<26; ++j)
				if(!v[j]&&p[j].e&&graph[j][i])
					break;
			if(j==26){
				v[i]=1;
				s[z]=i+'A';
				toposort(z+1, n);
				v[i]=0;
			}
		}
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("1114.in", "rb", stdin);
#endif
	int i,j,n;
	while(scanf("%d%d", &h, &w)==2){
		init();
		for(i=0; i<h; ++i)
			scanf("%s", map[i]);
		for(i=0; i<h; ++i)
			for(j=0; j<w; ++j)
				if(map[i][j]!='.'){
					update(map[i][j]-'A', i, j);
					p[map[i][j]-'A'].e=1;
				}
		for(n=i=0; i<26; ++i){
			build_graph(i);
			if(p[i].e)
				++n;
		}
		toposort(0, n);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}

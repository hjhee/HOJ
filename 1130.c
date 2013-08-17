#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ID(n) ((n)-'A'+1)
#define EPS 1e-8

int main(void){
	int n,i,j,id;
	int matrix[30][30];
	int queue[1000],front,rear,vis[30],dis[30];
	char ch[3],path[30];
	double invalue,max,value[30];
	while(scanf("%d", &n)!=EOF){
		memset(matrix, 0, sizeof(matrix));
		memset(vis, 0, sizeof(vis));
		memset(dis, -1, sizeof(dis));
		memset(value, 0, sizeof(value));
		for(i=0; i<n; ++i){
			scanf("%s%lf%s", ch, &invalue, path);
			ch[0]=toupper(ch[0]);
			value[ID(ch[0])]=invalue;
			for(j=0; path[j]!='\0'; ++j){
				path[j]=toupper(path[j]);
				if(path[j]=='*')
					matrix[0][ID(ch[0])]=1; /* matrix[ID(ch[0])][0]=1; */
				else
					matrix[ID(ch[0])][ID(path[j])]=1; /* matrix[ID(path[j])][ID(ch[0])]=1; */
			}
		}
		front=rear=0;
		queue[front++]=0;
		vis[0]=1;
		while(rear<front){
			id=queue[rear++];
			for(i=1; i<30; ++i)
				if(matrix[id][i]&&!vis[i]){
					vis[i]=1;
					dis[i]=dis[id]+1;
					queue[front++]=i;
				}
			vis[id]=2;
		}
		for(max=-1, i=1; i<30; ++i){
			while(vis[i]&&dis[i]--)
				value[i]*=0.95;
			if(value[i]-max>EPS){
				id=i;
				max=value[i];
			}
		}
		printf("Import from %c\n", id+'A'-1);
	}
	return 0;
}

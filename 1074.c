#include <stdio.h>
#include <string.h>
#define N 20
#define S 50
#define DEBUG 0

int line[N+10][S+10];
int driver[N+10][2];
int cover[S+10][N+10];
int matrix[N+10][N+10];
int dri[N+10],vis[N+10];

void build_graph(int n, int d, int s){
    int i,j,k;
    memset(matrix, 0, sizeof(matrix));
    for(i=1; i<=s; ++i)
        for(j=1; j<=cover[i][0]; ++j)
            for(k=j+1; k<=cover[i][0]; ++k)
                matrix[j][k]=matrix[k][j]=1;
#if DEBUG
    for(i=1; i<=n; ++i){
        for(j=1; j<=n; ++j)
            printf("%d ", matrix[i][j]);
        putchar('\n');
    }
#endif
}

void dfs(int cur, int n, int d){
    int i;
    vis[cur]=1;
    for(i=1; i<=d; ++i)
        if(driver[i][0]==cur)
            dri[i]=1;
    for(i=1; i<=n; ++i)
        if(matrix[cur][i]&&!vis[i])
            dfs(i, n, d);
}

int traverse(int n, int d, int s){
    int i;
    memset(vis, 0, sizeof(vis));
    memset(dri, 0, sizeof(dri));
    dfs(1, n, d);
    for(i=1; i<=d; ++i)
        if(!dri[i])
            break;
    return i==d+1;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("1074.in", "rb", stdin);
#endif
    int n,d,s,i,j,ds,dn;
    char inputline[1000];
    while(fgets(inputline, 1000, stdin)!=NULL){
        if(!(sscanf(inputline, "%d%d%d", &n, &d, &s)==3&&(n||d||s)))
            break;
        for(i=1; i<=s; ++i)
            cover[i][0]=0;
        for(i=1; i<=n; ++i){
            fgets(inputline, 1000, stdin);
            line[i][0]=0;
            for(j=0; inputline[j]!='\n'&&inputline[j]!='\0'; ++j){
                ++line[i][0];
                sscanf(inputline+j, "%d", line[i]+line[i][0]);
                ++cover[line[i][line[i][0]]][0];
                cover[line[i][line[i][0]]][cover[line[i][line[i][0]]][0]]=n;
                for(++j; inputline[j]!=' '&&inputline[j]!='\n'; ++j);
            }
#if DEBUG
            printf("line %d:\n", i);
            for(j=1; j<=line[i][0]; ++j)
                printf("%d ", line[i][j]);
            putchar('\n');
#endif
            fgets(inputline, 1000, stdin);
            for(j=0; inputline[j]!='\n'&&inputline[j]!='\0'; ++j){
                sscanf(inputline+j, "%d%d", &ds, &dn);
                driver[dn][0]=i;
                driver[dn][1]=ds;
                for(++j; inputline[j]!=' '&&inputline[j]!='\n'; ++j);
                for(++j; inputline[j]!=' '&&inputline[j]!='\n'; ++j);
            }
        }
#if DEBUG
        for(j=1; j<=d; ++j)
            printf("(%d, %d) ", driver[j][0], driver[j][1]);
        putchar('\n');
        for(i=1; i<=s; ++i){
            printf("stop %d:\n", i);
            for(j=1; j<=cover[i][0]; ++j)
                printf("%d ", j);
            putchar('\n');
        }
#endif
        build_graph(n, d, s);
        if(traverse(n, d, s))
            puts("Yes");
        else
            puts("No");
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

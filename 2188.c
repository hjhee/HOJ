#include <stdio.h>
#include <string.h>
#define MAX(a, b) (((a)>(b))?(a):(b))

int dp[10][1024][10];

void construct_cm(int (*cm)[10], int n, char (*words)[20], 
        const int *len){
    int i,j,k,l,c,max;
    for(i=0; i<n; ++i){
        cm[i][i]=0;
        for(j=i+1; j<n; ++j){
            max=-1;
            for(k=0; k<len[i]; ++k){
                for(c=l=0; k+l<len[i]&&l<len[j]; ++l)
                    if(words[i][k+l]==words[j][l])
                        ++c;
                max=MAX(max, c);
            }
            for(k=0; k<len[j]; ++k){
                for(c=l=0; k+l<len[j]&&l<len[i]; ++l)
                    if(words[j][k+l]==words[i][l])
                        ++c;
                max=MAX(max, c);
            }
            /*
            printf("%s %s %d\n", words[i], words[j], max);
            */
            cm[i][j]=cm[j][i]=max;
        }
    }
}

int main(void){
    int n,i,j,u,s,k,max;
    int cm[10][10],len[10];
    char words[10][20];
#ifndef ONLINE_JUDGE
    freopen("2188.in", "rb", stdin);
#endif
    while(scanf("%d", &n), n>0){
        memset(dp, -1, sizeof(dp));
        for(i=0; i<n; ++i){
            scanf("%s", words[i]);
            len[i]=strlen(words[i]);
        }
        construct_cm(cm, n, words, len);
        /*
        for(i=0; i<n; ++i){
            for(j=0; j<n; ++j)
                printf("%d ", cm[i][j]);
            putchar('\n');
        }
        */
        u=1<<n;
        for(i=0; i<n; ++i)
            dp[0][1<<i][i]=0;
        for(i=0; i<n-1; ++i){
            for(s=0; s<u; ++s)
                for(j=0; j<n; ++j)
                    if(dp[i][s][j]!=-1){
                        for(k=0; k<n; ++k){
                            if((s&(1<<k))==0)
                                dp[i+1][s|(1<<k)][k]=MAX(dp[i+1][s|(1<<k)][k],
                                        dp[i][s][j]+cm[j][k]);
                        }
                    }
        }
        /*
        for(i=0; i<n; ++i){
            for(j=0; j<n; ++j){
                for(s=1; s<u; ++s)
                    if(dp[i][s][j]!=-1)
                        printf("%d ", dp[i][s][j]);
                putchar('\n');
            }
            puts("---------");
        }
        */
        max=-1;
        for(j=0; j<n; ++j)
            max=MAX(max, dp[n-1][u-1][j]);
        printf("%d\n", max);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

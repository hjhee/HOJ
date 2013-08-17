#include <stdio.h>
#include <string.h>
#define N 100000

int trie[N+10][53],top;

void init(void){
    top=0;
    memset(trie, -1, sizeof(trie));
}

int transform(char *s){
    int u,k;
    u=0;
    switch(s[0]){
        case 'A': u=0; break;
        case 'J': u=10; break;
        case 'Q': u=11; break;
        case 'K': u=12; break;
        default: u=s[0]-'1'; break;
    }
    if(s[0]=='1'&&s[1]=='0'){
        u=9;
        k=2;
    }else
        k=1;
    switch(s[k]){
        case 'D': u+=13; break;
        case 'H': u+=13*2; break;
        case 'S': u+=13*3; break;
    }
    return u;
}

void insert(int *cardlist, int n){
    int i,cur;
    for(i=n-1, cur=0; i>-1; --i){
        if(trie[cur][cardlist[i]]==-1)
            trie[cur][cardlist[i]]=++top;
        cur=trie[cur][cardlist[i]];
    }
}

int main(void){
    int t,i,j,n,cardlist[53];
    char suit[20];
#ifndef ONLINE_JUDGE
    freopen("2353.in", "rb", stdin);
#endif
    while(scanf("%d", &t)==1&&t){
        init();
        for(i=0; i<t; ++i){
            scanf("%d", &n);
            for(j=0; j<n; ++j){
                scanf("%s", suit);
                cardlist[j]=transform(suit);
                /*
                printf("(%d, %d) ", cardlist[j]%13+1, cardlist[j]/13+1);
                */
            }
            insert(cardlist, n);
        }
        printf("%d\n", top);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

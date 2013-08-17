#include <stdio.h>

/*
void prekmp(char *B, int *next){
    int i,j;
    next[0]=-1;
    j=-1;
    for(i=1; B[i]!='\0'; ++i){
        while(j!=-1&&B[i]!=B[j+1])
            j=next[j];
        if(B[i]==B[j+1])
            ++j;
        next[i]=j;
    }
}
*/

void prekmp(int l, char *s, int *next){
    int k;
    if(l==0){
        next[0]=-1;
        return;
    }
    prekmp(l-1, s, next);
    k=next[l-1];
    while(k!=-1&&s[l]!=s[k+1])
        k=next[k];
    if(s[l]==s[k+1])
        ++k;
    next[l]=k;
}

int main(void){
    int i,next[1000];
    char s[1000];
    while(scanf("%s", s)!=EOF){
        for(i=0; s[i]!='\0'; ++i);
        prekmp(i, s, next);
        for(i=0; s[i]!='\0'; ++i)
            printf("%d ", next[i]);
        putchar('\n');
    }
    return 0;
}

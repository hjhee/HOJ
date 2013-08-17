#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 300

int main(void){
    int i,len;
    char plain[N],subsit[N],hash[N]={0},string[N];
    fgets(plain, N, stdin);
    fgets(subsit, N, stdin);
    for(len=strlen(plain), i=0; i<len; ++i)
        hash[plain[i]]=subsit[i];
    for(i=0; i<N; ++i)
        if(!hash[i])
            hash[i]=i;
    fputs(subsit, stdout);
    fputs(plain, stdout);
    while(fgets(plain, N, stdin)!=NULL){
        len=strlen(plain);
        for(i=0; i<len; ++i)
            subsit[i]=hash[plain[i]];
        subsit[i]='\0';
        fputs(subsit, stdout);
    }
    return 0;
}

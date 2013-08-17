#include <stdio.h>
#include <ctype.h>
#define ISOPE(u) ((u)=='+'||(u)=='-'||(u)=='=')

void format(char *input){
    int i,j;
    char tmp[300];
    j=0;
    if(!(input[0]=='+'||input[0]=='-')){
        tmp[j++]='+';
        if(input[0]=='x')
            tmp[j++]='1';
    }
    for(i=0; input[i]!='\0'; ++i){
        tmp[j++]=input[i];
        if(input[i]=='='){
            if(!(input[i]=='+'||input[i]=='-'))
                tmp[j++]='+';
        }
        if(input[i+1]=='x'){
            if(input[i]=='+'||input[i]=='-')
                tmp[j++]='1';
        }
    }
    tmp[j++]='\0';
    for(i=0; i<j; ++i)
        input[i]=tmp[i];
}

int abstract(char *input, long long *x, long long *s, char e){
    int i;
    long long p;
    for(i=0; input[i]!=e; ++i){
        sscanf(input+i, "%lld", &p);
        for(++i; '0'<=input[i]&&input[i]<='9'; ++i);
        --i;
        if(input[i+1]=='x'){
            ++i;
            *x+=p;
        }else{
            *s+=p;
        }
    }
    return i;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2368.in", "rb", stdin);
#endif
    int t,i;
    long long lx,ls,rx,rs,u;
    char input[300];
    fgets(input, 300, stdin);
    sscanf(input, "%d", &t);
    while(t--){
        lx=ls=rx=rs=0;
        fgets(input, 300, stdin);
        format(input);
        i=abstract(input, &lx, &ls, '=');
        abstract(input+i+1, &rx, &rs, '\n');
        if(lx==rx&&ls==rs)
            puts("IDENTITY");
        else{
            lx-=rx;
            rs-=ls;
            if(lx==0)
                puts("IMPOSSIBLE");
            else{
                u=rs/lx;
                if(u<0&&rs%lx!=0)
                    --u;
                printf("%lld\n", u);
            }
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

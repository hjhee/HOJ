#include <stdio.h>
#include <string.h>

int main(void){
    int i,len,mark;
    char string[200];
    while(fgets(string, 200, stdin)!=NULL){
        for(len=strlen(string), mark=i=0; i<len; ++i)
            if('A'<=string[i]&&string[i]<='Z')
                mark+=string[i]-'A'+1;
        if(mark<=100)
            printf("%d\n", mark);
        else
            printf("INVALID\n");
    }
    return 0;
}

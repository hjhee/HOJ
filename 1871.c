#include <stdio.h>

int main(void){
    int n,i;
    unsigned k,hex[20];
    const char gap[]="0x%c%c ";
    const char end[]="0x%c%c\n";
    scanf("%d", &n);
    while(n--){
        scanf("%u", &k);
        for(i=0; i<8; ++i){
            hex[i]=k%16;
            k/=16;
        }
        for(i=1; i<8; i+=2)
            printf(i==7?end:gap, hex[i]<10?hex[i]+'0':hex[i]+'A'-10,
                    hex[i-1]<10?hex[i-1]+'0':hex[i-1]+'A'-10);
    }
    return 0;
}

#include <stdio.h>
#define ESP 1E-7
#define N 10000

char string[N],type[N];

int main(void){
    long long acmperk;
    double mileage;
    while(fgets(string, N, stdin)!=NULL){
        sscanf(string, "%s", type);
        if(*type=='#')
            break;
        acmperk=0;
        while(acmperk==0||fgets(string, N, stdin)!=NULL){
            sscanf(string, "%s", type);
            if(*type=='0')
                break;
            sscanf(string, "%*s%*s%lf%s", &mileage, type);
            switch(toupper(*type)){
                case 'F': acmperk+=mileage*2; break;
                case 'B': acmperk+=mileage*1.5+0.5; break;
                case 'Y': acmperk+=(mileage-500<ESP)?500:mileage; break;
            }
        }
        printf("%lld\n", acmperk);
    }
    return 0;
}

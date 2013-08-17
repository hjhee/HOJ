#include <stdio.h>

int main(void){
    int p;
    unsigned long long A,B,C,k,Q,P,U,K;
    unsigned long long times;
#ifndef ONLINE_JUDGE
    freopen("1787.in", "rb", stdin);
#endif
    while(scanf("%llu%llu%llu%llu", &A, &B, &C, &k), A||B||C||k){
        times=0;
        /*
        printf("\nA: %llu, B: %llu, C: %llu\n", A, B, C);
        */
        if(A==B)
            puts("0");
        else if(C==0)
            puts("FOREVER");
        else{
            P=(long long)1<<k;
            U=A;
            p=0;
            while(B!=A){
                /*
                printf("A=%llu\n", A);
                */
                if(A<B&&(B-A)%C==0){
                    times+=(B-A)/C;
                    break;
                }else{
                    Q=(P-1-A)/C+1;
                    times+=Q+1;
                    A=A+C*(Q+1)-P;
                }
                if(U==A||(p&&K==A)){
                    puts("FOREVER");
                    goto exit;
                }
                if(!p)
                    K=A;
                ++p;
            }
            printf("%llu\n", times);
        }
exit:
                ;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

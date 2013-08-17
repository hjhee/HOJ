#include <stdio.h>
#define MOD 10000000
#define INIT(Q, p, q) { \
    (Q)[0][0]=1; \
    (Q)[0][1]=(p); \
    (Q)[0][2]=(q); \
    (Q)[1][0]=0; \
    (Q)[1][1]=(p); \
    (Q)[1][2]=(q); \
    (Q)[2][0]=0; \
    (Q)[2][1]=1; \
    (Q)[2][2]=0; \
}

int p,q;

void view(long long (*A)[3]){
    int i,j;
    for(i=0; i<3; ++i){
        for(j=0; j<3; ++j)
            printf("%lld ", A[i][j]);
        putchar('\n');
    }
}

void multiply(long long (*A)[3], long long (*B)[3], long long (*C)[3]){
    int i,j,k;
    long long sum;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j){
            sum=0;
            for(k=0; k<3; ++k)
                sum=(sum+A[i][k]*B[k][j])%MOD;
            C[i][j]=sum;
        }
}

void sum(long long (*A)[3], int n){
    long long B[3][3],C[3][3];
    if(n<=1)
        return;
    INIT(B, p, q);
    sum(B, n>>1);
    if(n&1){
        multiply(B, A, C);
        multiply(B, C, A);
    }else
        multiply(B, B, A);
    /*
    printf("%d:\n", n);
    view(A);
    */
}

int main(void){
    int t,a,b,s,e;
    long long se,ss,A[3][3];
#ifndef ONLINE_JUDGE
    freopen("2255.in", "rb", stdin);
#endif
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d%d", &a, &b, &p, &q, &s, &e);
        /*
        printf("(%d, %d, %d), (%d, %d), (%d, %d)\n", a+b, b, a, p, q, s, e);
        */
        --s;
        if(s==-1)
            ss=0;
        else if(s==0)
            ss=a;
        else if(s==1)
            ss=a+b;
        else{
            INIT(A, p, q);
            sum(A, s-1);
            ss=(A[0][0]*(a+b)+b*A[0][1]+a*A[0][2])%MOD;
        }
        /*
        view(A);
        putchar('\n');
        */
        if(e==0)
            se=a;
        else if(e==1)
            se=a+b;
        else{
            INIT(A, p, q);
            sum(A, e-1);
            se=(A[0][0]*(a+b)+b*A[0][1]+a*A[0][2])%MOD;
        }
        /*
        view(A);
        putchar('\n');
        */
        /*
        printf("%lld %lld\n", ss, se);
        */
        se-=ss;
        if(se<0)
            se+=MOD;
        else
            se%=MOD;
        printf("%lld\n", se);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

#include <stdio.h>

int main(void){
    int n,blocks[100],avg,i,costs,se;
    se=1;
    while(scanf("%d", &n), n){
        for(avg=i=0; i<n; ++i){
            scanf("%d", blocks+i);
            avg+=blocks[i];
        }
        for(avg/=n, costs=i=0; i<n; ++i)
            if(avg>blocks[i])
                costs+=avg-blocks[i];
        printf("Set #%d\n", se++);
        printf("The minimum number of moves is %d.\n", costs);
        putchar('\n');
    }
    return 0;
}

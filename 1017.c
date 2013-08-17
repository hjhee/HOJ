#include <stdio.h>
 
int x[] = { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };
 
void main()
{
        int n;
       
        for(;;)
        {
                scanf("%d", &n);
                if(!n) break;
                printf("%d\n", x[n-1] );       
        }
} 
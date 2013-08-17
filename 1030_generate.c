#include <stdio.h>
#define N 10

int main(void){
    FILE *fout;
    fout=fopen("1030.in", "wb");
    int i,j;
    fprintf(fout, "1\n%d %d\n", N, N);
    for(i=0; i<N; ++i)
        fputc('#', fout);
    fputc('\n', fout);
    for(i=1; i<N-1; ++i){
        switch(i%4){
            case 0: case 2: fputc('#', fout); for(j=1; j<N-1; ++j) fputc('.', fout); fprintf(fout, "#\n"); break;
            case 1: for(j=0; j<N-2; ++j) fputc('#', fout); fprintf(fout, ".#\n"); break;
            case 3: fprintf(fout, "#."); for(j=2; j<N; ++j) fputc('#', fout); fputc('\n', fout); break;
        }
    }
    for(i=0; i<N; ++i)
        fputc('#', fout);
    fputc('\n', fout);
    fclose(fout);
    return 0;
}

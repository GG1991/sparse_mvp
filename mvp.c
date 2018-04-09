// computes b = A*x 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000
#define NON_ZEROS 5
#define N_TEST 10

int main (int argc, char **argv) 
{

  srand(time(NULL));   // should only be called once
  double start, end, cpu_time_used;

  int test, N_MAT;
  for (test=0; test<N_TEST; test++) {

    N_MAT = N*(test+1)/N_TEST;

    int *row = malloc((N_MAT+1)*sizeof(int));
    int *col = malloc(N_MAT*NON_ZEROS*sizeof(int));
    double *vals = malloc(N_MAT*NON_ZEROS*sizeof(double));
    double *x = malloc(N_MAT*sizeof(double));
    double *b = malloc(N_MAT*sizeof(double));

    int i, j;

    start = clock();

    row[0] = 0;
    for (i=1; i<N_MAT+1; i++) {
      row[i] = NON_ZEROS*i;  
      x[i] = 1.0*(rand()%10);  
    }

    for (i=0; i<N_MAT*NON_ZEROS; i++) {
      vals[i] = 1.0*(rand()%10);
      col[i] = rand()%N_MAT;  
    }

    for (i=0; i<N_MAT; i++) {
      b[i] = 0.0;
      for (j=0; j<NON_ZEROS; j++)
	b[i] += vals[row[i] + j] * x[col[j]];
    }

    /*
       printf("x =\n", x[i]);
       for (i=0; i<N_MAT; i++)
       printf("%lf\n", x[i]);
       printf("\n");

       printf("b =\n", x[i]);
       for (i=0; i<N_MAT; i++)
       printf("%lf\n", b[i]);
       printf("\n");
     */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("N_MAT = %-4d cpu_time = %lf\n", N_MAT, cpu_time_used);

    free(row);
    free(col);
    free(vals);
    free(x);
    free(b);
  }

  return 0;
}

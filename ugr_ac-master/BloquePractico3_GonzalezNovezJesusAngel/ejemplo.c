/*objective:
matrix multiplication in dynamic way
*/
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
int main(int argc,char *argv[]){
int **M1,**M2,**M;
// variables to store allocated memory
int N=atoi(argv[1]), nthreads, tid, chunk =10;
//variables to input matrix size and variables to be used by OpenMP functions
double tiempo;
//variable to calculate the time tiempoference between the parallelization
int i,j,k;

M1=(int**) malloc(10*N);
for( i=0;i<N; i++) M1[i]=(int*) malloc(10*N);

M2=(int**) malloc(10*N);
for(i=0;i<N; i++) M2[i]=(int*) malloc(10*N);

M=(int**) malloc(10*N);
for(i=0;i< N; i++) M[i]=(int*) malloc(10*N);

printf("Initializing matrices...\n");
printf("Hello\n");
double t1 = omp_get_wtime();

#pragma omp parallel shared(M1,M2,M,nthreads,chunk) private(tid,i,j,k)
{
  tid = omp_get_thread_num();
  if(tid == 0)
  {
    nthreads = omp_get_num_threads();
    printf("t1ing matrix multiple example with %d threads \n",nthreads);
  }
  //initializing first matrix
  #pragma omp for schedule (static, chunk)
  for(i=0;i<N; i++){
   for(j=0;j<N; j++){
     M1[i][j] = i*j+1;
   }
  }

  // initializing second matrix
  #pragma omp for schedule (static,chunk)
  for(i=0;i<N; i++){
   for(j=0;j<N; j++){
     M2[i][j] = 1;
   }
  }
  
  /*initialize product matrix */
  #pragma omp for schedule (static, chunk)
  for(i=0;i<N; i++){
   for(j=0;j< N; j++){
     M[i][j]=0;
   }
  }

  /*** Do matrix multiply sharing iterations on outer loop ***/
  /*** Display who does which iterations for demonstration purposes ***/
  printf("Thread %d t1ing matrix multiply...\n",tid);
  #pragma omp for schedule (static, chunk)
  for(i=0;i<N; i++){
    for(j=0;j<N; j++){
      for(k=0;k<N; k++){
        M[i][j]=M[i][j]+M1[i][k]*M2[k][j];
      }
    }
  }
}
/*****t2 of parallel region*****/
printf("******************************************************\n");
if(N<10){
for(i=0;i<N; i++){
  for(j=0;j< N; j++){
    printf("%d ",M1[i][j]);
  }
  printf("\n");
}
for(i=0;i<N; i++){
  for(j=0;j< N; j++){
    printf("%d ",M2[i][j]);
  }
  printf("\n");
}
for(i=0;i<N; i++){
  for(j=0;j< N; j++){
   printf("%d ",M[i][j]);
  }
  printf("\n");
}
}
else{
  printf("M[0][0]:%d\n",M[0][0]);
  printf("M[N-1][N-1]:%d\n",M[N-1][N-1]);
}
printf ("Done.\n");
double t2 = omp_get_wtime( );
//t2 the timer
tiempo = t2-t1;
//store the tiempoference
printf("Parallelization took %f sec. time.\n", tiempo);
/*free memory*/
for (i=0;i<N; i++)  free(M1[i]);
free(M1);
for (i=0;i<N; i++)  free(M2[i]);
free(M2);
for (i=0;i<N; i++)  free(M[i]);
free(M);
}


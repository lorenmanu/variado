#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
int main(int argc,char *argv[]){
/*------Comprobamos que se dieron bien los parámetros-----------------------------*/
	if(argc < 2) {
		fprintf(stderr,"Uso:./pmm-parallel N\n");
		exit(-1);
	}
	srand(time(0));
/*------Declaramos variables que se usarán---------------------------------------*/
int **M1,**M2,**M;
int N=atoi(argv[1]);

double tiempo;
int i,j,k;

M1=(int**) malloc(10*N);
for( i=0;i<N; i++) M1[i]=(int*) malloc(10*N);

M2=(int**) malloc(10*N);
for(i=0;i<N; i++) M2[i]=(int*) malloc(10*N);

M=(int**) malloc(10*N);
for(i=0;i< N; i++) M[i]=(int*) malloc(10*N);

double t1 = omp_get_wtime();

/*------Inicializamos M y V--------------------------------------------------------*/	
#pragma omp parallel shared(M1,M2,M) private(i,j)
{
  #pragma omp for schedule (runtime)
  for(i=0;i<N; i++){
   for(j=0;j<N; j++){
     M1[i][j] = i*j+1;
   }
  }

  #pragma omp for schedule (runtime)
  for(i=0;i<N; i++){
   for(j=0;j<N; j++){
     M2[i][j] = 1;
   }
  }
  
  #pragma omp for schedule (runtime)
  for(i=0;i<N; i++){
   for(j=0;j< N; j++){
     M[i][j]=0;
   }
  }
}
/*------Multiplicamos M1 x M2 = M--------------------------------------------------*/
#pragma omp parallel shared(M1,M2,M) private(i,j,k)
{

     #pragma omp for schedule (runtime)
     for(i=0;i<N; i++){
      for(j=0;j<N; j++){
       for(k=0;k<N; k++){
        M[i][j] = M[i][j] + M1[i][k] * M2[k][j];
       }
      }
    }
}

/*------Mostrar los resultados---------------------------------------------------*/
if(N<10){
for(i=0;i<N; i++){
  for(j=0;j< N; j++){
    printf("%d ",M1[i][j]);
  }
  printf("\n");
}
printf("\n");
for(i=0;i<N; i++){
  for(j=0;j< N; j++){
    printf("%d ",M2[i][j]);
  }
  printf("\n");
}
printf("\n");
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

double t2 = omp_get_wtime( );
tiempo = t2-t1;
printf("Tiempo: %f seg\n", tiempo);

/*------Liberar memoria----------------------------------------------------------*/
for (i=0;i<N; i++)  free(M1[i]);
free(M1);
for (i=0;i<N; i++)  free(M2[i]);
free(M2);
for (i=0;i<N; i++)  free(M[i]);
free(M);
}


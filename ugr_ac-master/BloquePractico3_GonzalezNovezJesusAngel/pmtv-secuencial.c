#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif


void main(int argc,char **argv) {
/*------Comprobamos que se dieron bien los parámetros-----------------------------*/
	if(argc < 2) {
		fprintf(stderr,"Uso:./pmtv-secuencial N \n");
		exit(-1);
	}
	srand(time(0));
	
/*------Declaramos variables que se usarán---------------------------------------*/
	int N=atoi(argv[1]), i, j;
	double t1,t2;
	int *V;
	V = (int *)malloc (10*N);
	int *V2;
	V2 = (int *)malloc (10*N);
	int **M;
	M = (int **)malloc (10*N);
	for(i=0; i<N; i++) 
		M[i] = (int *)malloc (10*N);
	

	
/*------Inicializamos M y V--------------------------------------------------------*/	
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++)
	    if(j >= i)  M[i][j] = i+j+1;
	    else        M[i][j] = 0;

	for(i=0; i<N; i++){
		V[i] = i+1;
		V2[i] = 0;
	}
	
/*------Multiplicamos M x V = V2--------------------------------------------------*/
	t1 = omp_get_wtime();
	for(i=0; i<N; i++){
		V2[i] = 0;
		for(j=0; j<N; j++){
		        if(j >= i) 
		          V2[i] += M[i][j] * V[j];
		        else 
		          V2[i] = 0;
		}
	}
	t2 = omp_get_wtime();
	t2 = t2-t1;
	
/*------Mostrar los resultados---------------------------------------------------*/
	if(N<10){
		printf("M:\n");
		for(i=0; i<N; i++){
			for(j=0; j<N; j++)
				printf("%d ",M[i][j]);
			printf("\n");
		}
		printf("\nV:\n");
		for(i=0; i<N; i++) printf("%d \n",V[i]);
		printf("\nResultado MxV:\n");
		for(i=0; i<N; i++) printf("%d ",V2[i]);
	}else{
		printf("V2[0]:%d\n",V2[0]);
		printf("V2[N-1]:%d\n",V2[N-1]);
	}
	printf("\nTiempo en ejecutar MxV:%8.6f\n",t2);
	
	
/*------Liberar memoria----------------------------------------------------------*/	
	for(i=0; i<N; i++)
		free(M[i]);
	free(M);
	free(V);
	free(V2);
}


/*Implementar un programa secuencial en C que calcule el producto de una matriz cuadrada, M, por un vector, v1:
NOTAS:
 (1) el número de filas /columnas N de la matriz deben ser argumentos de entrada al programa; 
 (2) se debe inicializar la matriz y el vector antes del cálculo;
 (3) se debe asegurar que el programa calcula la suma correctamente  imprimiendo todos los componentes del vector resultante,
     v3, para tamaños pequeños de los vectores (por ejemplo, N = 8 y N=11); 
 (4) se debe imprimir sea cual sea el tamaño de los vectores el tiempo de ejecución del código paralelo que calcula el producto matriz  
     vector y, al menos, el primer y último componente del resultado (esto último evita que las optimizaciones del compilador eliminen el
     código de la suma).
*/
#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif


void main(int argc,char **argv) {
	int N=atoi(argv[1]), i, j;
	double t1,t2;
	int *V;
	V = (int *)malloc (N*sizeof(int));
	int *V2;
	V2 = (int *)malloc (N*sizeof(int));
	int **M;
	M = (int **)malloc (N*sizeof(int *));
	for(i=0; i<N; i++) 
		M[i] = (int *)malloc (N*sizeof(int));
	
	
	
/*------Comprobamos que se dieron bien los parámetros-----------------------------*/
	if(argc < 2) {
		fprintf(stderr,"Uso:./ejercicio8 N \n");
		exit(-1);
	}
	srand(time(0));
	
/*------Inicializamos M y V--------------------------------------------------------*/
	  #pragma omp parallel for
	  for(i=0; i<N; i++){
	  	for(j=0; j<N; j++){
			M[i][j]	= 1;
		}
	  }
	
	  #pragma omp parallel for
	  for(i=0; i<N; i++)
		V[i] = i+1;
	
	
/*------Multiplicamos M x V = V2--------------------------------------------------*/
	t1 = omp_get_wtime();
	int res;
	#pragma omp parallel shared(M,V) private (j) reduction(+:res)
		{
	  #pragma omp for schedule(static)
	  for(i=0; i<N; i++)
	  {
		int res = 0;
		
	
		
		for(j=0; j<N; j++)
			res = M[i][j] * V[j];
		V2[i] = res;
		
		
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
	printf("Max number of threads: %i \n",omp_get_max_threads());
	
/*------Liberar memoria----------------------------------------------------------*/	
	for(i=0; i<N; i++)
		free(M[i]);
	free(M);
	free(V);
	free(V2);
}


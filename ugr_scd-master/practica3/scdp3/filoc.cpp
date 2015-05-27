/*
 *	Filósofos con camarero
 *	filoc.cpp
 *	JESUS ANGEL GONZALEZ NOVEZ
 *			76440070F
 */
#include <mpi.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 	
#include <iostream>
using namespace std;

#define Camarero 10
#define TAGSentarse 0
#define TAGLevantarse 1
#define TAGCogeTenedor 2
#define TAGSueltaTenedor 3
/* Función Filosofo */
void Filosofo(int rank, int size){
	int peticion;
	int izq = rank + 1;
	int der;
	if(rank == 0)
		der = 9;
	else
		der = rank - 1;
	while(true){
		cout << "Filosofo " << rank << " PENSANDO " << endl << flush;
		sleep(rand()%2);
			
		//cout << "Filosofo " << rank << " SENTANDO " << endl << flush;
		MPI_Ssend( &peticion, 1, MPI_INT,Camarero,TAGSentarse, MPI_COMM_WORLD );	
	
	  	MPI_Ssend( &rank, 1, MPI_INT,izq,TAGCogeTenedor, MPI_COMM_WORLD);
       		//cout << "Filosofo " << rank << " solicita tenedor izq "  << izq << endl << flush;
            
	        MPI_Ssend( &rank, 1, MPI_INT,der,TAGCogeTenedor, MPI_COMM_WORLD);
       		//cout << "Filosofo " << rank << " coge tenedor der " << der << endl << flush;

		cout << "Filosofo: " << rank << " COMIENDO " << endl << flush;
		sleep(rand()%2);
	
		//cout << "Filosofo " << rank << " suelta tenedor izq  " << izq << endl << flush;
		MPI_Ssend( &rank, 1, MPI_INT,izq,TAGSueltaTenedor, MPI_COMM_WORLD );
              
		//cout << "Filosofo " << rank << " suelta tenedor der  " << der << endl << flush;
		MPI_Ssend( &rank, 1, MPI_INT,der,TAGSueltaTenedor, MPI_COMM_WORLD );
		
		//cout << "Filosofo " << rank << " LEVANTANDO " << endl << flush;
		MPI_Ssend( &peticion, 1, MPI_INT,Camarero,TAGLevantarse, MPI_COMM_WORLD );	
	}
}


/* Función Tenedor */
void Tenedor(int rank, int size){
	int Filo;
	MPI_Status status;
	while(true){
		MPI_Recv(&Filo, 1, MPI_INT, MPI_ANY_SOURCE, TAGCogeTenedor, MPI_COMM_WORLD, &status);
		//cout << "Ten. " << rank << " recibe petic. de " << Filo << endl << flush;
		MPI_Recv(&Filo, 1, MPI_INT, MPI_ANY_SOURCE, TAGSueltaTenedor, MPI_COMM_WORLD, &status);
		//cout << "Ten. " << rank << " recibe liberac. de " << Filo << endl << flush;
	}
}


/* Función Camarero */
void camarero(){	
	int peticion,etiqueta;
	int sentados=0;
	MPI_Status status;
	while(true){
		if (sentados < 4)
			if(sentados == 0)
				etiqueta = TAGSentarse;
			else
				etiqueta = rand()%2;
		else
			etiqueta = TAGLevantarse;
			
		MPI_Recv(&peticion,1,MPI_INT,MPI_ANY_SOURCE,etiqueta,MPI_COMM_WORLD,&status);
		if(etiqueta == TAGSentarse)
			sentados++;
		else
			sentados--;
		//cout << "Clientes sentados:" << sentados << endl << flush;
	}
}

/* Programa principal */
int main(int argc, char **argv){
	int rank, size;
	srand(time(0));
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(size != 11){
		//cout << "Uso mpirun -np 11 camarero" << endl << flush;
		MPI_Finalize();
		return 0;
	}
	if( ((rank % 2) == 0) && (rank != Camarero)){
		Filosofo(rank,size);	// Los pares son Filosofos
	}else
		if(rank == Camarero)
			camarero(); // El camarero es el 10
		else
			Tenedor(rank,size);	// Los impares som Tenedores
	
	MPI_Finalize();
	return 0;
}

/*
 *	Filósofos sin camarero
 *	filo.cpp
 *	JESUS ANGEL GONZALEZ NOVEZ
 *			76440070F
 */
#include <mpi.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h> 	
#include <unistd.h> 	
#include <iostream>
using namespace std;
/* Función Filosofo */
void Filosofo(int rank, int size){
	int izq = (rank + 1) % size;
	int der = (rank-1 + size) % size;
	while(true){
		if(rank == 0){
		  	MPI_Ssend( &rank, 1, MPI_INT,der,der, MPI_COMM_WORLD);
          		cout << "Filosofo " << rank << " solicita tenedor derecho " << der << endl << flush;
                
		       	MPI_Ssend( &rank, 1, MPI_INT,izq,izq, MPI_COMM_WORLD);
          		cout << "Filosofo " << rank << " coge tenedor izquierdo " << izq << endl << flush;
		}else{
		  	MPI_Ssend( &rank, 1, MPI_INT,izq,izq, MPI_COMM_WORLD);
          		cout << "Filosofo " << rank << " solicita tenedor izq "  << izq << endl << flush;
            
		        MPI_Ssend( &rank, 1, MPI_INT,der,der, MPI_COMM_WORLD);
            		cout << "Filosofo " << rank << " coge tenedor der " << der << endl << flush;
        }
		cout << "Filosofo: " << rank << " COMIENDO " << endl << flush;
		sleep(1);
	
		cout << "Filosofo " << rank << " suelta tenedor izq  " << izq << endl << flush;
		MPI_Ssend( &rank, 1, MPI_INT,izq,rank, MPI_COMM_WORLD );
              
		cout << "Filosofo " << rank << " suelta tenedor der  " << der << endl << flush;
		MPI_Ssend( &rank, 1, MPI_INT,der,rank, MPI_COMM_WORLD );
		cout << "Filosofo " << rank << " PENSANDO " << endl << flush;
		sleep(1);	
	}
}


/* Función Tenedor */
void Tenedor(int rank, int size){	// Código proceso Tenedor
	int Filo;
	MPI_Status status;
	while(true){
		MPI_Recv(&Filo, 1, MPI_INT, MPI_ANY_SOURCE, rank, MPI_COMM_WORLD, &status);
		cout << "Ten. " << rank << " recibe petic. de " << Filo << endl << flush;
		MPI_Recv(&Filo, 1, MPI_INT, MPI_ANY_SOURCE, Filo, MPI_COMM_WORLD, &status);
		cout << "Ten. " << rank << " recibe liberac. de " << Filo << endl << flush;
	}
}


/* Programa principal */
int main(int argc, char **argv){
	int rank, size;
	srand(time(0));	// Inicializa la semilla aleatoria
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(size != 10){
		//cout << "Uso mpirun -np 10 filosofos" << endl << flush;
		MPI_Finalize();
		return 0;
	}
	if( (rank % 2) == 0)
		Filosofo(rank,size);	// Los pares son Filosofos
	else
		Tenedor(rank,size);	// Los impares som Tenedores
	
	MPI_Finalize();
	return 0;
}

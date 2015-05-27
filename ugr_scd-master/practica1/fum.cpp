/* 
 * File: 
 *	 fum.cpp
 * Author:
 *	 Jesús Ángel González Novez
 * Title:  
 *	 Fumadores
 * Modo de uso:
 *	 g++ -o fum fum.cpp  -lrt -lpthread
 *	 ./fum
 */
#include <iostream>
#include <time.h> // incluye ”time(....)”
#include <unistd.h> // incluye ”sleep(....)”
#include <stdlib.h> // incluye ”rand(...)”
#include <semaphore.h>

using namespace std;

sem_t mutex, f_tabaco, f_papel, f_cerillas, ingredientes_retirados;

// función que simula la acción de fumar como un retardo aleatorio de la hebra
void fumar();

void* fumador1(void*);
void* fumador2(void*);
void* fumador3(void*);
void* colocar(void*);

int main(){
   srand ( time(NULL) ); // inicializa la semilla aleatoria
   pthread_t fumador_tabaco, fumador_papel, fumador_cerillas, estanquero;
   sem_init( &f_tabaco, 0, 0 );
   sem_init( &f_papel, 0, 0 );
   sem_init( &f_cerillas, 0, 0 );
   sem_init( &ingredientes_retirados, 0, 1 ); // semaforo para colocar ingredientes: inicializado a 1
   sem_init( &mutex, 0, 1 ); // semaforo para EM para cout: inicializado a 1

   cout << "Comienza el reparto:";

   pthread_create( &fumador_tabaco, NULL, fumador1, NULL );
   pthread_create( &fumador_papel, NULL, fumador2, NULL );
   pthread_create( &fumador_cerillas, NULL, fumador3, NULL );
   pthread_create( &estanquero, NULL, colocar, NULL );

   
   
   pthread_join( estanquero, NULL );
   sem_wait(&mutex);
   cout << "\n\nFin." << endl ;
   sem_post(&mutex);
   pthread_join( fumador_tabaco, NULL );
   pthread_join( fumador_papel, NULL );
   pthread_join( fumador_cerillas, NULL );
   

   sem_destroy( &f_tabaco );
   sem_destroy( &f_papel );
   sem_destroy( &f_cerillas );
   sem_destroy( &ingredientes_retirados );
   sem_destroy( &mutex );
	

   return 0;
}

void fumar(){
	sleep(rand()%5);
}

void* fumador1( void* ){
   while(true){
      sem_wait(&f_tabaco);

      sem_wait(&mutex);
      cout << "\nFuma el que tiene tabaco.";
      sem_post(&mutex);

      sem_post(&ingredientes_retirados);
      fumar();
   }

   return NULL;
}
void* fumador2( void* ){
   while(true){
      sem_wait(&f_papel);

      sem_wait(&mutex);
      cout << "\nFuma el que tiene papel.";
      sem_post(&mutex);

      sem_post(&ingredientes_retirados);
      fumar();
   }

   return NULL;
}
void* fumador3( void* ){
   while(true){
      sem_wait(&f_cerillas);

      sem_wait(&mutex);
      cout << "\nFuma el que tiene cerillas.";
      sem_post(&mutex);

      sem_post(&ingredientes_retirados);
      fumar();
   }

   return NULL;
}
void* colocar( void* ){
   while(true){
      static int i=0,j=0,k=0,l=1;
      sem_wait(&ingredientes_retirados);
      int quien = rand()%3 + 1;
      if(quien == 1){
	i++;
         sem_wait(&mutex);
         cout << "\nEstanquero coloca papel y cerillas por " << i << "ª vez,reparto nº" << l;
         sem_post(&mutex);
         sem_post(&f_tabaco);
      }
      else if(quien == 2){
	 j++;
         sem_wait(&mutex);
         cout << "\nEstanquero coloca tabaco y cerillas por " << j << "ª vez,reparto nº" << l;
         sem_post(&mutex);
         sem_post(&f_papel);
      }
      else{
	 k++;
         sem_wait(&mutex);
         cout << "\nEstanquero coloca tabaco y papel por " << k << "ª vez,reparto nº" << l;
         sem_post(&mutex);
         sem_post(&f_cerillas);
      }
	l++;


	
   }

   return NULL;
}

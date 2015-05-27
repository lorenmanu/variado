/* 
 * File: 
 *	 pc2.cpp
 * Author:
 *	 Jesús Ángel González Novez
 * Title:  
 *	 Productor/Consumidor 2
 * Modo de uso:
 *	 g++ -o pc2 pc2.cpp -lrt -lpthread
 *	 ./pc2
 */
#include <iostream>
#include <pthread.h> //Libreria para las hebras
#include <semaphore.h> //Libreria para los semáforos
using namespace std;
//Variables globales
const int num_items = 40,tam_vec = 10;
int BUFFER[tam_vec];
sem_t llenos, vacios, mutex;
  pthread_t prod2;
int indice = 0;
int cont_aux=0;
//Funciones para producir/consumir dato
int producir_dato();
void consumir_dato(int dato);

//Funciones hebra
void *productor(void *);
void * consumidor(void *);
void *productor2(void *);
int main(int argc,char * arg[]){
        pthread_t prodh; 
        pthread_t consh; 
      

	sem_init(&vacios,0,0); 
        sem_init(&llenos,0,tam_vec); 
	sem_init(&mutex,0,1);

	cout << "PRODUCTOR/CONSUMIDOR" << endl;

        pthread_create(&prodh,NULL,productor,NULL); 
        pthread_create(&consh,NULL,consumidor,NULL); 

        pthread_join(prodh,NULL);
	pthread_join(prod2,NULL);
        pthread_join(consh,NULL); 
	
	sem_destroy(&llenos);
	sem_destroy(&vacios);

        cout << "FIN" << endl; //Imprimir por pantalla "fin"
}

int producir_dato(){ 
	static int contador = 1 ;
	return contador ++ ;
}

void consumir_dato( int dato ){

	cout << "Dato recibido: " << dato << endl;
	
}

void *productor(void *){
	for (unsigned i=1;i<=20;i++){
				
		int dato = producir_dato();               
		sem_wait(&llenos); 
		sem_wait(&mutex);                
		BUFFER[indice] = dato; 
        	indice++;
		sem_post(&mutex);
               	sem_post(&vacios); 
	}
        return NULL;
}


void *productor2(void *){
	for (unsigned i=21;i<=num_items;i++){
				
		int dato = producir_dato();               
		sem_wait(&llenos); 
		sem_wait(&mutex);                
		BUFFER[indice] = dato; 
        	indice++;
		sem_post(&mutex);
               	sem_post(&vacios); 
	}
        return NULL;
}

void * consumidor(void *){
        for(unsigned i=1;i<=num_items;i++){
			cont_aux++;
                int dato;
		sem_wait(&vacios); 
		sem_wait(&mutex);                
		dato = BUFFER[indice-1]; 
         	indice--;	
		sem_post(&mutex);
		sem_post(&llenos);
		consumir_dato(dato);
		if(cont_aux == 20){
			sem_destroy(&llenos);
	                sem_destroy(&vacios);
			sem_init(&vacios,0,0); 
        		sem_init(&llenos,0,tam_vec);
			pthread_create(&prod2,NULL,productor2,NULL);  
		} 
	}
	
        return NULL;
}



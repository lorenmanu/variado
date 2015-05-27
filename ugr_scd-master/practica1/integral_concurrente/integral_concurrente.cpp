/* 
 * File:   main.cpp
 * Author: root
 * CALCULAR INTEGRAL CONCURRENTEMENTE
 * Created on 21 de octubre de 2013, 12:05
 */

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <time.h>
#include "fun_tiempo.h"
using namespace std;
const unsigned long m = 1024 * 1024 * 1024; //num de muestras
const unsigned long n = 2; //num de hebras
double resultado_parcial[n]; //vector de resultados parciales

double f(double x){
    return 4.0/(1+x*x);
}
void * funcion_hebra( void * ih_void ){
    // función que ejecuta cada hebra , ih es el índice hebra
    unsigned long ih = (unsigned long) ih_void ;
    double sumap = 0.0 ;
    // calcular suma parcial en ”sumap”
    for(unsigned long c=(m/n)*ih; c<(m/n)*(ih+1); c++)
        sumap += f((c+0.5)/m);
    
    resultado_parcial[ih] = sumap ; // guardar suma parcial en vector.
    return NULL;
}
double calcular_integral_concurrente( ){
    // crear y lanzar n hebras, cada una ejecuta ”funcion concurrente”
   
	pthread_t id_hebra[n];
    double res=0;
    for(unsigned i=0; i<n; i++)
        pthread_create(&(id_hebra[i]),NULL,funcion_hebra,(void *) i);
 
    // esperar (join) a que termine cada hebra, sumar su resultado
    for( unsigned i = 0 ; i < n ; i++ ){
        pthread_join(id_hebra[i],NULL);
        res += resultado_parcial[i];
    }
    // devolver resultado completo

    return res/m;

}


int main(int argc, char** argv) {
    
    cout << "Aproximación de PI = " << calcular_integral_concurrente() << endl;
    

    
}


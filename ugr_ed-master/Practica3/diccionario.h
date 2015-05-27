/* 
 * diccionario.h
 * 
 * Copyright  (C) Juan F. Huete
*/

#ifndef __DICCIONARIO_H
#define __DICCIONARIO_H
#include <string>
#include <vector>
#include <iostream> 

using namespace std;

//! Clase diccionario
 /*! diccionario:: diccionario, null, find, operator[], size, max_element
 * Tipos diccionario::entrada, diccionario::size_type
 * Descripción

* Un diccionario es un contenedor que permite almacenar un conjunto de pares de elementos, el primero será la clave que deber ser única y el segundo la definición.  En nuestro caso el diccionario va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento por clave, además de la consulta del   elemento con mayor valor en la definición). Este diccionario "simulará" un diccionario de la stl, con algunas claras diferencias pue, entre otros,  no estará dotado de la capacidad de iterar (recorrer) a través de sus elementos.

* Asociado al diccionario, tendremos el tipo  \code diccionario::entrada \endcode que permite hacer referencia al par de elementos almacenados en cada una de las posiciones del diccionario. Así, el primer campo de una entrada, first, representa la clave y el segundo campo, second, representa la definición. En nuestra aplicación concreta, la clave será un string representando una palabra válida del diccionario y el segundo campo es un entero que hace referencia a la frecuencia de ocurrencia de la palabra en el lenguaje.

* El número de elementos en el diccionario puede variar dinámicamente; la gestión de la memoria es automática. 
 
 */





class diccionario
{  
public:
	typedef pair<string, int> entrada;
	typedef unsigned int size_type;
	/** @brief constructor primitivo. 
	@post define la entrada nula como el par ("",-1)
	*/
	diccionario( );
	/** @brief constructor primitivo. 
	@param[in] nula representa a la entrada nula para el diccionario
	@post define la entrada nula 
	*/
	diccionario( const entrada & nula);

	/** @brief constructor de copia
	@param[in] d diccionario a copiar
	*/
	diccionario (const diccionario & d);

	/** @brief entrada nula del diccionario
         @return Devuelve la entrada  nula del diccionario.
	@post no modifica el diccionario
        */
	
	
	const entrada & null() const;
	
	/** @brief busca una cadena en el diccionario
	@param s cadena a buscar
	@return una copia de la entrada en el diccionario. Si la palabra s no se encuentra devuelve null()
	@post no modifica el diccionario.
	\verbatim Uso
	if (D.fin("hola")!=D.null()) cout << "Esta" ;
	else cout << "No esta";
	\endverbatim
	*/
	const entrada & find( const string & s) const;
	
	
/** @brief Consulta/Inserta una  entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia al numero de ocurrencias de la misma
en caso contrario la inserta, con frecuencia cero, devolviendo una referencia a este valor.
 
@param[in] s cadena a insertar
@param[out] int & referencia a la definicion asociada  a la entrada
@post  Si s no esta en el diccionario, el size() sera incrementado en 1.
*/
	int & operator[](const string & s);
	
	
/** @brief Consulta  una   entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia constante al numero de ocurrencias de la misma, si no la encuentra da un mensaje de error.
 
@param[in] s cadena a insertar
@param[out] int & referencia constante a la definicion asociada  a la entrada
@post  No se modifica el diccionario.
*/
	 const int & operator[](const string & s) const;

/** @brief operador de asignación
@param[in] org diccionario  a copiar.
 Crea un diccionario duplicado exacto de org.
*/
  diccionario & operator=( const diccionario & org);

	/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/
	size_type size() const ;


/** @brief vacia
   Chequea si el priority_queue esta vacio (size()==0)
*/
  bool empty() const;

	/** @brief devuelve una referencia constante a la entrada con un mayor numero de ocurrencias en el diccionario.
@post  No se modifica el diccionario.
	*/
	const string & max_element( ) const;
	 
	 
	   
	 
private:

	friend  ostream& operator<< ( ostream& , const diccionario& );
    

  
	vector<entrada> dic; // vector que almacena los elementos del diccionario
	int pos_max; // Posicion del elemento con mayor frecuencia  (entrada.second) en el diccionario

  /** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
*/
  bool cheq_rep( ) const;
  
  
 

};


/** @brief imprime todas las entradas del diccionario 
@post  No se modifica el diccionario.
@todo implementar esta funcion
	*/
ostream &  operator << ( ostream & sal, const diccionario & D);

#if defined(DICC_V2)
  #include "diccionarioV2.hxx"
#elif defined(DICC_V1)
  #include "diccionarioV1.hxx"
#else
#error !!! HAY QUE INDICAR LA VERSION DE LA REPRESENTACION A COMPILAR DICC_V1 o DICC_V2
#error compila como: g++ -D version -o ejecutable principal.ccp
#endif
	


#endif

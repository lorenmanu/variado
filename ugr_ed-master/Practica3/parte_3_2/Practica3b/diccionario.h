/* 
 * diccionario.h
 * JESUS ANGEL GONZALEZ NOVEZ
 * 76440070F
*/

#ifndef __DICCIONARIO_H
#define __DICCIONARIO_H
#include <string>
#include <vector>
#include <iostream> 

using namespace std;


template < typename T1, typename T2> class diccionario;

template <typename T1, typename T2>
ostream & operator << ( ostream &sal, const diccionario <T1, T2> &D);

template <typename T1, typename T2>
class diccionario{
	public:
		typedef pair<T1, T2> entrada;
		typedef unsigned int size_type;

		/*
		 * @brief constructor primitivo.
		 * @post define la entrada nula como el par ("",-1)
		 */
		diccionario<T1, T2>( );

		/*
		 *  @brief constructor primitivo.
		 *  @param[in] nula representa a la entrada nula para el diccionario
		 *  @post define la entrada nula
		 */
		diccionario<T1, T2>( const entrada &valor);

		/*
		 * @brief constructor de copia
		 * @param[in] d diccionario a copiar
		 */
		diccionario<T1, T2>(const diccionario<T1, T2> &d);

		/*
		 * @brief entrada nula del diccionario
		 * @return Devuelve la entrada  nula del diccionario
		 * @post no modifica el diccionario
		 */
		const entrada &null() const;

		/*
		 *  @brief busca una cadena en el diccionario
		 *  @param s cadena a buscar
		 *  @return una copia de la entrada en el diccionario. Si la palabra s no se encuentra devuelve null()
		 *  @post no modifica el diccionario.
		 *  \verbatim Uso
		 *  if (D.fin("hola")!=D.null()) cout << "Esta" ;
		 *  else cout << "No esta";
		 *  \endverbatim
		 */
		const entrada & find( const T1 &s) const;


		/*
		 * @brief Consulta/Inserta una  entrada en el diccionario.
		 * Busca la cadena s en el diccionario, si la encuentra devuelve una referencia al numero de ocurrencias de la misma
		 * en caso contrario la inserta, con frecuencia cero, devolviendo una referencia a este valor.
		 * @param[in] s cadena a insertar
		 * @param[out] int & referencia a la definicion asociada  a la entrada
		 * @post  Si s no esta en el diccionario, el size() sera incrementado en 1.
		 */
		T2 & operator[](const T1 & s);


		/*
		 * @brief Consulta  una   entrada en el diccionario.
		 * Busca la cadena s en el diccionario, si la encuentra devuelve una referencia constante al numero de ocurrencias de la misma, si no la encuentra da un mensaje de error.
		 * @param[in] s cadena a insertar
		 * @param[out] int & referencia constante a la definicion asociada  a la entrada
		 * @post  No se modifica el diccionario.
		 */
		const T2 & operator[](const T1 &s) const;
	
		/*
		 * @brief operador de asignación
		 * @param[in] org diccionario  a copiar.
		 * Crea un diccionario duplicado exacto de org
		 */
		diccionario & operator=( const diccionario<T1, T2> &org);
	
		/*
		 * @brief numero de entradas en el diccionario
		 * @post  No se modifica el diccionario.
		 */
		size_type size() const ;

		/*
		 * @brief vacia
		 * Chequea si el priority_queue esta vacio (size()==0
		 */
		bool empty() const;

		/*
		 * @brief devuelve una referencia constante a la entrada con un mayor numero de ocurrencias en el diccionario
		 * @post  No se modifica el diccionario.
		 */
		const T1 &max_element( ) const;

	private:
		/*
		 * @brief imprime todas las entradas del diccionario
		 * @post  No se modifica el diccionario.
		 * @todo implementar esta funcion
		 */
		friend ostream & operator << <>(ostream &sal , const diccionario <T1, T2> &D);
		vector<entrada> dic; // vector que almacena los elementos del diccionario
		int pos_max; // Posicion del elemento con mayor frecuencia  (entrada.second) en el diccionario
	
		/*
		 * @brief Chequea el Invariante de la representacion
		 * @return true si el invariante es correcto, falso en caso contrario
		 */
		bool cheq_rep( ) const;
};

	#if defined(DICC_V2)
	  #include "diccionarioV2.hxx"
	#elif defined(DICC_V1)
	  #include "diccionarioV1.hxx"
	#else
		#error !!! HAY QUE INDICAR LA VERSION DE LA REPRESENTACION A COMPILAR DICC_V1 o DICC_V2
		#error compila como: g++ -D version -o ejecutable prueba.ccp
	#endif
#endif

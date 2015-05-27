/*
 * diccionarioV1.hxx
 *
 * JESUS ANGEL GONZALEZ NOVEZ
 * 76440070F
 */

#ifndef DICCIONARIOV1_HXX_
#define DICCIONARIOV1_HXX_

#include <assert.h>

/**
 @todo Chequear esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2>::diccionario() {
//  diccionario::entrada nula("",-1);
//  dic.push_back(nula);
	pos_max = 0;
}
/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2>::diccionario(const entrada & nula) {
	dic.push_back(nula);
	pos_max = 0;

}
/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2>::diccionario(const diccionario & d) {
	dic = d.dic;
	pos_max = d.pos_max;
}

template<typename T1, typename T2>
const typename diccionario<T1, T2>::entrada & diccionario<T1, T2>::null() const {
	return dic[0];
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
const typename diccionario<T1, T2>::entrada & diccionario<T1, T2>::find(
		const T1 & s) const {
	for (int i = 1; i < dic.size(); i++)
		if (dic[i].first == s)
			return dic[i];
	return null();
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
T2 & diccionario<T1, T2>::operator[](const T1 &s) {
	bool encontrado = false;
	int i;
	for (i = 1; i < dic.size() && !encontrado;) {
		if (dic[i].first == s)
			encontrado = true;
		else
			i++;
	}
	if (!encontrado) {
		diccionario<T1, T2>::entrada entrada;
		dic.push_back(entrada);
		i = dic.size() - 1;
	}
	return dic[i].second;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
const T2 & diccionario<T1, T2>::operator[](const T1 &s) const {
	bool encontrado = false;
	int i;
	for (i = 0; i < dic.size() && !encontrado;) {
		if (dic[i].first == s)
			encontrado = true;
		else
			i++;
	}
	assert(encontrado == true);
	return dic[i].second;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2> & diccionario<T1, T2>::operator=(const diccionario<T1, T2> &org) {
	if (this != &org) {
		dic = org.dic;
		pos_max = org.pos_max;
	}
	return *this;
}

/**@todo implementa esta funcion.
 */
template<typename T1, typename T2>
typename diccionario<T1, T2>::size_type diccionario<T1, T2>::size() const {
	return dic.size() - 1;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
bool diccionario<T1, T2>::empty() const {
	return (dic.size() == 1);
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
const T1 & diccionario<T1, T2>::max_element() const {
	size_type p_max = 0;
	T2 cuantos = dic[p_max].second;
	for (int i = 1; i < dic.size(); i++)
		if (dic[i].second > cuantos) {
			cuantos = dic[i].second;
			p_max = i;
		}
	return dic[p_max].first;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
bool diccionario<T1, T2>::cheq_rep() const {
	// Chequearemos puntos i) y iii), pues el 2 no se puede chequear

	assert(size() == dic.size() - 1);
	for (int i = 1; i < dic.size(); i++) {
		assert(dic[i].second >= 0); //Valores >= que 0
		for (int j = 0; j < dic.size(); j++)
			if (j != i)
				assert(dic[i].first != dic[j].first); // No se repite clave, incluido la nula
	}
	return true;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
ostream & operator <<(ostream & sal, const diccionario<T1, T2> & D) {
	sal << "size : " << D.size() << " => [";
	for (int i = 0; i < D.dic.size(); i++)
		sal << "(" << i << ":: " << D.dic[i].first << "," << D.dic[i].second
				<< ")";
	sal << "]";
	return sal;
}

#endif /* DICCIONARIOV1_HXX_ */

/*
 * diccionarioV2.hxx
 *
 * JESUS ANGEL GONZALEZ NOVEZ
 * 76440070F
 */

#ifndef DICCIONARIOV2_HXX_
#define DICCIONARIOV2_HXX_

#include <assert.h>

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2>::diccionario() {
	diccionario::entrada nula("", -1);
	dic.push_back(nula);
	pos_max = 0;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2>::diccionario(const entrada &nula) {
	dic.push_back(nula);
	pos_max = 0;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2>::diccionario(const diccionario<T1, T2> &d) {
	dic = d.dic;
	pos_max = d.pos_max;
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
const typename diccionario<T1, T2>::entrada & diccionario<T1, T2>::null() const {
	return dic[0];
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
const typename diccionario<T1, T2>::entrada & diccionario<T1, T2>::find(const T1 & s) const {
	int inf = 1;
	int sup = dic.size() - 1;
	int centro;

	while (inf <= sup) {
		centro = (sup + inf) / 2;
		if (dic[centro].first == s)
			return dic[centro];
		else if (s < dic[centro].first) {
			sup = centro - 1;
		} else {
			inf = centro + 1;
		}
	}
	return dic[0];  //Entrada nula
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
T2 & diccionario<T1, T2>::operator[](const T1 & s) {

	//Paso1 busqueda de s
	int inf = 1, sup = dic.size() - 1;
	int centro;
	bool enc = false;
	while (inf <= sup && !enc) {
		centro = (sup + inf) / 2;
		if (dic[centro].first == s)
			enc = true;
		else if (s < dic[centro].first) {
			sup = centro - 1;
		} else {
			inf = centro + 1;
		}
	}
	//Paso2 si esta devuelve la ref y si no lo inserta.
	if (enc)
		return dic[centro].second;
	else { //No esta:
		diccionario::entrada aux(s, 0);
		dic.push_back(aux); //Insertamos al final, incrementamos el size del vector
		int pos = dic.size() - 1;
		while ((pos > 1) && (dic[pos - 1] > aux)) { //Desplazamos hasta su posicon
			dic[pos] = dic[pos - 1];
			pos--;
		}
		dic[pos] = aux;
		return dic[pos].second;
	}
}

/**
 @todo implementa esta función
 */
template<typename T1, typename T2>
const T2 & diccionario<T1, T2>::operator[](const T1 & s) const {
	int inf = 1, sup = dic.size() - 1;
	int centro;
	bool enc = false;

	while (inf <= sup && !enc) {
		centro = (sup + inf) / 2;
		if (dic[centro].first == s)
			enc = true;
		else if (s < dic[centro].first) {
			sup = centro - 1;
		} else {
			inf = centro + 1;
		}
	}
	assert(enc == true);
	return dic[centro].second;
}

/**
 * @todo implementa esta función
 */
template<typename T1, typename T2>
diccionario<T1, T2> &diccionario<T1, T2>::operator=(const diccionario<T1, T2> &org) {
	if (this != &org) {
		dic = org.dic;
		pos_max = org.pos_max;
	}
	return *this;
}

/**
 * @brief numero de entradas en el diccionario
 * @post  No se modifica el diccionario.
 */
template<typename T1, typename T2>
typename diccionario<T1, T2>::size_type diccionario<T1, T2>::size() const {
	return dic.size() - 1;

}

/**
 * @todo implementa esta función
 */
template<typename T1, typename T2>
bool diccionario<T1, T2>::empty() const {
	return (dic.size() == 1);

}

/**
 * @todo implementa esta función
 */
template<typename T1, typename T2>
const T1 & diccionario<T1, T2>::max_element() const {
	size_type p_max = 0;
	T2 cuantos = dic[p_max].second;
	for (unsigned int i = 1; i < dic.size(); i++)
		if (dic[i].second > cuantos) {
			cuantos = dic[i].second;
			p_max = i;
		}
	return dic[p_max].first;
}

/**
 * @todo implementa esta función
 */
template<typename T1, typename T2>
bool diccionario<T1, T2>::cheq_rep() const {
	// Chequearemos puntos i) y iii), pues el 2 no se puede chequear

	assert(size() == dic.size() - 1);
	for (int i = 1; i < dic.size(); i++) {
		assert(dic[i].second >= 0); //Valores >= que 0
		assert(dic[i].first != dic[0].first); // valores distintos del nulo
		if (i > 2)
			assert(dic[i].first != dic[i - 1].first); // Ordenados
	}
	return true;
}

/**
 * @todo implementa esta función
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

#endif /* DICCIONARIOV2_HXX_ */

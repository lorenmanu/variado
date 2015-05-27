/* 
 * File:   deque.hxx
 * Author: JESUS ANGEL GONZALEZ NOVEZ
 *
 */
#ifndef DEQUE_HXX
#define	DEQUE_HXX
#include "deque.h"

template<typename T>
deque<T>::deque() {
    inicio = 0;
    final = 0;
    tama = 0;
}

template<typename T>
deque<T>::deque(typename deque<T>::size_type n, const T & t) {
    inicio = 0;
    final = (n % TAM_BLQ);
    vector<T> vector_ini(TAM_BLQ, t);
    int n_vectores = n / TAM_BLQ;
    for (int i = 0; i < n_vectores; i++) {
        L_dq.push_back(vector_ini);
    }
    if ((n % TAM_BLQ) != 0) {

        n_vectores++;
        L_dq.push_back(vector_ini);
    }
    tama = n_vectores * 10;
}

template<typename T>
deque<T>::deque(const deque<T> & org) {
    L_dq = org.L_dq;
    inicio = org.inicio;
    final = org.final;
    tama = org.tama;

}

template<typename T>
deque<T>::~deque() {

}

template<typename T>
typename deque<T>::size_type deque<T>::size() const {
    if (L_dq.empty()) {
        return 0;
    }else{
        return (tama - inicio - TAM_BLQ + final + 1);
    }
}

template<typename T>
bool deque<T>::empty() const {
    return (deque<T>::size() == 0);
}

template<typename T>
T & deque<T>::operator[](const typename deque<T>::size_type pos) {
    typename deque<T>::iterator i = begin();
    for (int j = 0; j < pos; j++)
        i++;
    return *i;
}

template<typename T>
const T & deque<T>::operator[](const typename deque<T>::size_type pos) const {
    typename deque<T>::iterator i = begin();
    for (int j = 0; j < pos; j++)
        i++;
    return *i;
}

template<typename T>
const T & deque<T>::at(typename deque<T>::size_type pos) const {
    if ((pos < size()) && (size() >= 1)) {
        typename deque<T>::iterator i = begin();
        for (int j = 0; j < pos; j++)
            i++;
        return *i;
    }
}

template<typename T>
T & deque<T>::at(typename deque<T>::size_type pos) {
    if ((pos < size()) && (size() >= 1)) {
        typename deque<T>::iterator i = begin();
        for (int j = 0; j < pos; j++) {
            i++;
        }
        return *i;
    }
}

template<typename T>
void deque<T>::push_back(const T & t) {
    if (L_dq.size() == 0) {
        vector<T> v(10, T());
        v[0] = t;
        tama += 10;
        final = 0;
        L_dq.push_back(v);
    } else {
        typename list<vector<T> >::iterator i = L_dq.end();
        i--;
        vector<T> v = *i;
        if (final == 9) {
            vector<T> v2(10, T());
            v2[0] = t;
            tama += 10;
            final = 0;
            L_dq.push_back(v2);
        } else {
            v[final + 1] = t;
            final++;
            L_dq.pop_back();
            L_dq.push_back(v);
        }
    }
}

template<typename T>
void deque<T>::push_front(const T & t) {
    if (inicio == 0) {
        vector<T> v(10, T());
        v[TAM_BLQ - 1] = t;
        inicio = 9;
        tama += 10;
        L_dq.push_front(v);
    } else {
        typename list<vector<T> >::iterator i = L_dq.begin();
        vector<T> v = *i;
        v[inicio - 1] = t;
        L_dq.pop_front();
        L_dq.push_front(v);
        inicio--;
    }
}

template<typename T>
void deque<T>::pop_front() {
    if (inicio == 9) {
        inicio = 0;
        L_dq.pop_front();
        tama -= 10;
    } else {
        inicio++;
    }
}

template<typename T>
void deque<T>::pop_back() {
    if (final == 0) {
        final = 9;
        L_dq.pop_back();
        tama -= 10;
    }else{
        final--;
    }
}

template<typename T>
void deque<T>::clear() {
    L_dq.clear();
    tama = 0;
    inicio = 0;
    final = 0;
}

template<typename T>
void deque<T>::resize(typename deque<T>::size_type n, const T & t) {
    if (n < size()) {
        while (size() > n) {
            pop_back();
        }
    } else {
        while (size() < n) {
            push_back(t);
        }

    }

}

template<typename T>
deque<T>& deque<T>::operator=(const deque<T> & org) {
    if (this != &org) {
        L_dq = org.L_dq;
        inicio = org.inicio;
        final = org.final;
        tama = org.tama;
    }
    return *this;
}

template<typename T>
deque<T>::iterator::iterator() {

}

template<typename T>
deque<T>::iterator::iterator(const typename deque<T>::iterator & it) {
    it_v = it.it_v;
    it_l = it.it_l;
}

template<typename T>
T & deque<T>::iterator::operator*() {
    return *it_v;
}

template<typename T>
typename deque<T>::iterator & deque<T>::iterator::operator++(int n) {
    vector<T> v = *it_l;
    if (v[TAM_BLQ - 1] != *it_v)
        it_v++;
    else {
        it_l++;
        it_v = (*it_l).begin();
    }
    return *this;
}

template<typename T>
typename deque<T>::iterator & deque<T>::iterator::operator--(int n) {
    it_v -= 1;
    return *this;
}

template<typename T>
typename deque<T>::iterator & deque<T>::iterator::operator=(const deque<T>::iterator & it) {
    it_v = it.it_v;
    it_l = it.it_l;
    return *this;
}

template<typename T>
bool deque<T>::iterator::operator==(const deque<T>::iterator & it) const {
    if (it_l == it.it_l) {
        if (it_v == it.it_v) {
            return true;
        }
    } else {
        return false;
    }
}

template<typename T>
bool deque<T>::iterator::operator!=(const deque<T>::iterator & it) const {
    if (it_v != it.it_v) {
        return true;
    } else {
        if (it_l != it.it_l) {
            return true;
        } else {
            return false;
        }
    }
}

template<typename T>
deque<T>::const_iterator::const_iterator() {


}

template<typename T>
deque<T>::const_iterator::const_iterator(const deque<T>::const_iterator & it) {
    it_v = it.it_v;
    it_l = it.it_l;
}

template<typename T>
const T & deque<T>::const_iterator::operator*() {
    return *it_v;
}

template<typename T>
typename deque<T>::const_iterator & deque<T>::const_iterator::operator++() {
    vector<T> v = *it_l;
    if (v[TAM_BLQ - 1] != *it_v)
        it_v++;
    else {
        it_l++;
        it_v = (*it_l).begin();
    }
    return *this;
}

template<typename T>
typename deque<T>::const_iterator & deque<T>::const_iterator::operator--() {
    it_v -= 1;
    return *this;
}

template<typename T>
typename deque<T>::const_iterator & deque<T>::const_iterator::operator=(const typename deque<T>::const_iterator & it) {
    it_v = it.it_v;
    it_l = it.it_l;
    return *this;
}

template<typename T>
bool deque<T>::const_iterator::operator==(const typename deque<T>::const_iterator & it) const {
    if (it_l == it.it_l) {
        if (it_v == it.it_v) {
            return true;
        }
    } else {
        return false;
    }
}

template<typename T>
bool deque<T>::const_iterator::operator!=(const typename deque<T>::const_iterator & it) const {
    if (it_v != it.it_v) {
        return true;
    } else {
        if (it_l != it.it_l) {
            return true;
        } else {
            return false;
        }
    }
}

template<typename T>
typename deque<T>::iterator deque<T>::begin() {
    deque<T>::iterator it;
    typename list<vector<T> >::iterator i = L_dq.begin();
    vector<T> v = *i;
    it.it_l = i;
    it.it_v = (*it.it_l).begin();
    if (inicio != 0) {
        for (int k = 0; k < inicio; k++)
            it.it_v++;
    }
    return it;
}

template<typename T>
typename deque<T>::iterator deque<T>::end() {
    typename list<vector<T> >::iterator i = L_dq.end();
    i--;
    vector<T> v = *i;
    deque<T>::iterator it;
    it.it_l = i;
    it.it_v = (*it.it_l).begin();
    for (int j = 0; j <= final; j++) {
        it.it_v++;
    }
    return it;
}

template<typename T>
typename deque<T>::const_iterator deque<T>::begin() const {
    deque<T>::const_iterator it;
    typename list<vector<T> >::iterator i = L_dq.begin();
    vector<T> v = *i;
    it.it_l = i;
    it.it_v = (*it.it_l).begin();
    if (inicio != 0) {
        for (int k = 0; k < inicio; k++)
            it.it_v++;
    }
    return it;
}

template<typename T>
typename deque<T>::const_iterator deque<T>::end() const {
    typename list<vector<T> >::iterator i = L_dq.end();
    i--;
    vector<T> v = *i;
    deque<T>::const_iterator it;
    it.it_l = i;
    it.it_v = (*it.it_l).begin();
    for (int j = 0; j <= final; j++) {
        it.it_v++;
    }
    return it;
}

template<typename T>
typename deque<T>::iterator deque<T>::insert(typename deque<T>::iterator & pos, const T & t) {
    deque<T> aux;
    typename deque<T>::iterator j = begin();
    typename deque<T>::iterator m = begin();
    int posi = 0;
    while (m != pos) {
        m++;
        posi++;
    }
    for (int i = 0; i < posi; i++) {
        aux.push_back(*j);
        j++;
    }
    aux.push_back(t);
    for (int k = posi; k < size(); k++) {
        aux.push_back(*j);
        j++;
    }
    swap(aux);
}

template<typename T>
typename deque<T>::iterator deque<T>::erase(typename deque<T>::iterator & pos) {
    deque<T> aux;
    typename deque<T>::iterator j = begin();
    typename deque<T>::iterator m = begin();
    int posi = 0;
    while (m != pos) {
        m++;
        posi++;
    }
    posi++;
    for (int i = 0; i < posi; i++) {
        aux.push_back(*j);
        j++;
    }
    aux.pop_back();
    for (int k = posi; k < size(); k++) {
        aux.push_back(*j);
        j++;
    }
    swap(aux);
}

template<typename T>
void deque<T>::swap(deque<T> & otro) {
    deque<T> deque_org = otro;
    otro.L_dq = this->L_dq;
    otro.final = this->final;
    otro.inicio = this->inicio;
    otro.tama = this->tama;
    this->L_dq = deque_org.L_dq;
    this->final = deque_org.final;
    this->inicio = deque_org.inicio;
    this->tama = deque_org.tama;
}

template<typename T>
int deque<T>::getInicio() {
    return inicio;
}

template<typename T>
int deque<T>::getFinal() {
    return final;
}

#endif	/* DEQUE_HXX */


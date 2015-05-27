/* 
 * diccionario.h
 * 
 * Copyright  (C) Juan F. Huete
 * 
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 * 
 *
===================================================================================
Funcion de Abstraccion:
AF: Rep => Abs
   
  dado D=(vector<entrada>  dic, int mayor) ==> Diccionario Dic;
  
Un objeto abstracto, Dic, representando una colección de pares (string,int) se instancia en la clase diccionario como un vector de entradas, definidas como  diccionario::entrada. Dada una entrada, x, en D,  x.first representa a una palabra válida (clave) y x.second representa el número de veces que ocurre x (definición). 

D.dic[D.mayor] hace referencia a la entrada más frecuente en el diccionario.
=====================================================================================
Invariante de la Representación:



i) Dic.size() == D.dic.size();

ii) Para todo i, 0 <= i < D.dic.size() se cumple
	D.dic[D.mayor] >= D.dic[i].second;
	D.dic[i].second > 1;
	D.dic[i].first != "";
	D.dic[i].fisrt != D.dic[j].first, para todo j!=i.
=====================================================================================
*/
#include <assert.h>


/**
 @todo implementa esta función
*/
diccionario::diccionario(){
	entrada e;	
	e = make_pair("",-1);
	diccionario::dic.push_back(e);
}
/**
 @todo implementa esta función
*/
diccionario::diccionario( const entrada & nula ){ 
	diccionario::dic.push_back(nula);
	
}
/**
 @todo implementa esta función
*/
diccionario::diccionario (const diccionario & d){
	for(size_type i=0; i<d.dic.size(); i++)
		diccionario::dic[0] = d.dic[0];
}


const diccionario::entrada & diccionario::null() const {
	bool encontrada = false;
	size_type i;
	for(size_type i=0; i<diccionario::size() && !encontrada; i++)
		if(diccionario::dic[i].second == -1)
			encontrada = true;
	return diccionario::dic[i];
}

/**
 @todo implementa esta función
*/
const diccionario::entrada & diccionario::find( const string & s) const{
	bool esta=false;
	size_type i;
	for(i=0; i<diccionario::dic.size()&&!esta; i++)
		if(diccionario::dic[i].first == s)
			esta = true;
	if(esta)
		return diccionario::dic[i];
	else
		return diccionario::dic[diccionario::dic.size()-1];
}

/**
 @todo implementa esta función
*/
int & diccionario::operator[](const string & s) {

}
	

/**
 @todo implementa esta función
*/
const int & diccionario::operator[](const string & s) const{
	
}

/**
 @todo implementa esta función
*/
diccionario & diccionario::operator=( const diccionario & org){
	diccionario::dic.clear();
	diccionario::dic = org.dic;
}

	/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/

diccionario::size_type diccionario::size() const {
	return diccionario::dic.size();
}

/**
 @todo implementa esta función
*/
bool diccionario::empty() const{
	if(diccionario::dic.size() == 0)
		return true;
	else 
		return false;
}

/**
 @todo implementa esta función
*/
const string & diccionario::max_element( ) const{
	int max=0,pos;
	for(unsigned int i=0; i<diccionario::size(); i++)
		if(diccionario::dic[i].second >= max){
			max = diccionario::dic[i].second;
			pos = i;
		}
	return diccionario::[pos].first; 
}
	 
/**
 @todo implementa esta función
*/
bool diccionario::cheq_rep( ) const {
	if(diccionario::size() == diccionario::dic.size())
		return true;
	else
		return false;
}
  
/**
 @todo implementa esta función
*/
ostream &  operator<<( ostream & sal, const diccionario & D){
	for(unsigned int i=0; i<D.size(); i++)
		return (sal << D.dic[i].first << " " << D.dic[i].second << endl);
}



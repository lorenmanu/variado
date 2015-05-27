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
   
  dado Rep=(vector<entrada>  dic, int mayor) ==> Diccionario Dic;
  
Un objeto abstracto, Dic, representando una colección de pares (string,int) se instancia en la
clase diccionario como un vector de entradas, definidas como  diccionario::entrada. 
Dada una entrada, x, en Rep,  x.first representa a una palabra válida (clave) y x.second 
representa el número de veces que ocurre x (definición). 

Un diccionario debe tener definido el valor de la entrada nula, Dic.null(), que se almacena 
en la primera posicion del vector, esto es,  Rep.dic[0]== Dic.null();


=====================================================================================
Invariante de la Representación:

Dic es el objeto abstracto diccionario, Rep seria su representacion

i) Dic.size() == Rep.dic.size()-1;
ii) Rep.dic[0]== Dic.null();
iii) Para todo i, 1 <= i <= D.dic.size() se cumple
	Rep.dic[i].second >= 0;
	Rep.dic[i].first != Dic.null().first;
	Rep.dic[i].fisrt != Rep.dic[j].first, para todo j!=i.


=====================================================================================
*/
#include <assert.h>


/**
 @todo Chequear esta función
*/
diccionario::diccionario(){ 
  diccionario::entrada nula("",-1);
  dic.push_back(nula);
  pos_max =0;
}
/**
 @todo implementa esta función
*/
diccionario::diccionario( const entrada & nula ){ 
  dic.push_back(nula);
  pos_max =0;

}
/**
 @todo implementa esta función
*/
diccionario::diccionario (const diccionario & d){
  dic = d.dic;
  pos_max = d.pos_max;
}


const diccionario::entrada & diccionario::null() const {
  return dic[0];
}

/**
 @todo implementa esta función
*/
const diccionario::entrada & diccionario::find( const string & s) const{
	  for (int i=1; i< dic.size(); i++) 
	     if (dic[i].first == s) return dic[i];
	  return  null();
}

/**
 @todo implementa esta función
*/
int & diccionario::operator[](const string & s) {
  bool encontrado = false;
  int i;
  for (i=1;i<dic.size() && ! encontrado ;  ){
    if (dic[i].first == s)
      encontrado = true;
    else i++;
  }
  if (!encontrado) {
       dic.push_back(entrada(s,0));
       i = dic.size()-1;
  }
  return dic[i].second;
}
	

/**
 @todo implementa esta función
*/
const int & diccionario::operator[](const string & s) const{
 bool encontrado = false;
 int i;
  for (i=0;i<dic.size() && ! encontrado ;  ){
    if (dic[i].first == s)
      encontrado = true;
   else i++;
   }
  assert (encontrado == true);
  return dic[i].second;
}

/**
 @todo implementa esta función
*/
diccionario & diccionario::operator=( const diccionario & org){
if (this!=&org){
  dic = org.dic;
  pos_max =org.pos_max;
}
return *this;
}

/**@todo implementa esta funcion.
*/

diccionario::size_type diccionario::size() const {
 return dic.size()-1;
}

/**
 @todo implementa esta función
*/
bool diccionario::empty() const{
  return (dic.size()==1);
}

/**
 @todo implementa esta función
*/
const string & diccionario::max_element( ) const {
size_type p_max = 0;
int cuantos = dic[p_max].second;
  for (int i=1; i <  dic.size();i++)
    if (dic[i].second > cuantos) {
      cuantos =dic[i].second;
      p_max = i;
    }
    return dic[p_max].first;
}
	 
/**
 @todo implementa esta función
*/
bool diccionario::cheq_rep( ) const {
  // Chequearemos puntos i) y iii), pues el 2 no se puede chequear

  assert( size() == dic.size()-1);
  for (int i=1; i<dic.size(); i++) {
    assert(dic[i].second >=0); //Valores >= que 0
    for (int j=0; j<dic.size(); j++)
        if (j!=i) 
	   assert(dic[i].first != dic[j].first); // No se repite clave, incluido la nula
  }
  return true;
}
  
/**
 @todo implementa esta función
*/
ostream &  operator << ( ostream & sal, const diccionario & D){
   sal << "size : "<< D.size() <<" => [";
   for (int i=0; i< D.dic.size(); i++)
    sal << "("<< i << ":: " <<D.dic[i].first << "," << D.dic[i].second<<")";
   sal<<"]";
  return sal;
}



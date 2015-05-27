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
   
  dado Rep=(vector<entrada>  dic, pos_max ) ==> Diccionario Dic;
  
Un objeto abstracto, Dic, representando una colección de pares (string,int) se 
instancia en la clase diccionario como un vector de entradas, definidas como 
diccionario::entrada. Dada una entrada, x, en Rep,  x.first representa a una palabra válida (clave) 
y x.second representa el número de veces que ocurre x (definición). 


Un diccionario debe tener definido el valor de la entrada nula, Dic.null(), que se almacena 
en la primera posicion del vector, esto es,  Rep.dic[0]== Dic.null();
=====================================================================================
Invariante de la Representación:


Dic es el objeto abstracto diccionario, Rep seria su representacion

i) Dic.size() == Rep.dic.size()-1;
ii) Rep.dic[0]== Dic.null();
iii) Para todo i, 1 <= i < Rep.dic.size() se cumple
	Rep.dic[i].second >= 0;
	Rep.dic[i].first != Dic.null().first;
	Rep.dic[i].fisrt < Rep.dic[i+1].first,
=====================================================================================
*/
#include <assert.h>


/**
 @todo implementa esta función
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
   int inf=1; int sup = dic.size()-1;
   int centro;

   while(inf<=sup){
     centro=(sup+inf)/2;
     if(dic[centro].first==s) return dic[centro];
     else if(s < dic[centro].first ){
        sup=centro-1;
     }
     else {
       inf=centro+1;
     }
   }
   return dic[0];  //Entrada nula
}

/**
 @todo implementa esta función
*/
int & diccionario::operator[](const string & s) {
  
  //Paso1 busqueda de s
   int inf=1,  sup = dic.size()-1;
   int centro;
   bool enc=false;
   while(inf<=sup && ! enc){
     centro=(sup+inf)/2;
     if(dic[centro].first==s)
       enc = true;
     else if(s < dic[centro].first ){
        sup=centro-1;
     }
     else {
       inf=centro+1;
     }
   }
   //Paso2 si esta devuelve la ref y si no lo inserta.
   if (enc) return dic[centro].second;
   else { //No esta:
      diccionario::entrada aux(s,0);
      dic.push_back(aux); //Insertamos al final, incrementamos el size del vector
      int pos  = dic.size()-1;
      while ( (pos >1)  && (dic[pos-1] > aux)){ //Desplazamos hasta su posicon
	dic[pos]=dic[pos-1];
	pos--;
      }
      dic[pos]=aux;
      return dic[pos].second;
   }
}
	

/**
 @todo implementa esta función
*/
const int & diccionario::operator[](const string & s) const{
 int inf=1,  sup = dic.size()-1;
   int centro;
   bool enc=false;

   while(inf<=sup && ! enc){
     centro=(sup+inf)/2;
     if(dic[centro].first==s)
       enc = true;
     else if(s < dic[centro].first ){
        sup=centro-1;
     }
     else {
       inf=centro+1;
     }
   }
   assert(enc==true);
   return dic[centro].second;
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

	/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
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
    assert(dic[i].first != dic[0].first); // valores distintos del nulo
    if (i>2)
      assert(dic[i].first != dic[i-1].first); // Ordenados
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



#include "SoED.h"


using namespace std;


SoED::SoED(){
  SoED::entrada  aux;
  tree<entrada>::node n;
  pair<tree<entrada>::node,tree<entrada>::node> par;
  
 aux.nombre ="/";
 aux.propietario="root";
 aux.tama=0;
 
 arbol=tree<SoED::entrada >(aux);
 
  n = arbol.root();
  par.first = n;
  par.second = n;
  users["root"]=par;
  
 
  aux.nombre = "home/";
  arbol.insert_left(n,aux);
  
  
}



 
      
  
void SoED::reading_SoED( ) {
  // Funciona correctamente si se ejecuta despues del constructor por defecto
  tree<entrada>::node n, h;
  queue< tree<SoED::entrada >::node > Q;
   
  pair<tree<entrada>::node,tree<entrada>::node> par;
  SoED::entrada  aux;
 
  n = arbol.root().left();
  aux.nombre ="def/";
  aux.propietario="def";
  aux.tama=0;
 
  n = arbol.insert_left(n,aux);
  par.first = n;
  par.second = n;
  users["def"]=par;
  Q.push(n);
  while (!Q.empty() ){
    n = Q.front(); 
    Q.pop();
    cout << "Hijo Izq de " << (*n).nombre << " ( * para terminar )"<< endl;
    cin >> aux.nombre;
    if (aux.nombre != "*") { 
      h= arbol.insert_left(n,aux);
      Q.push(h);
      cout << "Hermano Dhc de " << (*h).nombre<< "( * para terminar )"<< endl;
      cin >> aux.nombre;
      while (aux.nombre != "*") {
	h= arbol.insert_right_sibling(h,aux);
	Q.push(h);
	cout << "Hermano Dhc de " << (*h).nombre<< " ( * para terminar )"<< endl;
        cin >> aux.nombre;
      } 
    }
    
  }
  
  cout << "El arbol en preorden es ...."<< endl;
  tree<SoED::entrada>::preorderiterator it;
  for (it = arbol.beginPreorder(); it!= arbol.endPreorder(); ++it)
    cout << (*it).nombre << " " << (*it).propietario<< "::";
  cout << endl;
  
}
    
 void SoED::cd(const SoED::userID & user){
   users[user].second = users[user].second;
 }
      
 SoED::path SoED::pwd(const SoED::userID & user) const {
  
   tree<entrada>::const_node aux;
   map<string, pair< tree<entrada>::node, tree<entrada>::node >  >::const_iterator it;
   
   SoED::path sal;
   
   it = users.find(user);
   if (it!=users.end())
   { aux = (*it).second.second;
     while (!aux.null()) {
     sal.insert(0,(*aux).nombre);
     aux = aux.parent();
     }
   }
 return sal;
   
 }
 
 
 

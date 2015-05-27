#include <iostream>
#include "diccionario.h"

using namespace std;

void funcion( const diccionario & d, const string &cad){
  cout << d << endl;
  cout << cad << " vale " << d[cad]<< endl; //Si "hola" no esta no puede insertarla y se aborta;
}

int main(){
diccionario d1;

diccionario::entrada ent;

ent.first = "zzzz";
ent.second = -1;

diccionario d2(ent);

d1["hola"]=4;
cout << d1<< endl;
d1["adios"]= 3;
cout << d1<< endl;

d1["adios"]++;
cout << d1<< endl;

d1["otro"]++;
cout << d1<< endl;

d1["valor"];
cout << d1<< endl;

d1["zapato"]=34;
cout << d1<< endl;

d1["abc"]=2;
cout << d1<< endl;


if (d1.empty()) cout << "d1 empty" << endl;
if (d2.empty()) cout << "d2 empty" << endl;

ent = d1.find("hola");

if (ent == d1.null()) cout << "Hola no esta en d1" <<endl;
if (ent == d2.null()) cout << "Hola no esta en d2" <<endl;

cout << "max d1 " << d1.max_element()<< endl;

cout << "max d2 "<< d2.max_element()<< endl;
funcion (d1,"hola"); 

d2 = d1;

if (d1.empty()) cout << "d1 empty" << endl;
if (d2.empty()) cout << "d2 empty" << endl;

ent = d1.find("hola");
if (ent == d1.null()) cout << "Hola no esta en d1" <<endl;
if (ent == d2.null()) cout << "Hola no esta en d2" <<endl;


cout << "max d1 " << d1.max_element()<< endl;

cout << "max d2 "<< d2.max_element()<< endl;

cout << d1<< endl;
cout << d2 << endl;

diccionario d3;
funcion( d3, "hola" ); //Aborta el programa si "Hola" no esta en el diccionario. 

return 0;
}

/*
 * prueba.cpp
 *
 * JESUS ANGEL GONZALEZ NOVEZ
 * 76440070F
 */
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;

void funcion( const diccionario<string,int> &D, const string &cad){
  cout << D << endl;
  cout << cad << " vale " << D[cad]<< endl; //Si "hola" no esta no puede insertarla y se aborta;
}

int main(){
diccionario<string,int> dicc_S_I;

diccionario<string,int>::entrada ent_S_I;
diccionario<string,string>::entrada ent_S_S;
diccionario<float,string>::entrada ent_F_S;

ent_S_I.first = "nula"; ent_S_I.second = -1;
ent_S_S.first = "nula"; ent_S_S.second = "CERO";
ent_F_S.first = 0.0; ent_F_S.second = "cero.cero";

diccionario<string,string> dicc_S_S(ent_S_S);
diccionario<float,string> dicc_F_S(ent_F_S);

dicc_S_I["hola"]=4; cout << dicc_S_I << endl;
dicc_S_I["adios"]= 3; cout << dicc_S_I<< endl;
dicc_S_I["adios"]++; cout << dicc_S_I<< endl;
dicc_S_I["otro"]++; cout << dicc_S_I<< endl;
dicc_S_I["valor"]; cout << dicc_S_I<< endl;
dicc_S_I["zapato"]=34; cout << dicc_S_I<< endl;
dicc_S_I["abc"]=2; cout << dicc_S_I<< endl;

dicc_F_S[23.5]; cout << dicc_F_S<< endl;
dicc_F_S[65.8]="muchos"; cout << dicc_F_S<< endl;
dicc_F_S[12.7]="mas"; cout << dicc_F_S<< endl;

if (dicc_S_I.empty())
	cout << "dicc_S_I empty" << endl;
else
	cout << "dicc_S_I lleno" << endl;
if (dicc_S_S.empty())
	cout << "dicc_S_S empty" << endl;
else
	cout << "dicc_S_S lleno" << endl;

ent_S_I = dicc_S_I.find("hola");
ent_S_S = dicc_S_S.find("hola");
ent_F_S = dicc_F_S.find(3.2);

if (ent_F_S == dicc_F_S.null()) cout << "3.2 no esta en dicc_F_S" <<endl;
if (ent_S_S == dicc_S_S.null()) cout << "Hola no esta en dicc_S_S" <<endl;

cout << "max dicc_F_S " << dicc_F_S.max_element()<< endl;
cout << "max dicc_S_I "<< dicc_S_I.max_element()<< endl;
//funcion (d1,"hola");

diccionario<string,int> copia;
copia = dicc_S_I;

if (dicc_S_I.empty())
	cout << "dicc_S_I empty" << endl;
else
	cout << "dicc_S_I lleno" << endl;
if (copia.empty())
	cout << "copia empty" << endl;
else
	cout << "copia lleno" << endl;

ent_S_I = dicc_S_I.find("hola");
if (ent_S_I == dicc_S_I.null()) cout << "Hola no esta en dicc_S_I" <<endl;
if (ent_S_I == copia.null()) cout << "Hola no esta en copia" <<endl;


cout << "max dicc_S_I " << dicc_S_I.max_element()<< endl;

cout << "max copia "<< copia.max_element()<< endl;

cout << dicc_S_I<< endl;
cout << copia << endl;

diccionario<string,int> d3;
funcion(d3, "hola"); //Aborta el programa si "Hola" no esta en el diccionario.

return 0;
}

#include "SoED.h"
#include <iostream>
#include "tree.h"
using namespace std;

int main(){

  
  SoED A;
  
  // Llamar a reading_SoED solo funciona correctamente si se ejecuta despues del constructor por defecto
  A.reading_SoED();
  
  
 cout <<  A.pwd("root")<< endl;
  cout << A.pwd("def")<< endl;
  
return 0;
} 
 

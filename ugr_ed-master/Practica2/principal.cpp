#include "corrector.h"
#include <iostream>

using namespace std;
 
int main()
{
    corrector miCorrector;
 
  
    miCorrector.load("quijote.txt");
    string palabra;
    while (palabra != "quit")
    {
        cout << "Escribe una palabra\n";
        cin >> palabra;
 
        string sugerencia(miCorrector.correct(palabra));
 
        if (sugerencia != "")
            cout << "Palabra sugerida: " << sugerencia << "?\n\n\n";
        else
            cout << "No hay sugerencias disponibles\n\n\n";
    }
 
    return 0;
}

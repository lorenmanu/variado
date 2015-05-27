/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include "vertex.h"
#include <vector>
#include <GL/glut.h>
#include "visualtype.h" //For enum
#include "Textura.h"
#include "Objeto3D.h"

using namespace std;


#ifndef _LATA_H_
#define _LATA_H_

class Lata {
private:
    //OpenGL puede gestionar mas de
    //una textura a la vez. Para diferenciarlas
    //usa un valor entero unico para cada una de ellas
    bool isLight;
    Objeto3D * cuerpo_lata;
    Objeto3D * tapa_inf;
    Objeto3D * tapa_sup;
public:
    Lata();
    ~Lata();
    void draw(visual_t visualization);

};


#endif

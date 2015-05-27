/* 
 * File:   figura_revolucion.h
 * Author: jesus
 *
 * Created on 24 de octubre de 2014, 16:55
 */

#ifndef TORRE_H
#define	TORRE_H
#include <cmath>
#include <iostream>
#include "objeto3D.h"
#include "figura_revolucion.h"
#define PI 3.141592653589793238463
class torre : public figura_revolucion{
public:
    torre();
    torre(char * ruta);
    torre(std::vector<std::vector<GLfloat> > vert);
private:
    figura_revolucion base,cima;
};

#endif	/* TORRE_H */


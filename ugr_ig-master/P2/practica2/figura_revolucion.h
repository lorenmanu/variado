/* 
 * File:   figura_revolucion.h
 * Author: jesus
 *
 * Created on 24 de octubre de 2014, 16:55
 */

#ifndef FIGURA_REVOLUCION_H
#define	FIGURA_REVOLUCION_H
#include <cmath>
#include <iostream>
#include "objeto3D.h"

#define PI 3.141592653589793238463
class figura_revolucion : public objeto3D{
public:
    figura_revolucion();
    figura_revolucion(char * ruta,bool tapa_arriba,bool tapa_abajo,bool inversa);
    void toMatrix(std::vector<float> u);
    void rotar(int rot);
    void calcularNormalesCaras();
    void calcularNormalesVertices();
    void invertir(std::vector<float> &u);

private:
   GLfloat y_arriba,y_abajo;
   bool t_arriba,t_abajo;
};

#endif	/* FIGURA_REVOLUCION_H */


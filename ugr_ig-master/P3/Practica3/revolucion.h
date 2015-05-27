/* 
 * File:   figura_revolucion.h
 * Author: jesus
 *
 * Created on 24 de octubre de 2014, 16:55
 */

#ifndef REVOLUCION_H
#define	REVOLUCION_H
#include <cmath>
#include <iostream>
#include "objeto3D.h"

#define PI 3.141592653589793238463
class revolucion : public objeto3D{
public:
    revolucion();
    void toMatrix(std::vector<float> u);
    void toMatrixC(std::vector<int> ver);
    void rotar(int rot);
    void calcularNormalesCaras();
    void calcularNormalesVertices();
    void invertir(std::vector<float> &u);


protected:
   GLfloat y_arriba,y_abajo;
   bool t_arriba,t_abajo;
};

#endif	/* FIGURA_REVOLUCION_H */


/* 
 * File:   figura_revolucion.cpp
 * Author: jesus
 * 
 * Created on 24 de octubre de 2014, 16:56
 */

#include "cono.h"
#include <iostream>
#include <stdlib.h>

cono::cono() {

}

cono::cono(float altura,float radio, bool tapa) {
    /*Comprobamos si se desean tapas superior e inferior*/
    t_arriba = false;
    t_abajo = tapa;
    std::vector<float> u;
    u.push_back(radio);u.push_back(0);u.push_back(0);
    u.push_back(0);u.push_back(altura);u.push_back(0);
    
    /*Pasamos a matriz para poder trabajar mejor*/
    toMatrix(u);
    /*Buscamos las "y" de arriba y de abajo*/
    y_abajo = vertices[0][1];
    y_arriba = vertices[vertices.size() - 1][1];
    /*Realizamos las rotaciones deseadas*/
    rotar(20);
    /*Calculamos las normales de las caras*/
    calcularNormalesCaras();
    /*Pasamos a puntero de GLfloat las matrices anteriores*/
    toVector();

    /*Calculamos las normales de los vértices*/
    calcularNormalesVertices();

}

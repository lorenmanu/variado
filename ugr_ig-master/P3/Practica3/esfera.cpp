/* 
 * File:   figura_revolucion.cpp
 * Author: jesus
 * 
 * Created on 24 de octubre de 2014, 16:56
 */

#include "esfera.h"
#include <iostream>
#include <stdlib.h>

esfera::esfera() {

}

esfera::esfera(float radio) {
    /*Comprobamos si se desean tapas superior e inferior*/
    t_arriba = false;
    t_abajo = false;
    std::vector<float> vec;
    float latitudeBands = 20;
    float longitudeBands = 20;
    for(int latNumber = 0; latNumber <= latitudeBands; latNumber++) {
        float theta = latNumber * PI / latitudeBands;
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);
        for (float longNumber = 0; longNumber <= longitudeBands; longNumber++) {
            float phi = longNumber * 2 * PI / longitudeBands;
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);
            float x = cosPhi * sinTheta;
            float y = cosTheta;
            float z = sinPhi * sinTheta;
            float u = 1 - (longNumber / longitudeBands);
            float v = 1 - (latNumber / latitudeBands);

            vec.push_back(radio * x);
            vec.push_back(radio * y);
            vec.push_back(radio * z);
        }
    }
    std::vector<float> aux;
    for(int i=vec.size()-1; i>=0; i--)
        aux.push_back(vec[i]);
    vec = aux;
    /*Pasamos a matriz para poder trabajar mejor*/
    toMatrix(vec);
    std::vector<int> carasaux;
    for (float latNumber = 0; latNumber < latitudeBands; latNumber++) {
      for (float longNumber = 0; longNumber < longitudeBands; longNumber++) {
        int first = (latNumber * (longitudeBands + 1)) + longNumber;
        int second = first + longitudeBands + 1;
        carasaux.push_back(first);
        carasaux.push_back(second);
        carasaux.push_back(first + 1);
        carasaux.push_back(second);
        carasaux.push_back(second + 1);
        carasaux.push_back(first + 1);
      }
    }
    toMatrixC(carasaux);
    /*Realizamos las rotaciones deseadas*/
//    rotar(22);
    /*Calculamos las normales de las caras*/
    calcularNormalesCaras();
    /*Pasamos a puntero de GLfloat las matrices anteriores*/
    toVector();
    /*Calculamos las normales de los vértices*/
    calcularNormalesVertices();
}



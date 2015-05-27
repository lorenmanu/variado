/* 
 * File:   figura_ply.cpp
 * Author: jesus
 * 
 * Created on 21 de octubre de 2014, 23:10
 */

#include "figura_ply.h"

figura_ply::figura_ply(){
    
}
figura_ply::figura_ply(char * ruta) {
    std::vector<float> ver;
    std::vector<int> car;
    ply::read(ruta,ver,car);
    for (int i = 0; i < ver.size(); i += 3) {
        std::vector<GLfloat> v;
        v.push_back((GLfloat) ver[i]);
        v.push_back((GLfloat) ver[i + 1]);
        v.push_back((GLfloat) ver[i + 2]);
        vertices.push_back(v);
        v.clear();
    }
    for (int i = 0; i < car.size(); i += 3) {
        std::vector<GLuint> v;
        v.push_back((GLuint) car[i]);
        v.push_back((GLuint) car[i + 1]);
        v.push_back((GLuint) car[i + 2]);
        caras.push_back(v);
        v.clear();
    }
}


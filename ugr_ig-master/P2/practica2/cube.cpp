/*
 * File: cube.cpp
 * Author: jesus
 *
 * Created on 22 de octubre de 2014, 19:54
 */
#include "cube.h"

cube::cube() {
    GLfloat v[8][3] = {
        {0, 0, 1},
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 1},
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 0},
        {1, 1, 0}};
    GLuint c[12][3] = {
        {0, 1, 2},
        {1, 3, 2},
        {2, 3, 7},
        {2, 7, 6},
        {1, 7, 3},
        {1, 5, 7},
        {6, 7, 4},
        {7, 5, 4},
        {0, 4, 1},
        {1, 4, 5},
        {2, 6, 4},
        {0, 2, 4},};
    std::vector<GLfloat> aux1;
    std::vector<GLuint> aux2;
    for (int i = 0; i < 8; i++) {
        aux1.push_back(v[i][0]);
        aux1.push_back(v[i][1]);
        aux1.push_back(v[i][2]);
        vertices.push_back(aux1);
        aux1.clear();
    }
    for (int i = 0; i < 12; i++) {
        aux2.push_back(c[i][0]);
        aux2.push_back(c[i][1]);
        aux2.push_back(c[i][2]);
        caras.push_back(aux2);
        aux2.clear();
    }
    toVector();
}

cube::cube(float lado) {
    GLfloat v[8][3] = {
        {0, 0, lado},
        {lado, 0, lado},
        {0, lado, lado},
        {lado, lado, lado},
        {0, 0, 0},
        {lado, 0, 0},
        {0, lado, 0},
        {lado, lado, 0}};
    GLuint c[12][3] = {
        {0, 1, 2},
        {1, 3, 2},
        {2, 3, 7},
        {2, 7, 6},
        {1, 7, 3},
        {1, 5, 7},
        {6, 7, 4},
        {7, 5, 4},
        {0, 4, 1},
        {1, 4, 5},
        {2, 6, 4},
        {0, 2, 4},};
    std::vector<GLfloat> aux1;
    std::vector<GLuint> aux2;
    for (int i = 0; i < 8; i++) {
        aux1.push_back(v[i][0]);
        aux1.push_back(v[i][1]);
        aux1.push_back(v[i][2]);
        vertices.push_back(aux1);
        aux1.clear();
    }
    for (int i = 0; i < 12; i++) {
        aux2.push_back(c[i][0]);
        aux2.push_back(c[i][1]);
        aux2.push_back(c[i][2]);
        caras.push_back(aux2);
        aux2.clear();
    }
    toVector();
}

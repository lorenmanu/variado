/* 
 * File:   figura_revolucion.cpp
 * Author: jesus
 * 
 * Created on 24 de octubre de 2014, 16:56
 */

#include "revolucion.h"
#include <iostream>
#include <stdlib.h>

revolucion::revolucion() {

}

void revolucion::rotar(int rot) {
    //Vertices
    int num_filas = vertices.size();
    std::vector<GLfloat> v;
    GLfloat x, y, z;
    std::vector<GLuint> c, c2;

    for (uint i = 0; i < num_filas * rot; i++) {
        /*Generamos los vertices*/
        x = vertices[i][0] * cos((2.0 / rot) * M_PI) +
                vertices[i][2] * sin((2.0 / rot) * M_PI);
        y = vertices[i][1];
        z = -sin((2.0 / rot) * M_PI) * vertices[i][0] +
                vertices[i][2] * cos((2.0 / rot) * M_PI);
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        vertices.push_back(v);
        v.clear();

        /*Generamos las caras*/
        c.clear();
        c2.clear();
        if ((vertices.size() - 1) % num_filas) {
                c.push_back(i);
                c.push_back((vertices.size() - 2));
                c.push_back((vertices.size() - 1));
            if ((vertices.size() - 1) % num_filas != 1) {
                    c2.push_back(i);
                    c2.push_back(i - 1);
                    c2.push_back((vertices.size() - 2));
            }
        } else {
                c.push_back(i + 1);
                c.push_back(i);
                c.push_back((vertices.size() - 1));
        }
        caras.push_back(c);
        if (!c2.empty())
            caras.push_back(c2);

    }



    /***********TAPA SUPERIOR*****************/
    //Punto superior
    v.push_back(0.);
    v.push_back(y_arriba);
    v.push_back(0.);
    vertices.push_back(v);
    if (t_arriba) {
        for (int i = 0; i < rot + 1; i++) {
            //Cara de arriba
            if (i > 0) {
                    c2.clear();
                    c2.push_back(num_filas * (i) - 1);
                    c2.push_back(num_filas * (rot + 1));
                    c2.push_back(num_filas * i - 1 + num_filas);
                    caras.push_back(c2);
                    c2.clear();
                    c2.push_back(num_filas * i - 1 + num_filas);
                    c2.push_back(num_filas * (rot + 1));
                    c2.push_back(num_filas * (i) - 1);
                    caras.push_back(c2);
            }
        }
            c2.clear();
            c2.push_back((rot + 1) * num_filas - 1);
            c2.push_back(num_filas * (rot + 1));
            c2.push_back(num_filas - 1);
            caras.push_back(c2);
    }

    /************TAPA INFERIOR**********************/
    //Punto inferior
    v.clear();
    v.push_back(0.);
    v.push_back(y_abajo);
    v.push_back(0.);
    vertices.push_back(v);
    v.clear();
    if (t_abajo) {
        for (int i = 0; i < rot; i++) {
                c2.clear();
                c2.push_back(num_filas * (rot + 1) + 1);
                c2.push_back(num_filas * i + num_filas);
                c2.push_back(num_filas * i);
                caras.push_back(c2);
        }
            c2.clear();
            c2.push_back(1 + (rot + 1) * num_filas);
            c2.push_back(num_filas * rot);
            c2.push_back(0);
            caras.push_back(c2);
    }

}

void revolucion::toMatrix(std::vector<float> ver) {
    for (int i = 0; i < ver.size(); i += 3) {
        std::vector<GLfloat> v;
        v.push_back((GLfloat) ver[i]);
        v.push_back((GLfloat) ver[i + 1]);
        v.push_back((GLfloat) ver[i + 2]);
        vertices.push_back(v);
        v.clear();
    }
}
void revolucion::toMatrixC(std::vector<int> ver) {
    for (int i = 0; i < ver.size(); i += 3) {
        std::vector<GLuint> v;
        v.push_back((GLuint) ver[i]);
        v.push_back((GLuint) ver[i + 1]);
        v.push_back((GLuint) ver[i + 2]);
        caras.push_back(v);
        v.clear();
    }
}


void revolucion::calcularNormalesCaras() {
    std::vector<GLfloat> A, B, C;
    std::vector<GLfloat> P, Q, N;
    float modulo;
    for (int i = 0; i < caras.size(); i++) {
        A = vertices[caras[i][0]];
        B = vertices[caras[i][1]];
        C = vertices[caras[i][2]];

        /* P = AB */
        P.push_back(B[0] - A[0]);
        P.push_back(B[1] - A[1]);
        P.push_back(B[2] - A[2]);

        /* Q = BC */
        Q.push_back(C[0] - B[0]);
        Q.push_back(C[1] - B[1]);
        Q.push_back(C[2] - B[2]);

        /* N = PxQ */
        N.push_back(P[1] * Q[2] - P[2] * Q[1]);
        N.push_back(P[2] * Q[0] - P[0] * Q[2]);
        N.push_back(P[0] * Q[1] - P[1] * Q[0]);

        modulo = sqrt(pow(N[0], 2) + pow(N[1], 2) + pow(N[2], 2));
        N[0] = fabs(N[0] / modulo);
        N[1] = fabs(N[1] / modulo);
        N[2] = fabs(N[2] / modulo);
        normales.push_back(N);
        A.clear();
        B.clear();
        C.clear();
        P.clear();
        Q.clear();
        N.clear();
    }
}

void revolucion::calcularNormalesVertices() {
    normales_vert = (GLfloat*) malloc(sizeof (GLfloat) * vertices_size);
    GLfloat num_x, num_y, num_z;
    GLfloat den;
    int cont = 0;
    for (int i = 0; i < vertices_size; i += 3) {
        num_x = 0;
        num_y = 0;
        num_z = 0;
        den = 0;
        for (int j = 0; j < caras_size; j += 3) {
            /* Comprobamos si alguno de los vertices de la cara j-ésima se 
               corresponde con nuestro vértice. */
            if (vertices2[i] == vertices2[caras2[j]*3] &&
                    vertices2[i + 1] == vertices2[caras2[j]*3 + 1] &&
                    vertices2[i + 2] == vertices2[caras2[j]*3 + 2] ||
                    vertices2[i] == vertices2[caras2[j + 1]*3] &&
                    vertices2[i + 1] == vertices2[caras2[j + 1]*3 + 1] &&
                    vertices2[i + 2] == vertices2[caras2[j + 1]*3 + 2] ||
                    vertices2[i] == vertices2[caras2[j + 2]*3] &&
                    vertices2[i + 1] == vertices2[caras2[j + 2]*3 + 1] &&
                    vertices2[i + 2] == vertices2[caras2[j + 2]*3 + 2]) {
                num_x = num_x + normales2[j];
                num_y = num_y + normales2[j + 1];
                num_z = num_z + normales2[j + 2];
            }
        }
        den = sqrt(pow(num_x, 2) + pow(num_y, 2) + pow(num_z, 2));
        normales_vert[cont] = fabs(num_x / den);
        cont++;
        normales_vert[cont] = fabs(num_y / den);
        cont++;
        normales_vert[cont] = fabs(num_z / den);
        cont++;
    }

}



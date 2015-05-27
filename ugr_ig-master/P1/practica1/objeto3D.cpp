/* 
 * File:   objeto3D.cpp
 * Author: jesus
 * 
 * Created on 22 de octubre de 2014, 19:47
 */

#include "objeto3D.h"

objeto3D::objeto3D() {
}

void objeto3D::draw(int tipo){
    //0=alambre 1=solido 2=ajedrez 3=puntos
    if(tipo == 0){
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_LINE);
    }else if(tipo == 1 || tipo == 2){
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_LINE);
    }else if(tipo == 3){
        glPolygonMode(GL_FRONT, GL_POINT);
        glPolygonMode(GL_BACK, GL_POINT);
    }
    glColor3f(1, 0, 0);
    glPointSize(3);
    
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < caras.size(); i++) {
        if (tipo == 2) {
            if (i % 3 == 0) glColor3f(0, 1, 0);
            else if (i % 3 == 1) glColor3f(1, 0, 0);
        }
        glVertex3fv((GLfloat*) vertices[caras[i][0]].data());
        glVertex3fv((GLfloat*) vertices[caras[i][1]].data());
        glVertex3fv((GLfloat*) vertices[caras[i][2]].data());
    }
    glEnd();
}


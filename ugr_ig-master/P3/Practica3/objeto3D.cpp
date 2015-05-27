/* 
 * File:   objeto3D.cpp
 * Author: jesus
 * 
 * Created on 22 de octubre de 2014, 19:47
 */

#include "objeto3D.h"

objeto3D::objeto3D() {
}

void objeto3D::draw(int tipo) {
    // 0=alambre 1=solido 2=ajedrez 3=puntos
    if (tipo == 0) {
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_LINE);
    } else if (tipo == 1) {
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
    } else if (tipo == 3) {
        glPolygonMode(GL_FRONT, GL_POINT);
        glPolygonMode(GL_BACK, GL_POINT);
    }else if (tipo == 2) {
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_LINE);
        glPointSize(3);
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < caras.size(); i++) {
            if (i % 2 == 0) glColor3f(0, 1, 0);
            else if (i % 2 == 1) glColor3f(0, 0, 1);
            //glColor3f(normales[i][0], normales[i][1], normales[i][2]);
            glVertex3fv((GLfloat*) vertices[caras[i][0]].data());
            glVertex3fv((GLfloat*) vertices[caras[i][1]].data());
            glVertex3fv((GLfloat*) vertices[caras[i][2]].data());
        }
        glEnd();
    }
    if(tipo == 0 || tipo == 1 || tipo == 3) {

        
        glPointSize(3);
        glEnableClientState(GL_VERTEX_ARRAY);
        //glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices2);
        //glColorPointer(3,GL_FLOAT,0,normales_vert);
        glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, caras2);
        glDisableClientState(GL_VERTEX_ARRAY);
        //glDisableClientState(GL_COLOR_ARRAY);
    }
    if (tipo == 4) {
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_LINE);
        glPointSize(3);
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < caras.size(); i++) {
            glColor3f(normales[i][0], normales[i][1], normales[i][2]);
            glVertex3fv((GLfloat*) vertices[caras[i][0]].data());
            glVertex3fv((GLfloat*) vertices[caras[i][1]].data());
            glVertex3fv((GLfloat*) vertices[caras[i][2]].data());
        }
        glEnd();
    }
}

void objeto3D::toVector() {
    vertices_size = vertices.size()*3;
    caras_size = caras.size()*3;
    normales_size = normales.size()*3;
    vertices2 = (GLfloat*) malloc(sizeof (GLfloat) * vertices_size);
    caras2 = (GLuint*) malloc(sizeof (GLuint) * caras_size);
    normales2 = (GLfloat*) malloc(sizeof (GLfloat) * normales_size);
    int cont = 0;
    for (int i = 0; i < vertices.size(); i++) {
        for (int j = 0; j < 3; j++) {
            vertices2[cont] = vertices[i][j];
            cont++;
        }
    }
    cont = 0;
    for (int i = 0; i < caras.size(); i++) {
        for (int j = 0; j < 3; j++) {
            caras2[cont] = caras[i][j];
            cont++;
        }
    }
    cont = 0;
    for (int i = 0; i < normales.size(); i++) {
        for (int j = 0; j < 3; j++) {
            normales2[cont] = normales[i][j];
            cont++;
        }
    }
}

#include "user_code.h"

//**************************************************************************
// Funcion para dibujar los vertices de un cubo unidad
//***************************************************************************
void draw_cube() {
    GLfloat Vertices[8][3] = {
        {-0.5, -0.5, 0.5},
        {0.5, -0.5, 0.5},
        {0.5, 0.5, 0.5},
        {-0.5, 0.5, 0.5},
        {-0.5, -0.5, -0.5},
        {0.5, -0.5, -0.5},
        {0.5, 0.5, -0.5},
        {-0.5, 0.5, -0.5}};

    glColor3f(0, 1, 0);
    glPointSize(4);

    glBegin(GL_POINTS);
    for (unsigned i = 0; i < 8; i++) {
        glVertex3fv((GLfloat *) & Vertices[i]);
    }
    glEnd();
}

//**************************************************************************
// Funcion para dibujar vertices
//***************************************************************************
void draw_vertices(vector<float> &Vertices) {
    glColor3f(0, 1, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
    for (unsigned i = 0; i < Vertices.size(); i += 3) {
        glVertex3f((GLfloat) Vertices[i], (GLfloat) Vertices[i + 1], (GLfloat) Vertices[i + 2]);
    }
    glEnd();
}



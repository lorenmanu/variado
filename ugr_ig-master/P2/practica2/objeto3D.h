/* 
 * File:   objeto3D.h
 * Author: jesus
 *
 * Created on 22 de octubre de 2014, 19:47
 */

#ifndef OBJETO3D_H
#define	OBJETO3D_H
#include <vector>
#include <GL/gl.h>
#include <stdlib.h> 
#include <cmath>
class objeto3D {
public:
    objeto3D();
    void draw(int tipo);
    void toVector();

protected:
    std::vector<std::vector<GLfloat> > vertices;
    std::vector<std::vector<GLuint> > caras;
    std::vector<std::vector<GLfloat> > normales;
    GLfloat * vertices2;
    GLuint * caras2;
    GLfloat * normales2;
    GLfloat * normales_vert;
    int vertices_size,caras_size,normales_size,normales_vert_size;
};

#endif	/* OBJETO3D_H */


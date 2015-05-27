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
class objeto3D {
public:
    objeto3D();
    void draw(int tipo);
protected:
    std::vector<std::vector<GLfloat> > vertices;
    std::vector<std::vector<GLuint> > caras;
};

#endif	/* OBJETO3D_H */


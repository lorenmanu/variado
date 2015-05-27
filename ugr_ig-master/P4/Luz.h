/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>
#include <string.h>
#include "vertex.h"
#include "visualtype.h"


#ifndef _LUZ_H_
#define _LUZ_H_



class Luz
{
    private:
        GLenum lightIndex;
        _vertex3f color;
        light_t type;
        GLfloat longitud;
        GLfloat latitud;
        GLfloat position[4];
    public:
        Luz(GLenum lightIndex, GLfloat longitud, GLfloat latitud, _vertex3f color, light_t type, GLfloat position[4]);
        void activate();
        void disactivate();


};


#endif

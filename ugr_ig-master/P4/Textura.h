/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include <vector>
#include <GL/glut.h>
#include "jpg_imagen.hpp"
#define ARRAY_SIZE 4

#ifndef _TEXTURA_H_
#define _TEXTURA_H_

enum generation_t {
    NOT_ACTIVE, OBJECT, EYE
};

class Textura {
private:
    jpg::Imagen * centralImg;
    unsigned long tamx;
    unsigned long tamy;
    unsigned char * texels;
    unsigned int imageSize;
    generation_t gen;
    GLuint idTex;
    GLfloat s[ARRAY_SIZE]; //coeficientes para coordenadas s
    GLfloat t[ARRAY_SIZE]; //coeficientes para coordenadas t

public:
    Textura(const char * textureFile);
    ~Textura();
    unsigned long getX() const;
    unsigned long getY() const;
    unsigned char * getTexels() const;
    //Para activar la textura
    void activate();

};
#endif

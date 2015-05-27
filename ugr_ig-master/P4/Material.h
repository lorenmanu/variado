/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include "Textura.h"
#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

class Material {
private:
    bool isIlluminated;
    Textura * texturePtr;
    GLuint idTex;
    GLfloat amb[4], dis[4], spe[4];
    GLfloat brillo;

public:
    Material();
    Material(const char * materialFile);
    ~Material();
    void activate();
    void setAmbient(GLfloat amb[3]);
    void setDiffuse(GLfloat dis[3]);
    void setSpecular(GLfloat spe[3]);
    void setBrightness(GLfloat brillo);
    GLfloat * getAmbient() const;
    GLfloat * getDiffuse() const;
    GLfloat * getSpecular() const;
    GLfloat getBrillo() const;
};
#endif

/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include "Textura.h"
#include <cassert>

Textura::Textura(const char *textureFile) {
    this->centralImg = NULL;
    //cargar la imagen
    this->centralImg = new jpg::Imagen(textureFile);

    this->tamx = centralImg->tamX(); //num.columnas
    this->tamy = centralImg->tamY();
    this->texels = centralImg->leerPixels(); //puntero textes
    this->imageSize = tamx * tamy * 3;
    this->gen = NOT_ACTIVE;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        s[i] = t[i] = 0.0f;
    }
    //hace idTex igual a un nuevo identificador
    glGenTextures(1, &idTex);
    glBindTexture(GL_TEXTURE_2D, idTex); //activa textura con identificado 'idTex'
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, this->tamx, this->tamy, GL_RGB, GL_UNSIGNED_BYTE, this->texels);
    assert(glGetError() == GL_NO_ERROR);
}

Textura::~Textura() {
    delete this->centralImg;
    glDisable(GL_TEXTURE_2D);
}

unsigned long Textura::getX() const {
    return this->tamx;
}

unsigned long Textura::getY() const {
    return this->tamy;
}

unsigned char * Textura::getTexels() const {
    return this->texels;
}

void Textura::activate() {


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->idTex);
    if (gen == NOT_ACTIVE) {
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    } else {
        glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

        glTexGenfv(GL_S, GL_OBJECT_PLANE, s);
        glTexGenfv(GL_T, GL_OBJECT_PLANE, t);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }

}

/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include "Material.h"

Material::Material() {
    isIlluminated = false;
    texturePtr = NULL;
    amb[3] = dis[3] = spe[3] = 1.0;
}

Material::Material(const char * materialFile) {
    texturePtr = new Textura(materialFile);
    amb[3] = dis[3] = spe[3] = 1.0;
}

Material::~Material() {
    if (texturePtr != NULL)
        delete texturePtr;
}

void Material::activate() {
    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_NORMALIZE);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dis);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spe);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);


    if (texturePtr != NULL)
        texturePtr->activate();
    else
        glDisable(GL_TEXTURE_2D);


}

void Material::setAmbient(GLfloat amb[3]) {
    for (int i = 0; i < 4; i++)
        this->amb[i] = amb[i];
}

void Material::setDiffuse(GLfloat dis[3]) {
    for (int i = 0; i < 4; i++)
        this->dis[i] = dis[i];
}

void Material::setSpecular(GLfloat spe[3]) {
    for (int i = 0; i < 4; i++)
        this->spe[i] = spe[i];
}

void Material::setBrightness(GLfloat brillo) {
    this->brillo = brillo;
}

GLfloat * Material::getAmbient() const {
    return (GLfloat *)this->amb;
}

GLfloat * Material::getDiffuse() const {
    return (GLfloat *)this->dis;
}

GLfloat * Material::getSpecular() const {
    return (GLfloat *)this->spe;
}

GLfloat Material::getBrillo() const {
    return this->brillo;
}


/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include "Lata.h"
#include <iostream>

using namespace std;


Lata::Lata() {
    isLight = true;
    cuerpo_lata = new Objeto3D("text-lata-1.jpg");
    cuerpo_lata->initializeRotationalObject2("lata-pcue.ply");

    tapa_inf = new Objeto3D();
    tapa_inf->initializeRotationalObject2("lata-psup.ply");

    tapa_sup = new Objeto3D();
    tapa_sup->initializeRotationalObject2("lata-pinf.ply");


}

Lata::~Lata() {
    delete cuerpo_lata;
    delete tapa_sup;
    delete tapa_inf;
}

void Lata::draw(visual_t visualization) {

    GLfloat whiteSpecular[] = {1.0, 1.0, 1.0};
    GLfloat blackSpecular[] = {0.0, 0.0, 0.0};
    GLfloat someDiffuse[] = {0.4, 0.4, 0.4};
    GLfloat someDiffuse1[] = {0.6, 0.6, 0.6};
    GLfloat silverAmbient[] = {0.19225, 0.19225, 0.19225};
    GLfloat silverDiffuse[] = {0.50754, 0.50754, 0.50754};
    GLfloat silverSpecular[] = {0.508273, 0.508273, 0.508273};
    GLfloat shiny = 100.0;
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
    cuerpo_lata->setAmbient(silverAmbient);
    cuerpo_lata->setDiffuse(silverDiffuse);
    cuerpo_lata->setSpecular(silverSpecular);
    cuerpo_lata->setBrightness(0);
    cuerpo_lata->draw(visualization);

    shiny = 100.0;
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
    tapa_inf->setAmbient(silverAmbient);
    tapa_inf->setDiffuse(silverDiffuse);
    tapa_inf->setSpecular(silverSpecular);
    tapa_inf->setBrightness(0);
    tapa_inf->draw(visualization);

    tapa_sup->setAmbient(silverAmbient);
    tapa_sup->setDiffuse(silverDiffuse);
    tapa_sup->setSpecular(silverSpecular);
    tapa_sup->setBrightness(0);
    tapa_sup->draw(visualization);


}

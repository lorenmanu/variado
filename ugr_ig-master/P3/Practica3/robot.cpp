/* 
 * File:   robot.cpp
 * Author: jesus
 * 
 * Created on 29 de noviembre de 2014, 13:19
 */

#include "robot.h"

robot::robot() {
    posicion = 0;
    piarriba = cilindro(1.5, 0.2, true, true);
    piabajo = cilindro(1.5, 0.2, true, true);
    pdarriba = cilindro(1.5, 0.2, true, true);
    pdabajo = cilindro(1.5, 0.2, true, true);
    bdarriba = cilindro(1, 0.2, true, true);
    biarriba = cilindro(1, 0.2, true, true);
    cuerpo = cube(1.5);
    cabeza = esfera(0.5);
    ojo1 = esfera(0.1);
    ojo2 = esfera(0.1);
    gorro = cono(1, 0.7, false);
    baile = false;
    
    //Examen
    codo1 = esfera(0.2);
    codo2 = esfera(0.2);
    mano1 = esfera(0.25);
    mano2 = esfera(0.25);
    bdabajo = cilindro(1, 0.2, true, true);
    biabajo = cilindro(1, 0.2, true, true);
}

robot::robot(const robot& orig) {
}

void robot::draw(int giro, int gla, int gra, int grl, int gll, int tipo) {
    modo = tipo;
    if (tipo == 0) {
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_LINE);
    } else if (tipo == 1) {
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
    } else if (tipo == 3) {
        glPolygonMode(GL_FRONT, GL_POINT);
        glPolygonMode(GL_BACK, GL_POINT);
    } else if (tipo == 2) {

        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
    }
    drawHead();

    glPushMatrix();
    glRotatef(giro, 0, 1, 0);
    drawEyes();
    glPopMatrix();

    drawBody();

    glPushMatrix();
    glTranslatef(0,0.7,0.0);
    glRotatef(grl, 1, 0, 0);
    glTranslatef(0,-0.7,0.0);
    drawLeftArm();
    drawCodo1();
    glRotatef(gla, 1, 0, 0);
    drawLeftArmAbajo();
    drawMano1();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.3,0.0);
    glRotatef(grl, 1, 0, 0);
    glTranslatef(0,-0.3,0.0);
    drawRightArm();
    drawCodo2();
    glRotatef(gra, 1, 0, 0);
    drawRightArmAbajo();
    drawMano2();
    glPopMatrix();
  
    glPushMatrix();
    glTranslatef(0,0.7,0.0);
    glRotatef(grl, 1, 0, 0);
    glTranslatef(0,-0.7,0.0);
    drawRightLeg();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0.7,0.0);
    glRotatef(gll, 1, 0, 0);
    glTranslatef(0,-0.7,0.0);
    drawLeftLeg1();
    drawLeftLeg2();
    glPopMatrix();
}

void robot::drawHead() {
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(0, 1.15, 0);
    cabeza.draw(modo);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 1.25, 0);
    glRotatef(0, 1.0f, 0.0f, 0.0f);
    gorro.draw(modo);
    glPopMatrix();

}

void robot::drawEyes() {
    glPushMatrix();
    glTranslatef(-0.2, 1.1, 0.50);
    ojo1.draw(modo);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.2, 1.1, 0.50);
    ojo2.draw(modo);
    glPopMatrix();
}

void robot::drawBody() {
    glPushMatrix();
    glColor3f(1, 0, 0);
    //glTranslatef(0, -0.5, 0);
    glRotatef(90, 0, 1, 0);
    cuerpo.draw(modo);
    glPopMatrix();
}

void robot::drawLeftArm() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(-1, 0.20, 0);
    //glRotatef(0, 1, 0, 0);
    biarriba.draw(modo);
    glPopMatrix();
}

void robot::drawRightArm() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(1, 0.20, 0);
    bdarriba.draw(modo);
    glPopMatrix();
}

void robot::drawRightLeg() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(-0.5, -1.50, 0);
    pdarriba.draw(modo);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0, 1);
    glTranslatef(-0.5, -3.01, 0);
    pdabajo.draw(modo);
    glPopMatrix();
}

void robot::drawLeftLeg1() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(0.5, -1.50, 0);
    piarriba.draw(modo);
    glPopMatrix();
}
void robot::drawLeftLeg2() {
    glPushMatrix();
    glColor3f(1, 0, 1);
    glTranslatef(0.5, -3.01, 0);
    piabajo.draw(modo);
    glPopMatrix();
}


void robot::drawMano1(){
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-1, -1.60, 0);
    //glRotatef(0, 1, 0, 0);
    mano1.draw(modo);
    glPopMatrix(); 
}
void robot::drawMano2(){
    glPushMatrix();
    glColor3f(1, 0,0);
    glTranslatef(1, -1.60, 0);
    //glRotatef(0, 1, 0, 0);
    mano2.draw(modo);
    glPopMatrix(); 
}
void robot::drawCodo1(){
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(-1, -0.40, 0);
    //glRotatef(0, 1, 0, 0);
    codo1.draw(modo);
    glPopMatrix();
}
void robot::drawCodo2(){
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(1, -0.40, 0);
    //glRotatef(0, 1, 0, 0);
    codo2.draw(modo);
    glPopMatrix();    
}
void robot::drawLeftArmAbajo(){
     glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(-1, -1.0, 0);
    //glRotatef(0, 1, 0, 0);
    biabajo.draw(modo);
    glPopMatrix();
}
void robot::drawRightArmAbajo(){
     glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(1, -1.0, 0);
    //glRotatef(0, 1, 0, 0);
    bdabajo.draw(modo);
    glPopMatrix();
}


robot::~robot() {
}


/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include "Robot.h"

Robot::Robot() {
    posicion = 0;
    baile = false;
}

Robot::Robot(const Robot& orig) {
}

void Robot::draw(int giro, int gla, int gra, int grl, int gll, int tipo) {
    modo = tipo;
    if (tipo == 0) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    } else if (tipo == 1) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    } else if (tipo == 2) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

    } else if (tipo == 3) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    drawHead();

    glPushMatrix();
    glRotatef(giro, 0, 1, 0);
    drawEyes();
    glPopMatrix();

    drawBody();

    glPushMatrix();
    glTranslatef(0, 0.7, 0.0);
//    glRotatef(grl, 1, 0, 0);
    glTranslatef(0, -0.7, 0.0);
    drawLeftArm();
    drawCodo1();
    glRotatef(gla, 1, 0, 0);
    drawLeftArmAbajo();
    drawMano1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.3, 0.0);
    //glRotatef(grl, 1, 0, 0);
    glTranslatef(0, -0.3, 0.0);
    drawRightArm();
    drawCodo2();
    glRotatef(gra, 1, 0, 0);
    drawRightArmAbajo();
    drawMano2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.7, 0.0);
    glRotatef(grl, 1, 0, 0);
    glTranslatef(0, -0.7, 0.0);
    drawRightLeg();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.7, 0.0);
    glRotatef(gll, 1, 0, 0);
    glTranslatef(0, -0.7, 0.0);
    drawLeftLeg1();
    drawLeftLeg2();
    glPopMatrix();
}

void Robot::drawHead() {
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(0, 1.15, 0);
    glutSolidSphere(.5,20,20);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 1.25, 0);
    glRotatef(90,-90,0,0);
    //gorro.draw(modo);
gluCylinder(gluNewQuadric(),0.6,0.01,1,25,25);
    
    glPopMatrix();

}

void Robot::drawEyes() {
    glPushMatrix();
    glTranslatef(-0.2, 1.1, 0.50);
    glutSolidSphere(.1,20,20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.2, 1.1, 0.50);
    glutSolidSphere(.1,20,20);
    glPopMatrix();
}

void Robot::drawBody() {
    glPushMatrix();
    glColor3f(1, 0, 0);
    //glTranslatef(0, -0.5, 0);
    glRotatef(90, 0, 1, 0);
    glutSolidCube(1.5);
    glPopMatrix();
}

void Robot::drawLeftArm() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(-1, 0.8, 0);
    glRotatef(90, 90, 0, 0);
    gluCylinder(gluNewQuadric(),0.3,0.3,1,25,25);
    glPopMatrix();
}

void Robot::drawRightArm() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(1, 0.8, 0);
    glRotatef(90, 90, 0, 0);
    
    gluCylinder(gluNewQuadric(),0.3,0.3,1,25,25);
    glPopMatrix();
}

void Robot::drawRightLeg() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(-0.5, -.8, 0);
    glRotatef(90, 90, 0, 0);
    
    gluCylinder(gluNewQuadric(),0.3,0.3,1.5,25,25);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0, 1);
    glTranslatef(-0.5, -2.3, 0);
    glRotatef(90, 90, 0, 0);
    
    gluCylinder(gluNewQuadric(),0.3,0.3,1.5,25,25);
    glPopMatrix();
}

void Robot::drawLeftLeg1() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(0.5, -.8, 0);
    glRotatef(90, 90, 0, 0);
    
    gluCylinder(gluNewQuadric(),0.3,0.3,1.5,25,25);
    glPopMatrix();
}

void Robot::drawLeftLeg2() {
    glPushMatrix();
    glColor3f(1, 0, 1);
    glTranslatef(0.5, -2.3, 0);
    glRotatef(90, 90, 0, 0);
    
    gluCylinder(gluNewQuadric(),0.3,0.3,1.5,25,25);
    glPopMatrix();
}

void Robot::drawMano1() {
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-1, -1.60, 0);
    
    glutSolidSphere(.25,20,20);
    glPopMatrix();
}

void Robot::drawMano2() {
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(1, -1.60, 0);
    
glutSolidSphere(.25,20,20);
glPopMatrix();
}

void Robot::drawCodo1() {
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(-1, -0.40, 0);
    
glutSolidSphere(.25,20,20);    
glPopMatrix();
}

void Robot::drawCodo2() {
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(1, -0.40, 0);
    glutSolidSphere(.25,20,20);
glPopMatrix();
}

void Robot::drawLeftArmAbajo() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(-1, -.6, 0);
    glRotatef(90, 90, 0, 0);
    gluCylinder(gluNewQuadric(),0.3,0.3,1,25,25);
    glPopMatrix();
}

void Robot::drawRightArmAbajo() {
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(1, -.6, 0);
    glRotatef(90, 90, 0, 0);
    gluCylinder(gluNewQuadric(),0.3,0.3,1,25,25);
    glPopMatrix();
}

Robot::~Robot() {
}


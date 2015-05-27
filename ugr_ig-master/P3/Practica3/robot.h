/* 
 * File:   robot.h
 * Author: jesus
 *
 * Created on 29 de noviembre de 2014, 13:19
 */

#ifndef ROBOT_H
#define	ROBOT_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "cilindro.h"
#include "cube.h"
#include "esfera.h"
#include "cono.h"
class robot{
public:
    robot();
    robot(const robot& orig);
    void draw(int giro,int gla,int gra,int grl, int gll,int tipo);
    void drawHead();
    void drawEyes();
    void drawBody();
    void drawRightArm();
    void drawLeftArm();
    void drawRightLeg();
    void drawLeftLeg1();
    void drawLeftLeg2();
    void bailar();
    
    //Examen
    void drawMano1();
    void drawMano2();
    void drawCodo1();
    void drawCodo2();
    void drawLeftArmAbajo();
    void drawRightArmAbajo();
    
    virtual ~robot();
private:
    float posicion;
    cilindro bdarriba,biarriba,pdabajo,pdarriba,piabajo,piarriba;
    cono gorro;
    cube cuerpo;
    esfera cabeza,ojo1,ojo2;
    int modo;
    bool baile;
    
    //Examen
    esfera codo1,codo2,mano1,mano2;
    cilindro bdabajo,biabajo;
};

#endif	/* ROBOT_H */


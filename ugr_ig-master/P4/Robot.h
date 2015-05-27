/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#ifndef ROBOT_H
#define	ROBOT_H

class Robot{
public:
    Robot();
    Robot(const Robot& orig);
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
    
    virtual ~Robot();
private:
    float posicion;
    int modo;
    bool baile;

};

#endif	/* ROBOT_H */


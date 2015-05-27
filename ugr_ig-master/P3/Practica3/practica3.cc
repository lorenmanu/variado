#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <iostream>

#include "scene.h"
#include "robot.h"
#include "esfera.h"
#include "cono.h"

#define UI_window_pos_x     50
#define UI_window_pos_y     50
#define UI_window_width     500
#define UI_window_height    500

// variables que determninan la posicion y tamaño de la ventana X
//int UI_window_pos_x = 50, UI_window_pos_y = 50, UI_window_width = 500, UI_window_height = 500;
scene escena;
robot r;
int copia_argv;

void clear_window() {
    escena.clear_window();
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection() {
    escena.change_projection();
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer() {
    escena.change_observer();
}

void draw_objects() {
    r.draw(escena.getGiro(),escena.getgra(),escena.getgla(),escena.getgrl(),escena.getgll(),escena.getModo());

}

void draw_scene(void) {
    escena.draw_scene();
    draw_objects();
    glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1, int Alto1) {
    escena.change_window_size(Ancho1, Alto1);
    glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************
void idle(){
    escena.idle();
}
void normal_keys(unsigned char Tecla1, int x, int y) {
    escena.normal_keys(Tecla1, x, y);
    glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1, int x, int y) {
    escena.special_keys(Tecla1, x, y);
    glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void) {
    escena.initialize();
}



//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {
    escena = scene(UI_window_pos_x, UI_window_pos_y, UI_window_width, UI_window_height,1);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(UI_window_pos_x, UI_window_pos_y);
    glutInitWindowSize(UI_window_width, UI_window_height);
    glutCreateWindow("PRACTICA 3");
    glutDisplayFunc(draw_scene);
    glutReshapeFunc(change_window_size);
    glutKeyboardFunc(normal_keys);
    glutSpecialFunc(special_keys);
    glutIdleFunc(idle);
    initialize();
    glutMainLoop();
    return 0;
}

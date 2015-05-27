/* 
 * File:   scene.cpp
 * Author: jesus
 * 
 * Created on 21 de octubre de 2014, 16:54
 */


#include "scene.h"
#include <iostream>

scene::scene() {

}

scene::scene(int UI_x, int UI_y, int UI_width, int UI_height, int m) {
    UI_window_pos_x = UI_x;
    UI_window_pos_y = UI_y;
    UI_window_width = UI_width;
    UI_window_height = UI_height;
    modo = m;
    giro = 0;
    gra = 0;
    gla = 0;
    grl = 0;
    gll = 0;
    caminar = false;
}

int scene::getModo() {
    return modo;
}

scene::scene(const scene& orig) {
}

void scene::clear_window() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void scene::change_projection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
    //  Front_plane>0  Back_plane>PlanoDelantero)
    glFrustum(-Window_width, Window_width, -Window_height, Window_height, Front_plane, Back_plane);
}

void scene::change_observer() {
    // posicion del observador
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -Observer_distance);
    glRotatef(Observer_angle_x, 1, 0, 0);
    glRotatef(Observer_angle_y, 0, 1, 0);
}

void scene::draw_scene(void) {
    clear_window();
    change_observer();
    ejes.draw_axis();
}

void scene::change_window_size(int Ancho1, int Alto1) {
    change_projection();
    glViewport(0, 0, Ancho1, Alto1);
}

void scene::normal_keys(unsigned char Tecla1, int x, int y) {

    if (toupper(Tecla1) == 'Q') exit(0);

    //Esto nos permitirá cambiar en ejecución el modo
    if (toupper(Tecla1) == 'L') modo = 0; //Alambre
    if (toupper(Tecla1) == 'S') modo = 1; //Solido
    if (toupper(Tecla1) == 'A') modo = 2; //Ajedrez
    if (toupper(Tecla1) == 'P') modo = 3; //Puntos
    if (toupper(Tecla1) == 'O') modo = 4;
    /*Para robot*/
    //Piernas parte abajo
    if (Tecla1 == 'z') {
        if (grl <= 15)
            grl += 5; //Puntos
    }
    if (Tecla1 == 'Z') {
        if (grl > 0)
            grl -= 5; //Puntos
    }
    if (Tecla1 == 'x') {
        if (gll <= 15)
            gll += 5; //Puntos
    }
    if (Tecla1 == 'X') {
        if (gll > 0)
            gll -= 5; //Puntos
    }
    //Brazos parte abajo
    if (Tecla1 == 'c') {
        if (gra >= -45)
            gra -= 5; //Puntos
    }
    if (Tecla1 == 'C') {
        if (gra < 0)
            gra += 5; //Puntos
    }
    if (Tecla1 == 'v') {
        if (gla >= -45)
            gla -= 5; //Puntos
    }

    if (Tecla1 == 'V') {
        if (gla < 0)
            gla += 5; //Puntos
    }
    //Ojos
    if (toupper(Tecla1) == 'B') {
        if (giro>-90)
            giro -= 5; //Puntos
    }
    if (toupper(Tecla1) == 'N') {
        if (giro < 90)
            giro += 5; //Puntos
    }
    if (Tecla1 == 'w') {
        if (!caminar)
            caminar = true;
        else
            caminar = false;
    }
}

void scene::special_keys(int Tecla1, int x, int y) {

    switch (Tecla1) {
        case GLUT_KEY_LEFT:Observer_angle_y--;
            break;
        case GLUT_KEY_RIGHT:Observer_angle_y++;
            break;
        case GLUT_KEY_UP:Observer_angle_x--;
            break;
        case GLUT_KEY_DOWN:Observer_angle_x++;
            break;
        case GLUT_KEY_PAGE_UP:Observer_distance *= 1.2;
            break;
        case GLUT_KEY_PAGE_DOWN:Observer_distance /= 1.2;
            break;
    }
}

void scene::idle() {
    static int cont = 0;
    if (caminar) {
        cont++;
        if (cont <= 72) {
            if (giro < 360)
                giro += 5.0;
            glutPostRedisplay();
        } else {
            cont = 0;
            caminar = false;
            giro = 0;
        }
    

}
}
void scene::initialize() {
    // se inicalizan la ventana y los planos de corte
    Window_width = .5;
    Window_height = .5;
    Front_plane = 1;
    Back_plane = 1000;

    // se inicia la posicion del observador, en el eje z
    Observer_distance = 15 * Front_plane; //AUMENTADO de 5 a 15 PARA VER MEJOR LA FIGURA
    Observer_angle_x = 0;
    Observer_angle_y = 0;

    // se indica cual sera el color para limpiar la ventana	(r,v,a,al)
    // blanco=(1,1,1,1) rojo=(1,0,0,1), ...
    glClearColor(1, 1, 1, 1);

    // se habilita el z-bufer
    glEnable(GL_DEPTH_TEST);
    change_projection();
    glViewport(0, 0, UI_window_width, UI_window_height);
}

int scene::getgra() {
    return gra;
}

int scene::getgla() {
    return gla;
}

int scene::getgrl() {
    return grl;
}

int scene::getgll() {
    return gll;
}

int scene::getGiro() {
    return giro;
}

scene::~scene() {
}


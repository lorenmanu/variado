/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */

#include "Escena.h"

Escena::Escena() {
    UI_window_pos_x = 50;
    UI_window_pos_y = 50;
    UI_window_width = 500;
    UI_window_height = 500;
    Window_width = .5;
    Window_height = .5;
    Front_plane = 1;
    Back_plane = 1000;

    // se inicia la posicion del observador, en el eje z
    Observer_distance = 10 * Front_plane;
    Observer_angle_x = 0;
    Observer_angle_y = 0;

}

Escena::Escena(const Escena& orig) {
}


void Escena::clear_window() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(65.0,)
    // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
    //  Front_plane>0  Back_plane>PlanoDelantero)
    glFrustum(-Window_width, Window_width, -Window_height, Window_height, Front_plane, Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer() {

    // posicion del observador
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -Observer_distance);
    glRotatef(Observer_angle_x, 1, 0, 0);
    glRotatef(Observer_angle_y, 0, 1, 0);
}

void Escena::change_window_size(int Ancho1, int Alto1) {
    //change_projection();
    glViewport(0, 0, Ancho1, Alto1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, Ancho1 / Alto1, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    glutPostRedisplay();
}

void Escena::draw_axis() {
    glBegin(GL_LINES);
    // eje X, color rojo
    glColor3f(1, 0, 0);
    glVertex3f(-AXIS_SIZE, 0, 0);
    glVertex3f(AXIS_SIZE, 0, 0);
    // eje Y, color verde
    glColor3f(0, 1, 0);
    glVertex3f(0, -AXIS_SIZE, 0);
    glVertex3f(0, AXIS_SIZE, 0);
    // eje Z, color azul
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, -AXIS_SIZE);
    glVertex3f(0, 0, AXIS_SIZE);
    glEnd();
}
void Escena::special_keys(int Tecla1, int x, int y) {

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
            break; //Zoom out
        case GLUT_KEY_PAGE_DOWN:Observer_distance /= 1.2;
            break; //Zoom in
    }
    glutPostRedisplay();
}
int Escena::getUiwh(){
    return UI_window_height;
}
int Escena::getUiww(){
    return UI_window_width;
}
int Escena::getWpx(){
    return UI_window_pos_x;
}
int Escena::getWpy(){
    return UI_window_pos_y;
}


Escena::~Escena() {
}




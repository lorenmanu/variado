/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#ifndef ESCENA_H
#define	ESCENA_H
#define AXIS_SIZE 5000
class Escena {
public:
    Escena();
    Escena(const Escena& orig);
    void clear_window();
    void change_projection();
    void change_observer();
    void change_window_size(int Ancho1, int Alto1);
    void draw_axis();
    int getUiww();
    int getUiwh();
    int getWpx();
    int getWpy();
    void special_keys(int Tecla1, int x, int y);
    virtual ~Escena();
private:
    // variables que definen la posicion de la camara en coordenadas polares
    GLfloat Observer_distance;
    GLfloat Observer_angle_x;
    GLfloat Observer_angle_y;

    // variables que controlan la ventana y la transformacion de perspectiva
    GLfloat Window_width, Window_height, Front_plane, Back_plane;

    // variables que determninan la posicion y tamaño de la ventana X
    int UI_window_pos_x, UI_window_pos_y, UI_window_width, UI_window_height;

};

#endif	/* ESCENA_H */


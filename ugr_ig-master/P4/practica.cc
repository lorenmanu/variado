/* 
 * Jesús Ángel González Novez
 * Práctica 4 IG
 *
 */
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <iostream> //Para cerr
#include "vertex.h"
#include "file_ply_stl.hpp"
#include "Objeto3D.h"
#include "Robot.h"
#include "Lata.h"
#include "visualtype.h"
#include "jpg_imagen.hpp"
#include "Luz.h"
#include "Escena.h"
Escena escena;

GLint texture = 0;
//enum que denota los diferentes estados

enum state_t {
    NONE = 0, PLY, ROTATION, JERARQUICO, P4
};
bool isP4 = false; //Modo practica 4



static GLfloat spin = 0.0;
static GLfloat spin2 = 0.0;

//************************Prácticas 1,2,3*******************
Objeto3D figura_ply;
Objeto3D figura_rotacional;
Robot robot;
int giro = 1, gla = 1, gra = 1, grl = 1, gll = 1, modo = 0;
//************************Práctica 4************************
Objeto3D * peonMadera;
Objeto3D * peonBlanco;
Objeto3D * peonNegro;
Lata * can = NULL;
//Fuentes de Luz
Luz * source1 = NULL;
Luz * source2 = NULL;

//Variable que destaca el estado de dibujo. PLY, ROTACIONAL, HIERARCHY
state_t state = NONE;
state_t lastState = NONE;

//Variable que destaca el modo de visualizacion
visual_t visualization = POINT;
visual_t last_visualization = POINT;

//// variables que definen la posicion de la camara en coordenadas polares
//GLfloat Observer_distance;
//GLfloat Observer_angle_x;
//GLfloat Observer_angle_y;
//
//// variables que controlan la ventana y la transformacion de perspectiva
//GLfloat Window_width, Window_height, Front_plane, Back_plane;
//
//// variables que determninan la posicion y tamaño de la ventana X
//int UI_window_pos_x = 50, UI_window_pos_y = 50, UI_window_width = 500, UI_window_height = 500;

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


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis() {
    escena.draw_axis();
}

//Modo practica 4

void p4_scene() {
    glPushMatrix();
    glScalef(3.0, 3.0, 3.0);
    can->draw(visualization);
    glPopMatrix();
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(0.0, 1.5, 4.0);
    glPushMatrix();
    GLfloat shiny = 100.0;
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
    peonMadera->draw(visualization);
    glPopMatrix();
    glTranslatef(3.5, 0.0, 0.0);
    peonBlanco->draw(visualization);
    glTranslatef(3.5, 0.0, 0.0);
    GLfloat blackAmbientLight[] = {0.0, 0.0, 0.0};
    peonNegro->draw(visualization);
    glPopMatrix();
    glPopMatrix();
}

//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects() {

    switch (state) {
        case PLY:
            //glutWireCube(1.0);
            figura_ply.draw(visualization);
            break;
        case ROTATION:
            figura_rotacional.draw(visualization);
            break;
        case JERARQUICO:
            robot.draw(giro, gla, gra, grl, gll, modo);
            break;
        case P4:
            p4_scene();
            break;

    }


}



//**************************************************************************
//
//***************************************************************************

void draw_scene(void) {

    clear_window();
    change_observer();
    draw_axis();
    draw_objects();
    GLfloat positional[] = {-3.0, -15.0, 1.0, 1.0};
    GLfloat directional[] = {3.0, 15.0, 0.0, 0.0};
    if (state == P4) {
        light_t type1 = DIRECTIONAL;
        light_t type2 = POSITIONAL;
        source1 = new Luz(GL_LIGHT0, 0.0, 0.0, _vertex3f(1.0, 1.0, 1.0), type2, positional);
        source2 = new Luz(GL_LIGHT1, spin, spin2, _vertex3f(0.6, 0.6, 0.6), type1, directional);
        source1->activate();
        source2->activate();
    } else {
        glDisable(GL_LIGHTING);
        if (source1 != NULL)
            source1->disactivate();
        if (source2 != NULL)
            source2->disactivate();
    }
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
}


//Funcion que define las teclas de la practica 4
bool p4_keys(unsigned char Tecla) {
    bool actualizar = true;
    switch (toupper(Tecla)) {
        case '1':
            visualization = ILUM_PLANO;
            glutPostRedisplay();
            break;
        case '2':
            visualization = ILUM_SOFT;
            glutPostRedisplay();
            break;
        case '4':
            isP4 = false;
            state = lastState;
            visualization = last_visualization;
            break;
        case 'A':
            spin = (spin + 3);
            glutPostRedisplay();
            break;
        case 'Z':
            spin = (spin - 3);
            glutPostRedisplay();
            break;
        case 'X':
            spin2 += 3;
            glutPostRedisplay();
            break;
        case 'C':
            spin2 -= 3;
            glutPostRedisplay();
            break;
        default:
            glutPostRedisplay();
            break;
    }
    return actualizar;

}

//Funcion que define las teclas de la practica 1 - 3

bool p1_to_p3_keys(unsigned char Tecla) {
    bool actualizar = true;
    switch (Tecla) {
        case '1':
            state = PLY;
            break;
        case '2':
            state = ROTATION;
            break;
        case '3':
            state = JERARQUICO;
            break;
        case '4':
            isP4 = true;
            //Guardar el ultimo estado
            lastState = state;
            state = P4;
            last_visualization = visualization;
            visualization = ILUM_PLANO;
            break;
        case 'p':
            visualization = POINT;
            modo = 2;
            glutPostRedisplay();
            break;
        case 'l':
            visualization = LINE;
            modo = 0;
            glutPostRedisplay();
            break;
        case 's':
            visualization = FILL;
            modo = 3;
            glutPostRedisplay();
            break;
        case 'a':
            visualization = CHECKERED;
            modo = 1;
            glutPostRedisplay();
            break;

        default: glutPostRedisplay();
            break;
    }


    if (state == JERARQUICO) {

        /*Para robot*/

        //Piernas parte abajo
        if (Tecla == 'z') {
            if (grl <= 15)
                grl += 5; //Puntos
        }
        if (Tecla == 'Z') {
            if (grl > 0)
                grl -= 5; //Puntos
        }
        if (Tecla == 'x') {
            if (gll <= 15)
                gll += 5; //Puntos
        }
        if (Tecla == 'X') {
            if (gll > 0)
                gll -= 5; //Puntos
        }
        //Brazos parte abajo
        if (Tecla == 'c') {
            if (gra >= -45)
                gra -= 5; //Puntos
        }
        if (Tecla == 'C') {
            if (gra < 0)
                gra += 5; //Puntos
        }
        if (Tecla == 'v') {
            if (gla >= -45)
                gla -= 5; //Puntos
        }

        if (Tecla == 'V') {
            if (gla < 0)
                gla += 5; //Puntos
        }
        //Ojos
        if (toupper(Tecla) == 'B') {
            if (giro>-90)
                giro -= 5; //Puntos
        }
        if (toupper(Tecla) == 'N') {
            if (giro < 90)
                giro += 5; //Puntos
        }
    }
    return actualizar;
}
//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1, int x, int y) {

    //En base a la tecla tocada, se determina que se dibuja y como
    bool actualizar = true;
    ;
    switch (Tecla1) {
        case 'Q': exit(0);
            break;
        case 27: exit(0);
            break;
        default:
            switch (isP4) {
                case true:
                    actualizar = p4_keys(Tecla1);
                    glutPostRedisplay();
                    break;
                case false:
                    actualizar = p1_to_p3_keys(Tecla1);
                    glutPostRedisplay();
                    break;
                default:
                    glutPostRedisplay();
                    break;

            }
            if (actualizar)
                glutPostRedisplay();
            break;


    }

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
}


//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(const char * file1) {
    // se inicalizan la ventana y los planos de corte


    // se indica cual sera el color para limpiar la ventana	(r,v,a,al)
    // blanco=(1,1,1,1) rojo=(1,0,0,1), ...
    glClearColor(1, 1, 1, 1);

    // se habilita el z-bufer
    glEnable(GL_DEPTH_TEST);
    change_projection();
    glViewport(0, 0, escena.getUiww(), escena.getUiwh());


    figura_ply.leer_ply("beethoven.ply");
    figura_rotacional.initializeRotationalObject("peon.ply");

    GLfloat whiteSpecular[] = {1.0, 1.0, 1.0};
    GLfloat blackSpecular[] = {0.0, 0.0, 0.0};
    GLfloat lowAmbient[] = {0.3, 0.3, 0.3};
    GLfloat a[] = {0.1, 0.1, 0.1};

    peonMadera = new Objeto3D("text-madera.jpg");
    peonMadera->initializeRotationalObject("peon.ply");

    peonMadera->setAmbient(a);
    peonMadera->setDiffuse(whiteSpecular);
    peonMadera->setSpecular(whiteSpecular);
    peonMadera->setBrightness(30);


    peonBlanco = new Objeto3D();
    peonBlanco->initializeRotationalObject("peon.ply");
    peonBlanco->setAmbient(lowAmbient);
    peonBlanco->setDiffuse(whiteSpecular);
    peonBlanco->setSpecular(blackSpecular);
    peonBlanco->setBrightness(30);

    peonNegro = new Objeto3D();
    peonNegro->initializeRotationalObject("peon.ply");
    peonNegro->setAmbient(blackSpecular);
    peonNegro->setDiffuse(lowAmbient);
    peonNegro->setSpecular(whiteSpecular);
    peonNegro->setBrightness(30);

    can = new Lata();
}

//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(escena.getWpx(), escena.getWpy());
    glutInitWindowSize(escena.getUiww(), escena.getUiwh());
    glutCreateWindow(argv[0]);
    glutDisplayFunc(draw_scene);
    glutReshapeFunc(change_window_size);
    glutKeyboardFunc(normal_keys);
    glutSpecialFunc(special_keys);
    if (argc != 2)
        std::cerr << "Error: Numero invalido de argumentos.\nError:./practica1 [nombreDelFicheroPlySinExtension]" << std::endl;
    else {
        initialize(argv[1]);
        glutMainLoop();
    }
    return 0;
}

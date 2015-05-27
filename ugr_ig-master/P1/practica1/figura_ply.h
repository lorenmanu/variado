/* 
 * File:   figura_ply.h
 * Author: jesus
 *
 * Created on 21 de octubre de 2014, 23:10
 */

#ifndef FIGURA_PLY_H
#define	FIGURA_PLY_H

#include "file_ply_stl.hpp"
#include "objeto3D.h"
class figura_ply : public objeto3D {
public:
    figura_ply();
    figura_ply(char * ruta);
};

#endif	/* FIGURA_PLY_H */


/* 
 * File:   cube.h
 * Author: jesus
 *
 * Created on 22 de octubre de 2014, 19:54
 */

#ifndef CUBE_H
#define	CUBE_H
#include "objeto3D.h"
#include <cmath>
#include <iostream>
#include "revolucion.h"

#define PI 3.141592653589793238463
class cube : public revolucion{
public:
    cube();
    cube(float lado);
};

#endif	/* CUBE_H */


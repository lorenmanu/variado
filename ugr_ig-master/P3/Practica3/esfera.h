/* 
 * File:   figura_revolucion.h
 * Author: jesus
 *
 * Created on 24 de octubre de 2014, 16:55
 */

#ifndef ESFERA_H
#define	ESFERA_H
#include <cmath>
#include <iostream>
#include "revolucion.h"

#define PI 3.141592653589793238463
class esfera : public revolucion{
public:
    esfera();
    esfera(float radio);
};

#endif	/* FIGURA_REVOLUCION_H */


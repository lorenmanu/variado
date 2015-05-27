/* 
 * File:   figura_revolucion.h
 * Author: jesus
 *
 * Created on 24 de octubre de 2014, 16:55
 */

#ifndef CONO_H
#define	CONO_H
#include <cmath>
#include <iostream>
#include "revolucion.h"

#define PI 3.141592653589793238463
class cono : public revolucion{
public:
    cono();
    cono(float altura,float radio, bool tapa);
};

#endif	/* FIGURA_REVOLUCION_H */


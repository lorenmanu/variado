/* 
 * File:   figura_revolucion.h
 * Author: jesus
 *
 * Created on 24 de octubre de 2014, 16:55
 */

#ifndef CILINDRO_H
#define	CILINDRO_H
#include <cmath>
#include <iostream>
#include "revolucion.h"

#define PI 3.141592653589793238463
class cilindro : public revolucion{
public:
    cilindro();
    cilindro(float altura,float radio, bool tapa_arriba, bool tapa_abajo);
};

#endif	/* FIGURA_REVOLUCION_H */


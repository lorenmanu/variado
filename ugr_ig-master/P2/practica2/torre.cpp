/* 
 * File:   figura_revolucion.cpp
 * Author: jesus
 * 
 * Created on 24 de octubre de 2014, 16:56
 */

#include "torre.h"
    torre::torre(){
        base = figura_revolucion("models/base_torre.ply",true,false);
        cima = figura_revolucion("models/cima_torre.ply",false,true);

    }


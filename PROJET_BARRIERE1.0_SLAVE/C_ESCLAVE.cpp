/* 
 * File:   C_ESCLAVE.cpp
 * Author: TIBO
 * 
 * Created on 8 janvier 2015, 12:42
 */

#include "C_ESCLAVE.h"

void C_ESCLAVE::Init(){
    Mon_Serial = new SoftwareSerial(0, PORT_ENVOI_ESCLAVE);
    Mon_Serial->begin(9600);   
}


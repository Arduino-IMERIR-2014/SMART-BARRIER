/* 
 * File:   C_MAITRE.cpp
 * Author: TIBO
 * 
 * Created on 8 janvier 2015, 11:39
 */

#include "C_MAITRE.h"

void C_MAITRE::Init(){
    Mon_Serial = new SoftwareSerial(0, PORT_ENVOI_ESCLAVE);
    Mon_Serial->begin(9600);   
}
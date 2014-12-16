/* 
 * File:   C_LED.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 09:12
 */

#include "C_LED.h"
#include "Arduino.h"


    
void C_LED::Active(){
    digitalWrite(Index_Entree,HIGH);
}

void C_LED::Desactive(){
    digitalWrite(Index_Entree,LOW);
}
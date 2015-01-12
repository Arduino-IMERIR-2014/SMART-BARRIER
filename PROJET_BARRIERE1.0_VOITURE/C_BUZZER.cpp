/* 
 * File:   C_BUZZER.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 14:41
 */

#include "C_BUZZER.h"
#include "Arduino.h"
    
void C_BUZZER::Active(){
    digitalWrite(Index_Entree,HIGH);
}

void C_BUZZER::Desactive(){
    digitalWrite(Index_Entree,LOW);
}
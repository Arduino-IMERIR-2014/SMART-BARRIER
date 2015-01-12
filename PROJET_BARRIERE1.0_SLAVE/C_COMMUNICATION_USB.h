/* 
 * File:   C_ENVOI_USB.h
 * Author: Ttibo
 *
 * Created on 9 décembre 2014, 16:15
 */

#ifndef C_ENVOI_USB_H
#define	C_ENVOI_USB_H
#include "SoftwareSerial.h"
#include "C_ECRAN.h"
#include "DEFINE.h"

class C_COMMUNICATION_USB {
public : 
#ifdef DEBUG_COM_USB
    inline void Set_Ecran(C_ECRAN* P_Ecran){
        Ecran=P_Ecran;
    }
#endif
    virtual void Init();
    virtual void Envoi(int);
    virtual String Reception();
    
protected : 
#ifdef DEBUG_COM_USB
    C_ECRAN* Ecran;
#endif
    String Message;
    SoftwareSerial* Mon_Serial;
};

#endif	/* C_ENVOI_USB_H */


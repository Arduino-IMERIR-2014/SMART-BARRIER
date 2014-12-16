/* 
 * File:   C_COMMUNICATION_USB_LIRE.h
 * Author: Ttibo
 *
 * Created on 11 décembre 2014, 14:53
 */

#ifndef C_COMMUNICATION_USB_LIRE_H
#define	C_COMMUNICATION_USB_LIRE_H

#include "C_COMMUNICATION_USB.h"


class C_COMMUNICATION_USB_LIRE : public C_THREAD{   
protected:
    void Run();
};

#endif	/* C_COMMUNICATION_USB_LIRE_H */


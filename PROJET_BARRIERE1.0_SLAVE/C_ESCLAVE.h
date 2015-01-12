/* 
 * File:   C_ESCLAVE.h
 * Author: TIBO
 *
 * Created on 8 janvier 2015, 12:42
 */

#ifndef C_ESCLAVE_H
#define	C_ESCLAVE_H
#include "C_COMMUNICATION_USB.h"

class C_ESCLAVE  : public C_COMMUNICATION_USB{
public:
    void Init();

};

#endif	/* C_ESCLAVE_H */


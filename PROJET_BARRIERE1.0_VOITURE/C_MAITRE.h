#ifndef C_MAITRE_H
#define	C_MAITRE_H
#include <Wire.h>
#include <String.h>

#include "C_COMMUNICATION_USB.h"

class C_MAITRE : public C_COMMUNICATION_BLUETOOTH{
public:
    void Init();
};

#endif	/* C_MAITRE_H */


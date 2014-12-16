/* 
 * File:   C_OBJET_SORTIE.h
 * Author: Ttibo
 *
 * Created on 9 décembre 2014, 09:27
 */

#ifndef C_OBJET_SORTIE_H
#define	C_OBJET_SORTIE_H

class C_OBJET_SORTIE {  //classe abstraite
protected:
    int Index_Entree;
    virtual void Init(int);
    virtual void Active()=0;
    virtual void Desactive()=0;

};

#endif	/* C_OBJET_SORTIE_H */


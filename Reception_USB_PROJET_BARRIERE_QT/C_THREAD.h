/* 
 * File:   C_THREAD.h
 * Author: tib
 *
 * Created on 14 novembre 2013, 10:29
 */

#ifndef C_THREAD_H

#define	C_THREAD_H
#include <windows.h>

class C_THREAD {
public:
    C_THREAD();
    static DWORD Fonction_Thread(C_THREAD* P_Info);
    virtual void Run() = 0;
    void Set_affinite(int p_affinite);
    void Demmares_Toi();
    void Set_Priorite(DWORD priorite);
    void Suspend_toi();
    void Synchronise_avec_mort(DWORD time_out = INFINITE);
    ~C_THREAD();
private:

    HANDLE thread;
    DWORD TID;
};

#endif	/* C_THREAD_H */


/* 
 * File:   C_THREAD.cpp
 * Author: tib
 * 
 * Created on 14 novembre 2013, 10:29
 */

#include "C_THREAD.h"
#include <windows.h>
#include <iostream>
#define DEBUG_C_THREAD 0
using namespace std;

C_THREAD::C_THREAD() {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif  
    thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) C_THREAD::Fonction_Thread, this, CREATE_SUSPENDED, &TID);
    if (!thread) throw ("C_THREAD : Erreur CreateThread");
}

void C_THREAD::Set_affinite(int p_affinite) {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif 
    SetThreadAffinityMask(thread, p_affinite);
}

void C_THREAD::Demmares_Toi() {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif 
    ResumeThread(thread);

}

void C_THREAD::Set_Priorite(DWORD p_priorite) {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif 
    SetThreadPriority(thread, p_priorite);
}

void C_THREAD::Suspend_toi() {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif 
    SuspendThread(thread);
}

C_THREAD::~C_THREAD() {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif 
    TerminateThread(thread, 0);
}

void C_THREAD::Synchronise_avec_mort(DWORD time_out) {
    WaitForSingleObject(thread, time_out);
}

DWORD C_THREAD::Fonction_Thread(C_THREAD* P_Objet) {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif 

    P_Objet->Run();
    return 0;
}

void C_THREAD::Run() {
#if DEBUG_C_THREAD > 0
    cerr << __PRETTY_FUNCTION__ << endl;
#endif 

}
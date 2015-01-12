/* 
 * File:   newfile.h
 * Author: Josiane
 *
 * Created on 9 janvier 2015, 11:41
 */
/*#define SFML_STATIC*/
#include "QR_Encode.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>
#include <RectangleShape.hpp>
#include <Text.hpp>
#include <SFML/OpenGL.hpp>
#include <windows.h>


char matrice[50][100];   // matrice contenant le qrcode 
class QR
{
public:
    void init(FILE*);
    void afficher_QR(unsigned char);
};

void generer_QRCODE(char message[150]);
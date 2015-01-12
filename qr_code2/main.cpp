#include "mesfonctions.h"          // rajout de mes fonctions

using namespace std;

int  main(void)
{
    generer_QRCODE("■■■■■■■■■carre■■■■■■■■■");
    return 0;
}

void generer_QRCODE(char message[150])  // ATTENTION: Pas plus de 150 caractère!!!
{

    QR code; // Création d'un objet 'code' de la classe QR 
    setlocale(LC_ALL, "");

    int level = 3; //Ne pas toucher
    int version = 0; // Ne pas toucher

    //rajout de code (Ce n'est pas à l'origine)
    FILE* fp = NULL;
    fp = fopen("qrcode.txt", "w");

    // **** This calls the library and encodes the data
    // *** length is taken from NULL termination, however can also be passed by parameter.
    BYTE QR_m_data[3917]; //max possible bits resolution 177*177/8+1
    int QR_width = EncodeData(3, version,message, 0, QR_m_data);

    
    int size = ((QR_width * QR_width) / 8)+(((QR_width * QR_width) % 8) ? 1 : 0);
    
    // This code dumps the QR code to the screen as ASCII.
    printf("QR Code width: %u\n", QR_width);

    int bit_count = 0;
    printf("%i", size);
    int n;
    for (n = 0; n < size; n++) {
        int b = 0;
        for (b = 7; b >= 0; b--) {

            if ((bit_count % QR_width) == 0) {
                wprintf(L"\n");
                fputc('\n', fp);
            } // Si on se trouve en fin de ligne je fais un saut de ligne
            if (((n + 1)*8) - b > QR_width * QR_width) {
                break;
            } // Si je me trouve à la fin de mon tableau je m'arrête
            if ((QR_m_data[n] & (1 << b)) != 0) {
                wprintf(L"\u2588");
                fputc('x', fp);
                wprintf(L"\u2588");
                fputc('x', fp);
            }// Si mon caractère est différent de 0 je l'inscris dans la fichier Fichier de sortie ( caractère: \u2588 à l'origine)
            else {
                wprintf(L" ");
                fputc(' ', fp);
                wprintf(L" ");
                fputc(' ', fp);
            } // Sinon je fais un espace
            bit_count++;
        }
    }
    wprintf(L"\n");
    code.init(fp);
    code.afficher_QR(QR_width);
}

void QR::init(FILE* fp) {
    int i = 0, j = 0; // affixes des cases de la matrice
    char c; // Variable de type caractÃ¨re
    fclose(fp);
    fp = fopen("qrcode.txt", "r");

    // Ici on test la valeur du caractÃ¨re lu dans le fichier texte
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n' && j < 25) // Si on a une ligne vide
        {
        } else if (c == '\n' && j > 25) // Si on se trouve en fin de ligne
        {
            j = 0;
            i++;
        }
        else {
            matrice[i][j] = c; // Sinon on inscrit directment le caractÃ¨re dans la matrice
            j++;
        }

    }
    fclose(fp);

}

void QR::afficher_QR(unsigned char largeur) // ICI on affichera le QRCODE en fonction de ce qu'il y a dans la matrice 
{
    double x = 0, y = 15;
    int i, j;
    int window_width = 480;
    int window_height = 495;
    double Rect_width = (window_width / (largeur * 2));
    double Rect_height = (window_height - 30) / largeur;
    double init_x = (window_width - Rect_width * largeur * 2) / 2;
    //Affichage de la matrice en console
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 100; j++) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");
    }
    printf("Affichage terminé!!\n"); // Affichage non terminé alors que la fenêtre s'ouvre (Problème à voir)

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), L"QRCODE (Appuyer sur C pour récupérer le QRCODE)");

    sf::RectangleShape rectangle;

    window.clear(sf::Color(255, 255, 255));

    for (i = 0; i < largeur; i++) {
        x = init_x;
        for (j = 0; j < (largeur * 2); j++) {

            if (matrice[i][j] == ' ') {
                rectangle.setFillColor(sf::Color(255, 255, 255));
            } else {
                rectangle.setFillColor(sf::Color(0, 0, 0));
            }

            rectangle.setSize(sf::Vector2f(Rect_width, Rect_height)); // Taille (2.4x4.8)
            rectangle.setPosition(x, y); //Position sur l\'écran");
            window.draw(rectangle);
            x = x + Rect_width;
        }
        y = y + Rect_height;
    }

    window.display();

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                            // Echap
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                            // C
                        case sf::Keyboard::C:
                            sf::Image Ecran;
                            window.display();
                            Ecran = window.capture();
                            window.display();
                            cout<<"saved"<<endl;
                            if (!Ecran.saveToFile("qrcode.jpg")) {
                                cout << "Impossible d'enregistrer l'écran en cours sur le fichier ecran.jpg !" << endl;
                                cout << "Merci de vérifier sa disponibilité !" << endl << endl;
                            }
                            break;
                    }
                    break;
                    // Clic sur la croix
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }



}
#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main () {

    setlocale(LC_ALL, "Portuguese");


    int TURNOSmodoFACIL=10, TURNOSmodoMEDIO=12, TURNOSmodoDIFICIL=14;
    int J0GADASmodoFACIL=4+1, J0GADASmodoMEDIO=5+1, J0GADASmodoDIFICIL=6+1;//+1 é do resultado (pinos pretos e brancos) do jogo.


    char modo_de_jogo;


    do {
        cout << "SELECIONE O MODO DE JOGO: " << endl;
        cin >> modo_de_jogo;
    } while (modo_de_jogo != 'f' && modo_de_jogo != 'm' && modo_de_jogo != 'd');


    system("cls");


    int tabuleiro_modo_facil[TURNOSmodoFACIL][J0GADASmodoFACIL];
    int tabuleiro_modo_medio[TURNOSmodoMEDIO][J0GADASmodoMEDIO];
    int tabuleiro_modo_dificil[TURNOSmodoDIFICIL][J0GADASmodoDIFICIL];


    bool flagFACIL=false, flagMEDIO=false, flagDIFICIL=false;


    if (modo_de_jogo == 'f') {
        flagFACIL=true;
    }

    else if(modo_de_jogo == 'm') {
        flagMEDIO=true;
    }

    else if (modo_de_jogo == 'd') {
        flagDIFICIL=true;
    }


    if (flagFACIL == true) {
        cout << "Master Mind 2017" << endl;

        for (int i=0; i<TURNOSmodoFACIL; i++) {
            for (int j=0; j<J0GADASmodoFACIL; j++) {
                cout << "[ " << " ] ";
            }
            cout << endl;
        }

    }

    else if (flagMEDIO == true) {
        cout << "Master Mind 2017" << endl;

        for (int i=0; i<TURNOSmodoMEDIO; i++) {
            for (int j=0; j<J0GADASmodoMEDIO; j++) {
                cout << "[ " << " ] ";
            }
            cout << endl;
        }

    }

    else if (flagDIFICIL == true) {
        cout << "Master Mind 2017" << endl;

        for (int i=0; i<TURNOSmodoDIFICIL; i++) {
            for (int j=0; j<J0GADASmodoDIFICIL; j++) {
                cout << "[ " << " ] ";
            }
            cout << endl;
        }

    }


    //////////////////////EXECUÇÃO DO JOGO//////////////////////
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~MODO MÉDIO~~~~~~~~~~~~~~~~~~~~~~~//
    if (flagFACIL == true) {

        do {

        } while ();

    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~MODO FÁCIL~~~~~~~~~~~~~~~~~~~~~~~//
    else if (flagMEDIO == true) {

        do {

        } while ();

    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~MODO DIFICIL~~~~~~~~~~~~~~~~~~~~~~//
    else if (flagDIFICIL == true) {

        do {

        } while ();

    }



    return 0;
}

//  projeto de LoP, por Ariel Alsina, Eduarda Vel�ria e Mateus de Assis,
#include<iostream>
#include<stdlib.h> // biblioteca necess�ria para usar o 'limpa tela'
#include <windows.h> //biblioteca necess�ria para usar 'a lentid�o'
#include<locale.h> //usar acentos :P
#include<ctime> // precisa disso para usar o seed
#include <algorithm>//Usar o random_shuffle.

using namespace std;

int main() {


    setlocale(LC_ALL,"Portuguese");   //o setlocale ainda n�o est� pronto!


    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleat�rios)


    //o trecho a seguir representa o inicio de tela:
    char str1[17]= {'P','L','A','Y',' ','M','A','S','T','E','R','M','I','N','D','!','\0'};
    int senha[8]= {0,1,2,3,4,5,6,7};

    int j=0;// essa vari�vel 'j' refere-se � contagem de repeti��es do t�tulo
    char f1; //primeira flag, para voltarmos � tele principal do jogo

    int nivel; // vari�vel que recebe n�vel de dificuldade

    int tamanho=0;//Define o tamaho do vetor_senha.







    //TELA DIVERTIDA
    do {

        for (int i=0; str1[i]!='\0'; i++) {
            cout<<str1[i]<<" ";
            Sleep(100); // esperar 100 milisegundos
        }

        system("cls"); // limpar a tela
        j++;
    } while (j<5);
    //T�RMINO DA TELA DIVERTIDA



    //a partir daqui come�a a intera��o!
    int OPCOES=0; // vari�vel "OPCoES" refere-se a escolha (OPCOES);


    //LOOP DO JOGO
    while(true) {


        //MENU EST�TICO INICIAL
        do {
            cout<<"PLAY MASTERMIND!"<<"  by Duda, TheAssis, @riel"<<endl<<"CHOOSE:"<<endl<<endl;
            cout<<"1 - PLAY NOW!"<<endl<<"2 - INSTRUCTIONS"<<endl<<"3 - EXIT"<<endl<<endl;
            cin>>OPCOES;

            system("cls");

        } while(OPCOES!=1 && OPCOES!=3 && OPCOES!=2);
        //T�RMIN0 MENU EST�TICO INICIAL



        //ESCOLHAS DAS OP��ES DO MENU DADA ESCOLHA NUM�RICA (1,2 OU 3).
        if(OPCOES==1){

            do {
                cout<<"Escolha um n�vel: "<<endl<<"1 - F�cil;"<<endl<<"2 - Intermedi�rio"<<endl<<"3 - Dif�cil."<<endl;
                cin>>nivel;

                system("cls");

            } while (nivel<=0 || nivel>3);


            // o trecho 'switch' seguinte mistura a localiza��o dos valores
            // Tamb�m determina o tamanho do vetor. Funciona assim: se o seu
            // vetor estiver no n�vel "f�cil", o c�digo mistura apenas os 6
            // primeiros valores. Se estiver no n�vel m�dio, as 7 primeiras
            // localiza��es de mem�ria s�o misturadas.Para o dif�cil, todo o
            // vetor � embaralhado.
            // O 'tamanho' criado � a quantidade de pinos que devem ser analisados.
            switch(nivel) {

                case 1:
                    random_shuffle(&senha[0],&senha[6]);
                    tamanho = 4;
                    break;

                case 2:
                    random_shuffle(&senha[0],&senha[7]);
                    tamanho = 5;
                    break;

                case 3:
                    random_shuffle(&senha[0],&senha[8]);
                    tamanho = 6;
                    break;

            }

            int senha_usuario[tamanho];
            char vetor_resposta[tamanho];


        }
        //T�RMINO DAS ESCOLHAS DAS OP��ES DO MENU DADA ESCOLHA NUM�RICA (1,2 OU 3).



        //TELA DE INSTRU��ES;
        if(OPCOES==2) {

            cout<<"Seja bem vindo ao Mastermind! Sua tarefa e descobrir uma senha em cores que foi criada aleatoriamente. Para isso, voce deve gerar palpites ate acertar. A cada "<<endl;
            cout<<"palpite de senha dada, voce tera como resposta uma quantidade de pinos brancos "<<endl;
            cout<<"e pretos. O pino de cor branca representa uma cor colocada exatamente no canto"<<endl;
            cout<<"correto, enquanto que os pinos pretos sao distribuidos quando uma cor colocada"<<endl;
            cout<<"esta na senha, porem na posicao errada. "<<endl;
            cout<<endl<<"PARA RETORNAR � TELA INICIAL, DIGITE ALGO E CLIQUE [ENTER]: ";
            cin>>f1;
            system("cls");
        }//TELA DE INSTRU��ES;



        //SAIR DO JOGO
        if (OPCOES==3)  {

            break; //sa�da do loop.

        }
        // T�RMINO DE SAIR DO JOGO

    }
    //T�RMINO DO LOOP DO JOGO



    //CR�DITOS
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<< endl << endl << "Thank you for playing MASTERMIND"<<endl<<"      by Ariel Alsina, Eduarda Val�ria e Mateus de Assis."<<endl;//tela de finaliza��o
    //T�RMINO DOS CR�DITOS.



    return 0;
}

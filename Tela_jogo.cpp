//  projeto de LoP, por Ariel Alsina, Eduarda Veléria e Mateus de Assis,
#include<iostream>
#include<stdlib.h> // biblioteca necessária para usar o 'limpa tela'
#include <windows.h> //biblioteca necessária para usar 'a lentidão'
#include<locale.h> //usar acentos :P
#include<ctime> // precisa disso para usar o seed
#include <algorithm>//Usar o random_shuffle.

using namespace std;

int main() {


    setlocale(LC_ALL,"Portuguese");   //o setlocale ainda não está pronto!


    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleatórios)


    //o trecho a seguir representa o inicio de tela:
    char str1[17]= {'P','L','A','Y',' ','M','A','S','T','E','R','M','I','N','D','!','\0'};
    int senha[8]= {0,1,2,3,4,5,6,7};

    int j=0;// essa variável 'j' refere-se à contagem de repetições do título
    char f1; //primeira flag, para voltarmos à tele principal do jogo

    int nivel; // variável que recebe nível de dificuldade

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
    //TÉRMINO DA TELA DIVERTIDA



    //a partir daqui começa a interação!
    int OPCOES=0; // variável "OPCoES" refere-se a escolha (OPCOES);


    //LOOP DO JOGO
    while(true) {


        //MENU ESTÁTICO INICIAL
        do {
            cout<<"PLAY MASTERMIND!"<<"  by Duda, TheAssis, @riel"<<endl<<"CHOOSE:"<<endl<<endl;
            cout<<"1 - PLAY NOW!"<<endl<<"2 - INSTRUCTIONS"<<endl<<"3 - EXIT"<<endl<<endl;
            cin>>OPCOES;

            system("cls");

        } while(OPCOES!=1 && OPCOES!=3 && OPCOES!=2);
        //TÉRMIN0 MENU ESTÁTICO INICIAL



        //ESCOLHAS DAS OPÇÕES DO MENU DADA ESCOLHA NUMÉRICA (1,2 OU 3).
        if(OPCOES==1){

            do {
                cout<<"Escolha um nível: "<<endl<<"1 - Fácil;"<<endl<<"2 - Intermediário"<<endl<<"3 - Difícil."<<endl;
                cin>>nivel;

                system("cls");

            } while (nivel<=0 || nivel>3);


            // o trecho 'switch' seguinte mistura a localização dos valores
            // Também determina o tamanho do vetor. Funciona assim: se o seu
            // vetor estiver no nível "fácil", o código mistura apenas os 6
            // primeiros valores. Se estiver no nível médio, as 7 primeiras
            // localizações de memória são misturadas.Para o difícil, todo o
            // vetor é embaralhado.
            // O 'tamanho' criado é a quantidade de pinos que devem ser analisados.
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
        //TÉRMINO DAS ESCOLHAS DAS OPÇÕES DO MENU DADA ESCOLHA NUMÉRICA (1,2 OU 3).



        //TELA DE INSTRUÇÕES;
        if(OPCOES==2) {

            cout<<"Seja bem vindo ao Mastermind! Sua tarefa e descobrir uma senha em cores que foi criada aleatoriamente. Para isso, voce deve gerar palpites ate acertar. A cada "<<endl;
            cout<<"palpite de senha dada, voce tera como resposta uma quantidade de pinos brancos "<<endl;
            cout<<"e pretos. O pino de cor branca representa uma cor colocada exatamente no canto"<<endl;
            cout<<"correto, enquanto que os pinos pretos sao distribuidos quando uma cor colocada"<<endl;
            cout<<"esta na senha, porem na posicao errada. "<<endl;
            cout<<endl<<"PARA RETORNAR À TELA INICIAL, DIGITE ALGO E CLIQUE [ENTER]: ";
            cin>>f1;
            system("cls");
        }//TELA DE INSTRUÇÕES;



        //SAIR DO JOGO
        if (OPCOES==3)  {

            break; //saída do loop.

        }
        // TÉRMINO DE SAIR DO JOGO

    }
    //TÉRMINO DO LOOP DO JOGO



    //CRÉDITOS
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<< endl << endl << "Thank you for playing MASTERMIND"<<endl<<"      by Ariel Alsina, Eduarda Valéria e Mateus de Assis."<<endl;//tela de finalização
    //TÉRMINO DOS CRÉDITOS.



    return 0;
}

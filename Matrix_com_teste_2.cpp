// Esse c�digo � a Matrix_com_teste_versao_2. Ele printa a matriz em loop. Tamb�m � respons�vel por analisar
// a senha digitada pelo usu�rio. Dependendo da an�lise, � demonstrado o vetor resposta organizado. Falta
// ainda organizar de forma que as respostas anteriores v�o sendo salvas e o vetor resposta aparece apenas
// no momento certo. Tamb�m organizei e comentei XD

// Ele tamb�m � respons�vel por criar uma matriz_resposta (o vetor_resposta j� n�o mais existe). Essa matriz
// guarda os acertos do jogador de forma que suas linhas representam os turnos que v�o ocorrendo. O jogo, a
// partir dessa vers�o, roda em turnos. As jogadas que v�o sendo realizadas v�o sendo mostradas e os vetores
// respostas tamb�m XD. O comando "turnos-k-1", basicamente, te p�e na altura certa.


#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <algorithm> //precisa disso para usar o random_shuffle
#include <ctime> // precisa disso para usar o seed
#include <windows.h> //biblioteca necess�ria para usar 'a lentid�o'

using namespace std;

int main () {

    setlocale(LC_ALL, "Portuguese");
    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleat�rios)


    //DECLARA��O DO VETOR SENHA QUE SER� EMBARALHADA
    int senha[8]= {0,1,2,3,4,5,6,7};
    // FIM DA DECLARA��O DO VETOR SENHA QUE SER� EMBARALHADA

    //O NIVEL DE DIFICULDADE DO JOGO,
    //A QUANTIDADE DE TURNOS EXISTENTE,
    //A QUANTIDADE DE PINOS QUE O USU�RIO PODE MEXER,
    //O TAMANHO M�XIMO DE SENHA.
    //TUDO DECLARADO NA PR�XIMA LINHA:
    int nivel,turnos,pinos,tamanho;

    //ESCOLHA DO N�VEL DE DIFICULDADE
    do {

        cout<<"Escolha um n�vel: "<<endl<<"1 - F�cil;"<<endl<<"2 - Intermedi�rio"<<endl<<"3 - Dif�cil."<<endl;
        cin>>nivel;

        system("cls");

    } while (nivel<=0 || nivel>3);
    //FIM DA ESCOLHA DO N�VEL DE DIFICULDADE

    //ABAIXO SE DEFINEM A QUANTIDADE DE PINOS QUE PODEM SER MEXIDOS, OS TURNOS EXISTENTE E O TAMANHO DA SENHA E A PR�PRIA SENHA.
    switch(nivel) {

        case 1:
            pinos = 4;
            turnos = 10;
            tamanho=pinos;
            random_shuffle(&senha[0],&senha[6]);
            break;

        case 2:
            pinos = 5;
            turnos = 12;
            tamanho=pinos;
            random_shuffle(&senha[0],&senha[7]);
            break;

        case 3:
            pinos = 6;
            turnos = 14;
            tamanho=pinos;
            random_shuffle(&senha[0],&senha[8]);
            break;
    }
    //TERMINOS DAS DEFINI��ES: TAMANHO DE/E SENHA, QUANTIDADES DE TURNOS E PINOS.


    //VETOR SENHA QUE O USUARIO VAI DIGITAR
    int senha_usuario[tamanho];
    //VETOR SENHA QUE O USUARIO VAI DIGITAR

    //MATRIZ QUE GERA A AN�LISE DO SISTEMA
    char matriz_resposta[turnos][pinos];
    //MATRIZ QUE GERA A AN�LISE DO SISTEMA

    //DEFINI��O DO TABULEIRO DO JOGO, O QUAL DEVE RECEBER AS SENHAS
    int tabuleiro[turnos][pinos];

    //LIMPANDO O TABULEIRO
        for(int j=0; j<pinos;j++){
            for(int i=0; i<turnos;i++){
                tabuleiro[i][j]=0;
                matriz_resposta[i][j]='?';
            }
    }
    //FIM DA 'LIMPEZA' DO TABULEIRO.


    //LIMPAR A TELA
    system("cls");

           //MOSTRANDO A MATRIZ 'TURNOS' VEZES, ISTO �, A JOGABILIDADE EM SI.
        for(int k=0;k<turnos;k++){

         cout << "Master Mind 2017" << endl;

        for (int i=0; i<turnos; i++) {

            //PRINTANDO A MATRIZ TABULEIRO
            for (int j=0; j<pinos; j++) {
                cout << "[ " << tabuleiro[i][j] << " ] ";
            }
            //FIM DO 'PRINTANDO A MATRIZ TABULEIRO'


            //MOSTRAR A AN�LISE DA SENHA
            for(int j=0;j<pinos;j++){
                cout<<matriz_resposta[i][j];
            }
            //MOSTRAR A AN�LISE DA SENHA

            //APARECER O TURNO CORRENTE
            cout << "|   " << turnos-i <<"� jogada";
            cout << endl;
            //FIM DA EXPLICITA��O DO TURNO CORRENTE.

        }
        //FIM DO PRINT DA MATRIZ DO JOGO

        //PEDIR QUE O USU�RIO DIGITE A SENHA:
        cout << endl<< "Digite sua senha: " << endl;

        //DIGITANTO CADA VALOR
        for(int i=0; i<tamanho; i++) {
            cout<<"Posi��o "<<i<<" : ";
            cin>>senha_usuario[i];
            tabuleiro[turnos-1-k][i]= senha_usuario[i];
            }
        //FIM DA INSER��O DE CADA VALOR.

            //CONFIRMA��O DA SENHA DO USU�RIO
        for(int i=0; i<tamanho; i++) {
          for(int j=0; j<tamanho; j++) {
            if(senha[i]==senha_usuario[j] && i==j){
              matriz_resposta[turnos-1-k][i]='b';
              break;
                }
            else if (senha[i]==senha_usuario[j] && i!=j) {
              matriz_resposta[turnos-1-k][i]='p';
              break;
                }
            else {
              matriz_resposta[turnos-1-k][i]='p';
                }
            }
        }
    //T�RMINO DA CONFIRMA��O DA SENHA DO USU�RIO


    // ORGANIZA��O DO VETOR RESPOSTA.
    // a vari�vel aux � um intemediario na organiza��o do vetor.
    char aux;

    for(int j=0; j<tamanho-1; j++) {
        for(int i =0; i<tamanho-1; i++) {
            if( matriz_resposta[turnos-1-k][i]=='p'&& matriz_resposta[turnos-1-k][i+1]=='b'){
                aux=matriz_resposta[turnos-1-k][i];
                matriz_resposta[turnos-1-k][i]=matriz_resposta[turnos-1-k][i+1];
                matriz_resposta[turnos-1-k][i+1]=aux;
            }
        }
    }
    //FIM DA ORGANIZA��O DO VETOR RESPOSTA.

        //LIMPAR TELA
        system("cls");
        //FIM DO LIMPAR TELA
        }
}

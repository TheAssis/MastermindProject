// Esse c�digo � a Matrix_com_teste_versao_1. Ele printa a matriz em loop. Tamb�m � respons�vel por analisar
// a senha digitada pelo usu�rio. Dependendo da an�lise, � demonstrado o vetor resposta organizado. Falta
// ainda organizar de forma que as respostas anteriores v�o sendo salvas e o vetor resposta aparece apenas
// no momento certo. Tamb�m organizei e comentei XD

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

    //VETOR QUE GERA A AN�LISE DO SISTEMA
    char vetor_resposta[tamanho];
    //VETOR QUE GERA A AN�LISE DO SISTEMA

    //DEFINI��O DO TABULEIRO DO JOGO, O QUAL DEVE RECEBER AS SENHAS
    int tabuleiro[turnos][pinos];

    //LIMPANDO O TABULEIRO
        for(int j=0; j<pinos;j++){
            for(int i=0; i<turnos;i++){
                tabuleiro[i][j]=0;
            }
    }
    //FIM DA 'LIMPEZA' DO TABULEIRO.

    //LIMPEZA DO VETOR RESPOSTA
    for(int i =0; i<tamanho;i++){
        vetor_resposta[i]='?';
    }
    //FIM DA LIMPEZA DO VETOR RESPOSTA

    //LIMPAR A TELA
    system("cls");

    cout << "Master Mind 2017" << endl;

        //MOSTRANDO A MATRIZ
        while(true){

        for (int i=0; i<turnos; i++) {
            for (int j=0; j<pinos; j++) {
                cout << "[ " << tabuleiro[i][j] << " ] ";
            }
            //MOSTRAR A AN�LISE DA SENHA
            for(int j=0; j<tamanho; j++) {
                cout<<vetor_resposta[j]<<"  ";
            }
            //FIM DO MOSTRAR A AN�LISE DA SENHA

            //APARECER O TURNO CORRENTE
            cout << "|   " << turnos-i <<"� jogada";
            cout << endl;
            //FIM DA EXPLICITA��O DO TURNO CORRENTE.

        }
        //FIM DO PRINT DA MATRIZ

        //PEDIR QUE O USU�RIO DIGITE A SENHA:
        cout << endl<< "Digite sua senha: " << endl;

        //DIGITANTO CADA VALOR
        for(int i=0; i<tamanho; i++) {
            cout<<"Posi��o "<<i<<" : ";
            cin>>senha_usuario[i];
            }
        //FIM DA INSER��O DE CADA VALOR.

            //CONFIRMA��O DA SENHA DO USU�RIO
        for(int i=0; i<tamanho; i++) {
          for(int j=0; j<tamanho; j++) {
            if(senha[i]==senha_usuario[j] && i==j){
              vetor_resposta[i]='b';
              break;
                }
            else if (senha[i]==senha_usuario[j] && i!=j) {
              vetor_resposta[i]='p';
              break;
                }
            else {
              vetor_resposta[i]='p';
                }
            }
        }
    //T�RMINO DA CONFIRMA��O DA SENHA DO USU�RIO


    // ORGANIZA��O DO VETOR RESPOSTA.
    // a vari�vel aux � um intemediario na organiza��o do vetor.
    char aux;

    for(int j=0; j<tamanho-1; j++) {
        for(int i =0; i<tamanho-1; i++) {
            if(vetor_resposta[i]=='p' && vetor_resposta[i+1]=='b') {
                aux=vetor_resposta[i];
                vetor_resposta[i]=vetor_resposta[i+1];
                vetor_resposta[i+1]=aux;
            }
        }
    }
    //FIM DA ORGANIZA��O DO VETOR RESPOSTA.

        //LIMPAR TELA
        system("cls");
        //FIM DO LIMPAR TELA
        }
}

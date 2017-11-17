// Esse código é a Matrix_com_teste_versao_2. Ele printa a matriz em loop. Também é responsável por analisar
// a senha digitada pelo usuário. Dependendo da análise, é demonstrado o vetor resposta organizado. Falta
// ainda organizar de forma que as respostas anteriores vão sendo salvas e o vetor resposta aparece apenas
// no momento certo. Também organizei e comentei XD

// Ele também é responsável por criar uma matriz_resposta (o vetor_resposta já não mais existe). Essa matriz
// guarda os acertos do jogador de forma que suas linhas representam os turnos que vão ocorrendo. O jogo, a
// partir dessa versão, roda em turnos. As jogadas que vão sendo realizadas vão sendo mostradas e os vetores
// respostas também XD. O comando "turnos-k-1", basicamente, te põe na altura certa.


#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <algorithm> //precisa disso para usar o random_shuffle
#include <ctime> // precisa disso para usar o seed
#include <windows.h> //biblioteca necessária para usar 'a lentidão'

using namespace std;

int main () {

    setlocale(LC_ALL, "Portuguese");
    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleatórios)


    //DECLARAÇÃO DO VETOR SENHA QUE SERÁ EMBARALHADA
    int senha[8]= {0,1,2,3,4,5,6,7};
    // FIM DA DECLARAÇÃO DO VETOR SENHA QUE SERÁ EMBARALHADA

    //O NIVEL DE DIFICULDADE DO JOGO,
    //A QUANTIDADE DE TURNOS EXISTENTE,
    //A QUANTIDADE DE PINOS QUE O USUÁRIO PODE MEXER,
    //O TAMANHO MÁXIMO DE SENHA.
    //TUDO DECLARADO NA PRÓXIMA LINHA:
    int nivel,turnos,pinos,tamanho;

    //ESCOLHA DO NÍVEL DE DIFICULDADE
    do {

        cout<<"Escolha um nível: "<<endl<<"1 - Fácil;"<<endl<<"2 - Intermediário"<<endl<<"3 - Difícil."<<endl;
        cin>>nivel;

        system("cls");

    } while (nivel<=0 || nivel>3);
    //FIM DA ESCOLHA DO NÍVEL DE DIFICULDADE

    //ABAIXO SE DEFINEM A QUANTIDADE DE PINOS QUE PODEM SER MEXIDOS, OS TURNOS EXISTENTE E O TAMANHO DA SENHA E A PRÓPRIA SENHA.
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
    //TERMINOS DAS DEFINIÇÕES: TAMANHO DE/E SENHA, QUANTIDADES DE TURNOS E PINOS.


    //VETOR SENHA QUE O USUARIO VAI DIGITAR
    int senha_usuario[tamanho];
    //VETOR SENHA QUE O USUARIO VAI DIGITAR

    //MATRIZ QUE GERA A ANÁLISE DO SISTEMA
    char matriz_resposta[turnos][pinos];
    //MATRIZ QUE GERA A ANÁLISE DO SISTEMA

    //DEFINIÇÃO DO TABULEIRO DO JOGO, O QUAL DEVE RECEBER AS SENHAS
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

    //MOSTRANDO A MATRIZ 'TURNOS' VEZES, ISTO É, A JOGABILIDADE EM SI.
    for(int k=0;k<turnos;k++){

        cout << "Master Mind 2017" << endl;

        for (int i=0; i<turnos; i++) {

            //PRINTANDO A MATRIZ TABULEIRO
            for (int j=0; j<pinos; j++) {
                cout << "[ " << tabuleiro[i][j] << " ] ";
            }
            //FIM DO 'PRINTANDO A MATRIZ TABULEIRO'


            //MOSTRAR A ANÁLISE DA SENHA
            for(int j=0;j<pinos;j++){
                cout<<matriz_resposta[i][j];
            }
            //MOSTRAR A ANÁLISE DA SENHA

            //APARECER O TURNO CORRENTE
            cout << "|   " << turnos-i <<"ª jogada";
            cout << endl;
            //FIM DA EXPLICITAÇÃO DO TURNO CORRENTE.

        }
        //FIM DO PRINT DA MATRIZ DO JOGO

        //PEDIR QUE O USUÁRIO DIGITE A SENHA:
        cout << endl<< "Digite sua senha: " << endl;

        //DIGITANTO CADA VALOR
        for(int i=0; i<tamanho; i++) {
            cout<<"Posição "<<i<<" : ";
            cin>>senha_usuario[i];
            tabuleiro[turnos-1-k][i]= senha_usuario[i];
        }
        //FIM DA INSERÇÃO DE CADA VALOR.

        //CONFIRMAÇÃO DA SENHA DO USUÁRIO
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
        //TÉRMINO DA CONFIRMAÇÃO DA SENHA DO USUÁRIO


        // ORGANIZAÇÃO DO VETOR RESPOSTA (para que os pinos brancos venham antes dos pinos pretos).
        // a variável aux é um intemediario na organização do vetor.
        char aux;

        for(int j=0; j<tamanho-1; j++) {                                    //(tamanho-1) = Porque como comparamos i com (i+1), não podemos incrementar
            for(int i =0; i<tamanho-1; i++) {                               //              até tamanho.
                if( matriz_resposta[turnos-1-k][i]=='p'&& matriz_resposta[turnos-1-k][i+1]=='b'){
                    aux=matriz_resposta[turnos-1-k][i];
                    matriz_resposta[turnos-1-k][i]=matriz_resposta[turnos-1-k][i+1];
                    matriz_resposta[turnos-1-k][i+1]=aux;
                }
            }
        }
        //FIM DA ORGANIZAÇÃO DO VETOR RESPOSTA.

        //LIMPAR TELA
        system("cls");
        //FIM DO LIMPAR TELA
    }
}

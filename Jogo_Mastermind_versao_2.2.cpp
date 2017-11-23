//  projeto de LoP, por Ariel Alsina, Eduarda Val�ria e Mateus de Assis.

//O SEGUINTE ALGORITMO POSSUI A JOGABILIDASDE COMPLETA. ELE MOSTRA UMA TELA INICIAL, PEDE OS NOMES DOS JOGADORES E RODA O JOGO DA SENHA.

#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <algorithm> //precisa disso para usar o random_shuffle
#include <ctime> // precisa disso para usar o seed
#include <windows.h> //biblioteca necess�ria para usar 'a lentid�o'

using namespace std;

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleat�rios)

    //DECLARA��O DO VETOR SENHA QUE SER� EMBARALHADA
    int senha[8]= {0,1,2,3,4,5,6,7};
    // FIM DA DECLARA��O DO VETOR SENHA QUE SER� EMBARALHADA


    //A QUANTIDADE DE TURNOS EXISTENTE,
    //A QUANTIDADE DE PINOS QUE O USU�RIO PODE MEXER,
    //O TAMANHO M�XIMO DE SENHA.
    //TUDO DECLARADO NA PR�XIMA LINHA:
    int turnos,pinos,tamanho;

    //DECLARA��O DA VARI�VEL QUE GUARDA O N�VEL ESCOLHIDO.
    char nivel;
    // FIM DA DECLARA��O DA VARI�VEL QUE GUARDA O N�VEL ESCOLHIDO.

    //DECLARA��O DA VARI�VEL QUE GUARDA A QUANTIDADE DE JOGADORES
    char quantidade_de_jogadores=0;
    //FIM DA DECLARA��O DA VARI�VEL QUE GUARDA A QUANTIDADE DE JOGADORES

    // DECLARA��O DE STRING QUE GUARDA OS NOMES DOS JOGADORES
    char jogador1[6];
    char jogador2[6];
    // FIM DA DECLARA��O DE STRING QUE GUARDA OS NOMES DOS JOGADORES


    // AS SEGUNITES DECLARA��ES DE VARI�VEIS SEVEM PARA GERAR A ANIMA��O-T�TULO. A STRING 'T�TULO' GUARDA
    // O T�TULO A SER ANIMADO, ENQUANTO QUE A VARI�VEL 'J' GUARDA A QUANTIDADE DE VEZES QUE TAL T�TULO SER�
    // REPETIDO.
    char titulo[17]={'P','L','A','Y',' ','M','A','S','T','E','R','M','I','N','D','!','\0'};
    int j=0;
    //FIM DAS DECLARA��ES DAS VARI�VEIS NECESS�RIAS PARA A ANIMA��O T�TULO

    // A VARI�VEL F1 � NECESS�RIA PARA O RETORNO � TELA PRINCIPAL DO JOGO
    char f1;
    // FIM DA DECLARA��O DE F1.

    //O SEGUINTE TRECHO DE C�DIGO ANIMA O T�TULO
    do{
        for (int i=0; titulo[i]!='\0';i++){
            cout<<titulo[i]<<" ";
            Sleep(100); // esperar 100 milisegundos
        }
        system("cls"); // limpar a tela
        j++;
    }while (j<5);
    //FIM DA ANIMA��O DO T�TULO

    // VARI�VEL 'c' GUARDA A ESCOLHA DO MENU
    int c=0;
    //FIM DA DECLARA��O DA VARI�VEL C

    //O SEGUINTE TRECHO DE C�DIGO PERMITE QUE O JOGO 'RODE'.
    while(true){ // esse comando � para criar um loop

        // O SEGUINTE TRECHO DE C�DIGO � RESPONS�VEL POR CRIAR UMA TELA DE MENU EST�TICA.
        do{
            cout<<"PLAY MASTERMIND!"<<"  by Duda, TheAssis, @riel"<<endl<<"CHOOSE:"<<endl<<endl;
            cout<<"1 - PLAY NOW!"<<endl<<"2 - INSTRUCTIONS"<<endl<<"3 - EXIT"<<endl<<endl;
            cin>>c;
            system("cls");
         }while(c!=1&&c!=3&&c!=2);
         //FIM DA TELA EST�TICA DO MENU.

         //O SEGUINTE TRECHO DE C�DIGO � RESPONS�VEL PELA SEQU�NCIA DE TELAS RESPONS�VEIS PELO JOGO EM SI.
         if(c==1){

            //SELECIONANDO O MODO DE JOGO (Single ou Multiplayer)
            do{
                cout<<"Selecione um modo: "<<endl<<"1 - Single."<<endl<<"2 - Multiplayer."<<endl<<"ESCOLHA: ";
                cin>>quantidade_de_jogadores;
                system("cls");
            }while(quantidade_de_jogadores !='1' && quantidade_de_jogadores!='2');
            //FIM DA SELE��O DO MODO DE JOGO (Single ou Multiplayer)

            //DECLARA��O DO NOME DO PRIMEIRO JOGADOR:
            //VALIDANDO QUANTIDADE DE D�GITOS NO NOME
            do{
                cout << "Digite nome de jogador (at� 5 digitos): "<<endl;
                cin>> jogador1;
                system ("cls");
            }while(jogador1[5]!='\0'&& jogador1[4]!='\0' &&  jogador1[3]!='\0' &&  jogador1[2]!='\0' && jogador1[1]!='\0');
            //FIM DA VALIDA��O DE D�GITOS NO NOME
            //FIM DA DECLARA��O DO NOME DO PRIMEIRO JOGADOR.

            //DECLARA��O DO NOME DO SEGUNDO JOGADOR:
            if (quantidade_de_jogadores==2){

                //VALIDANDO QUANTIDADE DE D�GITOS NO NOME
                do{
                    cout << "Digite o nome do segundo jogador (at� 5 digitos): "<<endl;
                    cin>> jogador2;
                    system ("cls");
                }while(jogador2[5]!='\0'&& jogador2[4]!='\0' &&  jogador2[3]!='\0' &&  jogador2[2]!='\0' && jogador2[1]!='\0');
                //FIM DA VALIDA��O DE D�GITOS NO NOME

            }
            // FIM DA DECLARA��O DO NOME DO SEGUNDO JOGADOR.

            //ESCOLHA DO N�VEL DE DIFICULDADE (F�cil, M�dio ou Intermedi�rio)
            do {

                cout<<"Escolha um n�vel: "<<endl<<"1 - F�cil;"<<endl<<"2 - Intermedi�rio"<<endl<<"3 - Dif�cil."<<endl;
                cin>>nivel;

                system("cls");

            } while (nivel!='1' && nivel!='2' && nivel!='3' );
            //ESCOLHA DO N�VEL DE DIFICULDADE (F�cil, M�dio ou Intermedi�rio)

            //ABAIXO SE DEFINEM A QUANTIDADE DE PINOS QUE PODEM SER MEXIDOS, OS TURNOS EXISTENTE E O TAMANHO DA SENHA E A PR�PRIA SENHA.
            switch(nivel) {

                case '1':
                    pinos = 4;
                    turnos = 10;
                    tamanho=pinos;
                    random_shuffle(&senha[0],&senha[6]);
                    break;

                case '2':
                    pinos = 5;
                    turnos = 12;
                    tamanho=pinos;
                    random_shuffle(&senha[0],&senha[7]);
                    break;

                case '3':
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
            //FIM DA DEFINI��O DO TABULEIRO DO JOGO

            //MUDAN�A DE JOGADORES OCORREM DEVIDO AO SEGUINTE FOR:
           for(int vez=0; vez<quantidade_de_jogadores; vez++){

                //LIMPANDO O TABULEIRO
                for(int j=0; j<pinos;j++){
                    for(int i=0; i<turnos;i++){
                        tabuleiro[i][j]=0;
                        matriz_resposta[i][j]='?';
                        }
                }
                //FIM DA 'LIMPEZA' DO TABULEIRO.

                //VARI�VEL GANHAR INDICA QUANDO O JOGADOR GANHOU
                bool ganhar=false;
                //FIM DA DECLARA��O DA VARI�VEL ganhar

                //VETOR PONTOS FAZ A GONTAGEM DA PONTUA��O
                int pontos[2]={0,0};
                //FIM DA DECLARA��O DO VETOR QUE FAZ A CONTAGEM DE PONTOS.

                //LIMPAR A TELA
                system("cls");

                //MOSTRANDO A MATRIZ 'TURNOS' VEZES, ISTO �, A JOGABILIDADE EM SI.
                for(int k=0;k<turnos;k++){

                    //DESCOBRINDO SE O JOGADOR GANHOU
                    if(ganhar==true){
                        break;
                    }
                    //FIM DO TESTE DE 'O JOGADOR GANHOU?'.

                    cout << "Master Mind 2017.          VEZ DE "; // 3 tabs

                    //INTERA��O COM O USU�RIO
                    if(vez==0){
                        cout<<jogador1<<endl;
                    }
                    if(vez==1){
                        cout<<jogador2<<endl;
                    }
                    //INTERA��O COM O USU�RIO



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

                        //SALVANDO O D�GITO DIGITADO
                        tabuleiro[turnos-1-k][i]= senha_usuario[i];
                        //FIM DO REGISTRO DO D�GITO DIGITADO
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
                                matriz_resposta[turnos-1-k][i]=' ';
                            }
                        }
                    }
                    //T�RMINO DA CONFIRMA��O DA SENHA DO USU�RIO


                    // ORGANIZA��O DO VETOR RESPOSTA (para que os pinos brancos venham antes dos pinos pretos).
                    // a vari�vel aux � um intemediario na organiza��o do vetor.
                    char aux;

                    for(int j=0; j<tamanho-1; j++) {                                    //(tamanho-1) = Porque como comparamos i com (i+1), n�o podemos incrementar
                        for(int i =0; i<tamanho-1; i++) {                               //              at� tamanho.
                            if( matriz_resposta[turnos-1-k][i]=='p'&& matriz_resposta[turnos-1-k][i+1]=='b'){
                                aux=matriz_resposta[turnos-1-k][i];
                                matriz_resposta[turnos-1-k][i]=matriz_resposta[turnos-1-k][i+1];
                                matriz_resposta[turnos-1-k][i+1]=aux;
                            }
                            if( matriz_resposta[turnos-1-k][i]==' '&& matriz_resposta[turnos-1-k][i+1]=='b'){
                                aux=matriz_resposta[turnos-1-k][i];
                                matriz_resposta[turnos-1-k][i]=matriz_resposta[turnos-1-k][i+1];
                                matriz_resposta[turnos-1-k][i+1]=aux;
                            }
                            if( matriz_resposta[turnos-1-k][i]==' '&& matriz_resposta[turnos-1-k][i+1]=='p'){
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

                    //O SEGUINTE TRECHO DE C�DIGO � RESPONS�VEL POR DESCOBRIR SE O VETOR RESPOSTA � COMPOSTO POR TERMOS 'b'
                    for(int i=0;i<tamanho;i++){
                        if(matriz_resposta[turnos-1-k][i]!=' ' && matriz_resposta[turnos-1-k][i]!='p'){
                            ganhar=true;
                        }
                        else if(matriz_resposta[turnos-1-k][i]==' ' || matriz_resposta[turnos-1-k][i]=='p'){
                            ganhar=false;
                            break;
                        }
                    }
                    //FIM DO C�DIGO QUE � RESPONS�VEL POR DESCOBRIR SE O VETOR RESPOSTA � COMPOSTO POR TERMOS 'b'

                    //DEFINI��O DA PONTUA��O DO JOGADOR
                    pontos[vez]=turnos-k;
                    //FIM DA DEFINI��O DA PONTUA��O DO JOGADOR.

                //AQUI TERMINA O C�DIGO RESPONS�VEL PELO JOGO EM SI
                }

                //O SEGUINTE TRECHO MOSTRA A TELA FINAL DO JOGO.

                //LIMPANDO A TELA
                system("cls");
                //FIM DA LIMPEZA DE TELA.

                //INTERA��O COM O USU�RIO
                if(vez==0){
                    cout<<jogador1;
                }
                if(vez==1){
                    cout<<jogador2;
                }
                //INTERA��O COM O USU�RIO

                if(ganhar==true){
                    //MOSTRANDO A MENSAGEM DA VIT�RIA E A PONTUA��O
                    cout<<", voc� Ganhou! Sua pontua��o � de: "<<pontos[vez]<<" pontos!"<<endl;
                    //FIM DO MOSTRAR A VITORIA E A PONTUA��O
                }
                //TELA DA DERROTA
                else if(ganhar==false){
                    //MOSTRANDO A MENSAGEM DE DERROTA.
                    pontos[vez]=0;
                    cout<<", voc� perdeu por limite de jogadas! Sua pontua��o � de 0 pontos!"<<endl;
                    //FIM DA MENSAGEM DE DERROTA.
                }

                //PRINTANDO O TABULEIRO FINAL
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
                //FIM DO PRINT DA TABULEIRO FINAL.

                //MOSTRANDO A SENHA AO FINAL DO JOGO.
                cout<<endl<<"A senha era: ";
                for(int j=0;j<pinos;j++){
                        cout<<senha[j];
                    }
                cout<<endl;
                // FIM DA DEMONSTRA��O DA SENHA

                //ESSA VARI�VEL � S� PRA CRIAR A PAUSA ENTRE OS TURNOS
                    char start[15];
                //FIM DA DECLARA��O DA VARI�VEL PARA AJUDAR A PAUSA

                //PROCEDIMENTO PARA RETORNAR � TELA INICIAL, CASO HOUVER APENAS UM JOGADOR
                if(quantidade_de_jogadores==1){
                    //PROCEDIMENTO PARA RETORNAR � TELA INICIAL
                    cout<<"Digite algo para voltar � tela inicial: "<<endl;
                    cin>>start;
                    system("cls");
                    //FIM DO PROCEDIMENTO PARA RETORNAR � TELA INICIAL
                }
                //PROCEDIMENTO PARA RETORNAR � TELA INICIAL, CASO HOUVER APENAS UM JOGADOR

                //� PRECISO EMBARALHAR A SENHA UMA VEZ MAIS
                random_shuffle(&senha[0],&senha[pinos+2]);
                //FIM DO NOVO EMBARALHAMENTO

                //INTERA��ES
                if(quantidade_de_jogadores==2){

                    if(vez==0){
                        cout<<endl<<jogador2<<"...se estiver preparado, digite algo para come�armos seu turno!"<<endl<<"RESPOSTA: ";
                        cin>>start;
                    }
                    // FIM DA PAUSA ENTRE TURNOS

                     //O SEGUINTE TRECHO MOSTRA O PLACAR E O GRANDE VENCEDOR
                    else if(vez==1){
                        cout<<endl<<"Digitem algo se estiverem preparados para o placar!"<<endl<<"RESPOSTA: ";
                        cin>>start;
                        system("cls");
                        cout<<"O PLACAR FINAL �:"<<endl<<jogador1<<" : "<<pontos[0]<<endl;
                        cout<<jogador2<<" : "<<pontos[1]<<endl;
                        if(pontos[0]>pontos[1]){
                            cout<<"O GRANDE VENCEDOR � "<<jogador1<<"!!!";
                        }
                        else if (pontos[0]<pontos[1]){
                            cout<<"O GRANDE VENCEDOR � "<<jogador2<<"!!!";
                        }
                        else{
                            cout<<"HOUVE EMPATE!!!";
                        }
                        //A SEGUINTE 'PULADA DE LINHA' � NECESS�RIA, POIS A TELA SEGUINTE � O MENU DE JOGO.
                        cout<<endl;
                        //FIM DO 'PULAR LINHA'

                        //PROCEDIMENTO PARA RETORNAR � TELA INICIAL
                        cout<<"Digite algo para voltar � tela inicial: "<<endl;
                        cin>>start;
                        system("cls");
                        //FIM DO PROCEDIMENTO PARA RETORNAR � TELA INICIAL
                    }
                    //FIM DO PLACAR E DO GRANDE VENCEDOR!

                }
                //FIM DA INTERA��O.

           }
           //FIM DA JOGABILIDADE EM RELA��O A QUEM EST� JOGANDO.

         }
        //FIM DA SEQU�NCIA DE TELAS RESPONS�VEIS PELO JOGO EM SI.

        //O SEGUINTE TRECHO DE C�DIGO � RESPONS�VEL PELA TELA DE INSTRU��ES
        if(c==2){
            cout<<"Seja bem vindo ao Mastermind! Sua tarefa � descobrir uma senha num�rica que foi criada aleatoriamente. Para isso, voce deve gerar palpites at� acertar. A cada "<<endl;
            cout<<"palpite de senha dada, voce ter� como resposta uma quantidade de caracteres 'b'"<<endl;
            cout<<"e 'p', al�m de espa�amentos: ' '. Caracteres 'b' representam um d�gito correto "<<endl;
            cout<<"no local exato, enquanto que d�gitos 'p' sao distribuidos quando um d�gito "<<endl;
            cout<<"inserido est� na senha, porem na posicao errada. Para cada n�vel de "<<endl;
            cout<<"dificuldade existe uma extens�o de senha expec�fica, com d�gitos n�o-repetidos:"<<endl;
            cout<<"O n�vel f�cil gera uma senha de 4 d�gitos com valores de 0 a 5. O n�vel m�dio "<<endl;
            cout<<"cria uma senha de 5 pinos e 7 valores (0 a 6), enquanto que o n�vel dif�cil produz ";
            cout<<" uma senha de 6 d�gitos, com n�meros de 0 a 7. Boa sorte e divirta-se!!!!"<<endl<<endl;
            cout<<endl<<"PARA RETORNAR � TELA INICIAL, DIGITE ALGO E CLIQUE [ENTER]: ";
            cin>>f1;
            system("cls");
        }
        //FIM DA TELA DE INSTRU��ES.

        //O SEGUINTE 'if' � RESPONS�VEL PELA 'sa�da' DO JOGO. iSTO �, A TELA 'EXIT'
        if (c==3) break;
        //FINAL DA SA�DA
    }
    //FIM DO JOGO

    //AGRADECIMENTOS FINAIS
    cout<<"Thank you for playing MASTERMIND"<<endl<<"      by Ariel Alsina, Eduarda Val�ria e Mateus de Assis."<<endl;//tela de finaliza��o
    //FIM DOS AGRADECIMENTOS FINAIS
}

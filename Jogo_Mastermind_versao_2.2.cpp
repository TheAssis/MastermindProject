//  projeto de LoP, por Ariel Alsina, Eduarda Valéria e Mateus de Assis.

//O SEGUINTE ALGORITMO POSSUI A JOGABILIDASDE COMPLETA. ELE MOSTRA UMA TELA INICIAL, PEDE OS NOMES DOS JOGADORES E RODA O JOGO DA SENHA.

#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <algorithm> //precisa disso para usar o random_shuffle
#include <ctime> // precisa disso para usar o seed
#include <windows.h> //biblioteca necessária para usar 'a lentidão'

using namespace std;

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleatórios)

    //DECLARAÇÃO DO VETOR SENHA QUE SERÁ EMBARALHADA
    int senha[8]= {0,1,2,3,4,5,6,7};
    // FIM DA DECLARAÇÃO DO VETOR SENHA QUE SERÁ EMBARALHADA


    //A QUANTIDADE DE TURNOS EXISTENTE,
    //A QUANTIDADE DE PINOS QUE O USUÁRIO PODE MEXER,
    //O TAMANHO MÁXIMO DE SENHA.
    //TUDO DECLARADO NA PRÓXIMA LINHA:
    int turnos,pinos,tamanho;

    //DECLARAÇÃO DA VARIÁVEL QUE GUARDA O NÍVEL ESCOLHIDO.
    char nivel;
    // FIM DA DECLARAÇÃO DA VARIÁVEL QUE GUARDA O NÍVEL ESCOLHIDO.

    //DECLARAÇÃO DA VARIÁVEL QUE GUARDA A QUANTIDADE DE JOGADORES
    char quantidade_de_jogadores=0;
    //FIM DA DECLARAÇÃO DA VARIÁVEL QUE GUARDA A QUANTIDADE DE JOGADORES

    // DECLARAÇÃO DE STRING QUE GUARDA OS NOMES DOS JOGADORES
    char jogador1[6];
    char jogador2[6];
    // FIM DA DECLARAÇÃO DE STRING QUE GUARDA OS NOMES DOS JOGADORES


    // AS SEGUNITES DECLARAÇÕES DE VARIÁVEIS SEVEM PARA GERAR A ANIMAÇÃO-TÍTULO. A STRING 'TÍTULO' GUARDA
    // O TÍTULO A SER ANIMADO, ENQUANTO QUE A VARIÁVEL 'J' GUARDA A QUANTIDADE DE VEZES QUE TAL TÍTULO SERÁ
    // REPETIDO.
    char titulo[17]={'P','L','A','Y',' ','M','A','S','T','E','R','M','I','N','D','!','\0'};
    int j=0;
    //FIM DAS DECLARAÇÕES DAS VARIÁVEIS NECESSÁRIAS PARA A ANIMAÇÃO TÍTULO

    // A VARIÁVEL F1 É NECESSÁRIA PARA O RETORNO À TELA PRINCIPAL DO JOGO
    char f1;
    // FIM DA DECLARAÇÃO DE F1.

    //O SEGUINTE TRECHO DE CÓDIGO ANIMA O TÍTULO
    do{
        for (int i=0; titulo[i]!='\0';i++){
            cout<<titulo[i]<<" ";
            Sleep(100); // esperar 100 milisegundos
        }
        system("cls"); // limpar a tela
        j++;
    }while (j<5);
    //FIM DA ANIMAÇÃO DO TÍTULO

    // VARIÁVEL 'c' GUARDA A ESCOLHA DO MENU
    int c=0;
    //FIM DA DECLARAÇÃO DA VARIÁVEL C

    //O SEGUINTE TRECHO DE CÓDIGO PERMITE QUE O JOGO 'RODE'.
    while(true){ // esse comando é para criar um loop

        // O SEGUINTE TRECHO DE CÓDIGO É RESPONSÁVEL POR CRIAR UMA TELA DE MENU ESTÁTICA.
        do{
            cout<<"PLAY MASTERMIND!"<<"  by Duda, TheAssis, @riel"<<endl<<"CHOOSE:"<<endl<<endl;
            cout<<"1 - PLAY NOW!"<<endl<<"2 - INSTRUCTIONS"<<endl<<"3 - EXIT"<<endl<<endl;
            cin>>c;
            system("cls");
         }while(c!=1&&c!=3&&c!=2);
         //FIM DA TELA ESTÁTICA DO MENU.

         //O SEGUINTE TRECHO DE CÓDIGO É RESPONSÁVEL PELA SEQUÊNCIA DE TELAS RESPONSÁVEIS PELO JOGO EM SI.
         if(c==1){

            //SELECIONANDO O MODO DE JOGO (Single ou Multiplayer)
            do{
                cout<<"Selecione um modo: "<<endl<<"1 - Single."<<endl<<"2 - Multiplayer."<<endl<<"ESCOLHA: ";
                cin>>quantidade_de_jogadores;
                system("cls");
            }while(quantidade_de_jogadores !='1' && quantidade_de_jogadores!='2');
            //FIM DA SELEÇÃO DO MODO DE JOGO (Single ou Multiplayer)

            //DECLARAÇÃO DO NOME DO PRIMEIRO JOGADOR:
            //VALIDANDO QUANTIDADE DE DÍGITOS NO NOME
            do{
                cout << "Digite nome de jogador (até 5 digitos): "<<endl;
                cin>> jogador1;
                system ("cls");
            }while(jogador1[5]!='\0'&& jogador1[4]!='\0' &&  jogador1[3]!='\0' &&  jogador1[2]!='\0' && jogador1[1]!='\0');
            //FIM DA VALIDAÇÃO DE DÍGITOS NO NOME
            //FIM DA DECLARAÇÃO DO NOME DO PRIMEIRO JOGADOR.

            //DECLARAÇÃO DO NOME DO SEGUNDO JOGADOR:
            if (quantidade_de_jogadores==2){

                //VALIDANDO QUANTIDADE DE DÍGITOS NO NOME
                do{
                    cout << "Digite o nome do segundo jogador (até 5 digitos): "<<endl;
                    cin>> jogador2;
                    system ("cls");
                }while(jogador2[5]!='\0'&& jogador2[4]!='\0' &&  jogador2[3]!='\0' &&  jogador2[2]!='\0' && jogador2[1]!='\0');
                //FIM DA VALIDAÇÃO DE DÍGITOS NO NOME

            }
            // FIM DA DECLARAÇÃO DO NOME DO SEGUNDO JOGADOR.

            //ESCOLHA DO NÍVEL DE DIFICULDADE (Fácil, Médio ou Intermediário)
            do {

                cout<<"Escolha um nível: "<<endl<<"1 - Fácil;"<<endl<<"2 - Intermediário"<<endl<<"3 - Difícil."<<endl;
                cin>>nivel;

                system("cls");

            } while (nivel!='1' && nivel!='2' && nivel!='3' );
            //ESCOLHA DO NÍVEL DE DIFICULDADE (Fácil, Médio ou Intermediário)

            //ABAIXO SE DEFINEM A QUANTIDADE DE PINOS QUE PODEM SER MEXIDOS, OS TURNOS EXISTENTE E O TAMANHO DA SENHA E A PRÓPRIA SENHA.
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
            //TERMINOS DAS DEFINIÇÕES: TAMANHO DE/E SENHA, QUANTIDADES DE TURNOS E PINOS.

            //VETOR SENHA QUE O USUARIO VAI DIGITAR
            int senha_usuario[tamanho];
            //VETOR SENHA QUE O USUARIO VAI DIGITAR

            //MATRIZ QUE GERA A ANÁLISE DO SISTEMA
            char matriz_resposta[turnos][pinos];
            //MATRIZ QUE GERA A ANÁLISE DO SISTEMA

            //DEFINIÇÃO DO TABULEIRO DO JOGO, O QUAL DEVE RECEBER AS SENHAS
            int tabuleiro[turnos][pinos];
            //FIM DA DEFINIÇÃO DO TABULEIRO DO JOGO

            //MUDANÇA DE JOGADORES OCORREM DEVIDO AO SEGUINTE FOR:
           for(int vez=0; vez<quantidade_de_jogadores; vez++){

                //LIMPANDO O TABULEIRO
                for(int j=0; j<pinos;j++){
                    for(int i=0; i<turnos;i++){
                        tabuleiro[i][j]=0;
                        matriz_resposta[i][j]='?';
                        }
                }
                //FIM DA 'LIMPEZA' DO TABULEIRO.

                //VARIÁVEL GANHAR INDICA QUANDO O JOGADOR GANHOU
                bool ganhar=false;
                //FIM DA DECLARAÇÃO DA VARIÁVEL ganhar

                //VETOR PONTOS FAZ A GONTAGEM DA PONTUAÇÃO
                int pontos[2]={0,0};
                //FIM DA DECLARAÇÃO DO VETOR QUE FAZ A CONTAGEM DE PONTOS.

                //LIMPAR A TELA
                system("cls");

                //MOSTRANDO A MATRIZ 'TURNOS' VEZES, ISTO É, A JOGABILIDADE EM SI.
                for(int k=0;k<turnos;k++){

                    //DESCOBRINDO SE O JOGADOR GANHOU
                    if(ganhar==true){
                        break;
                    }
                    //FIM DO TESTE DE 'O JOGADOR GANHOU?'.

                    cout << "Master Mind 2017.          VEZ DE "; // 3 tabs

                    //INTERAÇÃO COM O USUÁRIO
                    if(vez==0){
                        cout<<jogador1<<endl;
                    }
                    if(vez==1){
                        cout<<jogador2<<endl;
                    }
                    //INTERAÇÃO COM O USUÁRIO



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

                        //SALVANDO O DÍGITO DIGITADO
                        tabuleiro[turnos-1-k][i]= senha_usuario[i];
                        //FIM DO REGISTRO DO DÍGITO DIGITADO
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
                                matriz_resposta[turnos-1-k][i]=' ';
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
                    //FIM DA ORGANIZAÇÃO DO VETOR RESPOSTA.

                    //LIMPAR TELA
                    system("cls");
                    //FIM DO LIMPAR TELA

                    //O SEGUINTE TRECHO DE CÓDIGO É RESPONSÁVEL POR DESCOBRIR SE O VETOR RESPOSTA É COMPOSTO POR TERMOS 'b'
                    for(int i=0;i<tamanho;i++){
                        if(matriz_resposta[turnos-1-k][i]!=' ' && matriz_resposta[turnos-1-k][i]!='p'){
                            ganhar=true;
                        }
                        else if(matriz_resposta[turnos-1-k][i]==' ' || matriz_resposta[turnos-1-k][i]=='p'){
                            ganhar=false;
                            break;
                        }
                    }
                    //FIM DO CÓDIGO QUE É RESPONSÁVEL POR DESCOBRIR SE O VETOR RESPOSTA É COMPOSTO POR TERMOS 'b'

                    //DEFINIÇÃO DA PONTUAÇÃO DO JOGADOR
                    pontos[vez]=turnos-k;
                    //FIM DA DEFINIÇÃO DA PONTUAÇÃO DO JOGADOR.

                //AQUI TERMINA O CÓDIGO RESPONSÁVEL PELO JOGO EM SI
                }

                //O SEGUINTE TRECHO MOSTRA A TELA FINAL DO JOGO.

                //LIMPANDO A TELA
                system("cls");
                //FIM DA LIMPEZA DE TELA.

                //INTERAÇÃO COM O USUÁRIO
                if(vez==0){
                    cout<<jogador1;
                }
                if(vez==1){
                    cout<<jogador2;
                }
                //INTERAÇÃO COM O USUÁRIO

                if(ganhar==true){
                    //MOSTRANDO A MENSAGEM DA VITÓRIA E A PONTUAÇÃO
                    cout<<", você Ganhou! Sua pontuação é de: "<<pontos[vez]<<" pontos!"<<endl;
                    //FIM DO MOSTRAR A VITORIA E A PONTUAÇÃO
                }
                //TELA DA DERROTA
                else if(ganhar==false){
                    //MOSTRANDO A MENSAGEM DE DERROTA.
                    pontos[vez]=0;
                    cout<<", você perdeu por limite de jogadas! Sua pontuação é de 0 pontos!"<<endl;
                    //FIM DA MENSAGEM DE DERROTA.
                }

                //PRINTANDO O TABULEIRO FINAL
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
                //FIM DO PRINT DA TABULEIRO FINAL.

                //MOSTRANDO A SENHA AO FINAL DO JOGO.
                cout<<endl<<"A senha era: ";
                for(int j=0;j<pinos;j++){
                        cout<<senha[j];
                    }
                cout<<endl;
                // FIM DA DEMONSTRAÇÃO DA SENHA

                //ESSA VARIÁVEL É SÓ PRA CRIAR A PAUSA ENTRE OS TURNOS
                    char start[15];
                //FIM DA DECLARAÇÃO DA VARIÁVEL PARA AJUDAR A PAUSA

                //PROCEDIMENTO PARA RETORNAR À TELA INICIAL, CASO HOUVER APENAS UM JOGADOR
                if(quantidade_de_jogadores==1){
                    //PROCEDIMENTO PARA RETORNAR À TELA INICIAL
                    cout<<"Digite algo para voltar à tela inicial: "<<endl;
                    cin>>start;
                    system("cls");
                    //FIM DO PROCEDIMENTO PARA RETORNAR À TELA INICIAL
                }
                //PROCEDIMENTO PARA RETORNAR À TELA INICIAL, CASO HOUVER APENAS UM JOGADOR

                //É PRECISO EMBARALHAR A SENHA UMA VEZ MAIS
                random_shuffle(&senha[0],&senha[pinos+2]);
                //FIM DO NOVO EMBARALHAMENTO

                //INTERAÇÕES
                if(quantidade_de_jogadores==2){

                    if(vez==0){
                        cout<<endl<<jogador2<<"...se estiver preparado, digite algo para começarmos seu turno!"<<endl<<"RESPOSTA: ";
                        cin>>start;
                    }
                    // FIM DA PAUSA ENTRE TURNOS

                     //O SEGUINTE TRECHO MOSTRA O PLACAR E O GRANDE VENCEDOR
                    else if(vez==1){
                        cout<<endl<<"Digitem algo se estiverem preparados para o placar!"<<endl<<"RESPOSTA: ";
                        cin>>start;
                        system("cls");
                        cout<<"O PLACAR FINAL É:"<<endl<<jogador1<<" : "<<pontos[0]<<endl;
                        cout<<jogador2<<" : "<<pontos[1]<<endl;
                        if(pontos[0]>pontos[1]){
                            cout<<"O GRANDE VENCEDOR É "<<jogador1<<"!!!";
                        }
                        else if (pontos[0]<pontos[1]){
                            cout<<"O GRANDE VENCEDOR É "<<jogador2<<"!!!";
                        }
                        else{
                            cout<<"HOUVE EMPATE!!!";
                        }
                        //A SEGUINTE 'PULADA DE LINHA' É NECESSÁRIA, POIS A TELA SEGUINTE É O MENU DE JOGO.
                        cout<<endl;
                        //FIM DO 'PULAR LINHA'

                        //PROCEDIMENTO PARA RETORNAR À TELA INICIAL
                        cout<<"Digite algo para voltar à tela inicial: "<<endl;
                        cin>>start;
                        system("cls");
                        //FIM DO PROCEDIMENTO PARA RETORNAR À TELA INICIAL
                    }
                    //FIM DO PLACAR E DO GRANDE VENCEDOR!

                }
                //FIM DA INTERAÇÃO.

           }
           //FIM DA JOGABILIDADE EM RELAÇÃO A QUEM ESTÁ JOGANDO.

         }
        //FIM DA SEQUÊNCIA DE TELAS RESPONSÁVEIS PELO JOGO EM SI.

        //O SEGUINTE TRECHO DE CÓDIGO É RESPONSÁVEL PELA TELA DE INSTRUÇÕES
        if(c==2){
            cout<<"Seja bem vindo ao Mastermind! Sua tarefa é descobrir uma senha numérica que foi criada aleatoriamente. Para isso, voce deve gerar palpites até acertar. A cada "<<endl;
            cout<<"palpite de senha dada, voce terá como resposta uma quantidade de caracteres 'b'"<<endl;
            cout<<"e 'p', além de espaçamentos: ' '. Caracteres 'b' representam um dígito correto "<<endl;
            cout<<"no local exato, enquanto que dígitos 'p' sao distribuidos quando um dígito "<<endl;
            cout<<"inserido está na senha, porem na posicao errada. Para cada nível de "<<endl;
            cout<<"dificuldade existe uma extensão de senha expecífica, com dígitos não-repetidos:"<<endl;
            cout<<"O nível fácil gera uma senha de 4 dígitos com valores de 0 a 5. O nível médio "<<endl;
            cout<<"cria uma senha de 5 pinos e 7 valores (0 a 6), enquanto que o nível difícil produz ";
            cout<<" uma senha de 6 dígitos, com números de 0 a 7. Boa sorte e divirta-se!!!!"<<endl<<endl;
            cout<<endl<<"PARA RETORNAR À TELA INICIAL, DIGITE ALGO E CLIQUE [ENTER]: ";
            cin>>f1;
            system("cls");
        }
        //FIM DA TELA DE INSTRUÇÕES.

        //O SEGUINTE 'if' É RESPONSÁVEL PELA 'saída' DO JOGO. iSTO É, A TELA 'EXIT'
        if (c==3) break;
        //FINAL DA SAÍDA
    }
    //FIM DO JOGO

    //AGRADECIMENTOS FINAIS
    cout<<"Thank you for playing MASTERMIND"<<endl<<"      by Ariel Alsina, Eduarda Valéria e Mateus de Assis."<<endl;//tela de finalização
    //FIM DOS AGRADECIMENTOS FINAIS
}

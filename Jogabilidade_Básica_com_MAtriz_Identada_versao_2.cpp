// Esse código é a Matrix_com_teste_versao_2. Ele printa a matriz em loop. Também é responsável por analisar
// a senha digitada pelo usuário. Dependendo da análise, é demonstrado o vetor resposta organizado. Falta
// ainda organizar de forma que as respostas anteriores vão sendo salvas e o vetor resposta aparece apenas
// no momento certo. Também organizei e comentei XD

// Ele também é responsável por criar uma matriz_resposta (o vetor_resposta já não mais existe). Essa matriz
// guarda os acertos do jogador de forma que suas linhas representam os turnos que vão ocorrendo. O jogo, a
// partir dessa versão, roda em turnos. As jogadas que vão sendo realizadas vão sendo mostradas e os vetores
// respostas também XD. O comando "turnos-k-1", basicamente, te põe na altura certa.

// Essa atualização cria o vetor resposta corretamente. Isto é, os valores que não existem na senha são indicados
// como um vazio. O vetor resposta foi organizado de maneira que os pinos são apresentados na ordem: branco, preto e vazio.
// Também foi implementado a checagem da vitória do jogador. Caso ele vença, uma tela específica é mostrada. Caso não,
// uma tela de derrota é mostrada. A pontuação relativa também é mostrada. Por fim, a senha é mostrada ao final da partida.

// A variável quantidade_de_jogadores guarda a quantidade de jogadores.  Atualizei a definição
// da variável 'nivel' para char pois, se for int, é possível bugar o jogo. Também declarei as variáveis que
// registram o nome dos jogadores (jogador1 e jogador 2). Por fim, criei um sistema de interações.

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


    //A QUANTIDADE DE TURNOS EXISTENTE,
    //A QUANTIDADE DE PINOS QUE O USUÁRIO PODE MEXER,
    //O TAMANHO MÁXIMO DE SENHA.
    //TUDO DECLARADO NA PRÓXIMA LINHA:
    int turnos,pinos,tamanho;

    //DECLARAÇÃO DA VARIÁVEL QUE GUARDA O NÍVEL ESCOLHIDO.
    char nivel;
    // FIM DA DECLARAÇÃO DA VARIÁVEL QUE GUARDA O NÍVEL ESCOLHIDO.

    //DECLARAÇÃO DA VARIÁVEL QUE GUARDA A QUANTIDADE DE JOGADORES
    int quantidade_de_jogadores=0;
    //FIM DA DECLARAÇÃO DA VARIÁVEL QUE GUARDA A QUANTIDADE DE JOGADORES

    // DECLARAÇÃO DE STRING QUE GUARDA OS NOMES DOS JOGADORES
    char jogador1[6];
    char jogador2[6];
    // FIM DA DECLARAÇÃO DE STRING QUE GUARDA OS NOMES DOS JOGADORES


    //SELECIONANDO O MODO DE JOGO (Single ou Multiplayer)
    do{
        cout<<"Selecione um modo: "<<endl<<"1 - Single."<<endl<<"2 - Multiplayer."<<endl<<"ESCOLHA: ";
        cin>>quantidade_de_jogadores;
        system("cls");
    }while(quantidade_de_jogadores <1 || quantidade_de_jogadores>2);
    //FIM DA SELEÇÃO DO MODO DE JOGO (Single ou Multiplayer)

    //DECLARAÇÃO DO NOME DO PRIMEIRO JOGADOR:
    cout << "Digite nome de jogador (até 5 digitos): "<<endl;
    cin>> jogador1;
    system ("cls");
    //FIM DA DECLARAÇÃO DO NOME DO PRIMEIRO JOGADOR.

    //DECLARAÇÃO DO NOME DO SEGUNDO JOGADOR:
    if (quantidade_de_jogadores ==2){
        cout << "Digite o nome do segundo jogador (até 5 digitos): "<<endl;
        cin>> jogador2;
        system ("cls");
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

        //É PRECISO EMBARALHAR A SENHA UMA VEZ MAIS
        random_shuffle(&senha[0],&senha[pinos+2]);
        //FIM DO NOVO EMBARALHAMENTO

        //INTERAÇÕES
        if(quantidade_de_jogadores==2){
            //ESSA VARIÁVEL É SÓ PRA CRIAR A PAUSA ENTRE OS TURNOS
            char start[15];
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
            }
            //FIM DO PLACAR E DO GRANDE VENCEDOR!
        }
        //FIM DA INTERAÇÃO.




   }
   //FIM DA JOGABILIDADE EM RELAÇÃO A QUEM ESTÁ JOGANDO.


   return 0;
}

//  projeto de LoP, por Ariel Alsina, Eduarda Veléria e Mateus de Assis,

#include<iostream>
#include<stdlib.h> // biblioteca necessária para usar o 'limpa tela'
#include <windows.h> //biblioteca necessária para usar 'a lentidão'
#include<locale.h> //usar acentos :P
using namespace std;

int main(){
                    // setLocale(LC_ALL,"Portuguese");   o setlocale ainda não está pronto!
    //o trecho a seguir representa o inicio de tela:
char str1[17]={'P','L','A','Y',' ','M','A','S','T','E','R','M','I','N','D','!','\0'};
int j=0;// essa variável 'j' refere-se à contagem de repetições do título
//aqui está a tela divertida:
do{
for (int i=0; str1[i]!='\0';i++){
    cout<<str1[i]<<" ";
    Sleep(100); // esperar 100 milisegundos
        }
system("cls"); // limpar a tela
j++;
}while (j<5);
//a partir daqui começa a interação!
int c=0; // vari´vel 'c' refere-se a escolha (c-choose)
//tela estática, do menu:
do{
cout<<"PLAY MASTERMIND!"<<"  by Duda, TheAssis, @riel"<<endl<<"CHOOSE:"<<endl<<endl;
cout<<"1 - PLAY NOW!"<<endl<<"2 - INSTRUCTIONS"<<endl<<"3 - EXIT"<<endl<<endl;
cin>>c;
system("cls");
}while(c!=1&&c!=3&&c!=2);
//aqui começa as 'respostas' do sistema:
if(c==2){ //o dígito '2' refere-se à tela de instruções, assim:
    cout<<"Seja bem vindo ao Mastermind! Sua tarefa e descobrir uma senha em cores que foi criada aleatoriamente. Para isso, voce deve gerar palpites ate acertar. A cada "<<endl;
    cout<<"palpite de senha dada, voce tera como resposta uma quantidade de pinos brancos "<<endl;
    cout<<"e pretos. O pino de cor branca representa uma cor colocada exatamente no canto"<<endl;
    cout<<"correto, enquanto que os pinos pretos sao distribuidos quando uma cor colocada"<<endl;
    cout<<"esta na senha, porem na posicao errada. "<<endl;
}
}

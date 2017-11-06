// Suponha que cada cor se relacionar� a um dado valor
// num�rico inteiro. O n�vel f�cil ir� se relacionar a
// 6 cores poss�veis (valores de 0 a 5). O m�dio dever�
// lidar com 7 cores (valores de 0 a 6) e o dif�cil com 8 cores (0 a 7).

#include<stdlib.h>
#include<iostream>
#include<locale.h>

using namespace std;

int main ()
{
    setlocale(LC_ALL,"Portuguese");
    int nvl; // vari�vel que recebe n�vel de dificuldade
    int cor; //  vari�vel 'cor' guarda a quantidade de cores
    int t; // vari�vel 't' guarda tamanho do vetor
    do
    {
        cout<<"Escolha um n�vel: "<<endl<<"1 - F�cil;"<<endl<<"2 - Intermedi�rio"<<endl<<"3 - Dif�cil."<<endl;
        cin>>nvl;
        system("cls");
    }
    while (nvl<=0 || nvl>3);
    // o trecho 'switch' seguinte determina quantas cores
    // haver�o no jogo e o tamanho do vetor.
    switch(nvl)
    {
    case 1:
        cor = 5 ;
        t = 4;
        break;
    case 2:
        cor = 6 ;
        t = 5;
        break;
    case 3:
        cor = 7 ;
        t = 6;
        break;
    }

    int v[t]; // vetor que recebe n�meros aleat�rios
    //cout<<"Seu vetor �: "<<endl;
    // a fun��o 'rand() % n ' gera n�meros entre 0 e n
    // o trecho a seguir preenche o vetor com valores aleat�rios, n�o necessariamente distintos.

    for(int i=0; i<t; i++)
    {
        v[i] = rand() % cor ;
        cout<<v[i]<<"  ";
    }
    float vt[t]; //vetor de teste
    system("cls");
    for (int i=0;i<t;i++){
        cout<<"Digite posi��o "<<i<<" :"<<endl;
        cin>>vt[i];
    }
    system("cls");
    cout<<"vetor gerado:"<<endl;
    for(int i=0; i<t; i++)
    {
        cout<<v[i]<<"  ";
    }
    cout<<endl;
    cout<<"vetor preenchido: "<<endl;
    for(int i=0; i<t; i++)
    {
        cout<<vt[i]<<"  ";
    }

}

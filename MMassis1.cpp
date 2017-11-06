// Suponha que cada cor se relacionará a um dado valor
// numérico inteiro. O nível fácil irá se relacionar a
// 6 cores possíveis (valores de 0 a 5). O médio deverá
// lidar com 7 cores (valores de 0 a 6) e o difícil com 8 cores (0 a 7).

#include<stdlib.h>
#include<iostream>
#include<locale.h>

using namespace std;

int main ()
{
    setlocale(LC_ALL,"Portuguese");
    int nvl; // variável que recebe nível de dificuldade
    int cor; //  variável 'cor' guarda a quantidade de cores
    int t; // variável 't' guarda tamanho do vetor
    do
    {
        cout<<"Escolha um nível: "<<endl<<"1 - Fácil;"<<endl<<"2 - Intermediário"<<endl<<"3 - Difícil."<<endl;
        cin>>nvl;
        system("cls");
    }
    while (nvl<=0 || nvl>3);
    // o trecho 'switch' seguinte determina quantas cores
    // haverão no jogo e o tamanho do vetor.
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

    int v[t]; // vetor que recebe números aleatórios
    //cout<<"Seu vetor é: "<<endl;
    // a função 'rand() % n ' gera números entre 0 e n
    // o trecho a seguir preenche o vetor com valores aleatórios, não necessariamente distintos.

    for(int i=0; i<t; i++)
    {
        v[i] = rand() % cor ;
        cout<<v[i]<<"  ";
    }
    float vt[t]; //vetor de teste
    system("cls");
    for (int i=0;i<t;i++){
        cout<<"Digite posição "<<i<<" :"<<endl;
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

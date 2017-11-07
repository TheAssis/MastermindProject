// Suponha que cada cor se relacionará a um dado valor
// numérico inteiro. O nível fácil irá se relacionar a
// 6 cores possíveis (valores de 0 a 5). O médio deverá
// lidar com 7 cores (valores de 0 a 6) e o difícil com 8 cores (0 a 7).


// a biblioteca stime é necessária para gerar o vetor de valores aleatórios.
//

#include <cstdlib>
#include <ctime>
#include<iostream>
#include<locale.h>

using namespace std;

int main ()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleatórios)
    int nivel; // variável que recebe nível de dificuldade
    int cor; //  variável 'cor' guarda a quantidade de cores
    int tamanho; // variável 't' guarda tamanho do vetor
    do
    {
        cout<<"Escolha um nível: "<<endl<<"1 - Fácil;"<<endl<<"2 - Intermediário"<<endl<<"3 - Difícil."<<endl;
        cin>>nivel;
        system("cls");
    }
    while (nivel<=0 || nivel>3);
    // o trecho 'switch' seguinte determina quantas cores
    // haverão no jogo e o tamanho do vetor.
    switch(nivel)
    {
    case 1:
        cor = 5 ;
        tamanho = 4;
        break;
    case 2:
        cor = 6 ;
        tamanho = 5;
        break;
    case 3:
        cor = 7 ;
        tamanho = 6;
        break;
    }

    int v[tamanho]; // vetor que recebe números aleatórios
    cout<<"Seu vetor é: "<<endl;
    // a função 'rand() % n ' gera números entre 0 e n
    // o trecho a seguir preenche o vetor com valores aleatórios, não necessariamente distintos.

    for(int i=0; i<tamanho; i++)
    {
        v[i] = rand() % cor ;
        cout<<v[i]<<"  ";
    }
    float vt[tamanho]; //vetor de teste
    system("cls");
    for (int i=0;i<tamanho;i++){
        cout<<"Digite posição "<<i<<" :"<<endl;
        cin>>vt[i];
    }
    system("cls");
    cout<<"vetor gerado:"<<endl;
    for(int i=0; i<tamanho; i++)
    {
        cout<<v[i]<<"  ";
    }
    cout<<endl;
    cout<<"vetor preenchido: "<<endl;
    for(int i=0; i<tamanho; i++)
    {
        cout<<vt[i]<<"  ";
}

}



// Suponha que cada cor se relacionará a um dado valor
// numérico inteiro. O nível fácil irá se relacionar a
// 6 cores possíveis (valores de 0 a 5). O médio deverá
// lidar com 7 cores (valores de 0 a 6) e o difícil com 8 cores (0 a 7).


// a biblioteca stime é necessária para gerar o vetor de valores aleatórios.
//

#include<iostream>
#include<algorithm> //precisa disso para usar o random_shuffle
#include<ctime> // precisa disso para usar o seed
#include<locale.h>
#include <cstdlib>

using namespace std;

int main(){
    setlocale(LC_ALL,"Portuguese");
    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleatórios)
    int senha[8]={0,1,2,3,4,5,6,7};
    int nivel; // variável que recebe nível de dificuldade
    int tamanho=0;
    do
    {
        cout<<"Escolha um nível: "<<endl<<"1 - Fácil;"<<endl<<"2 - Intermediário"<<endl<<"3 - Difícil."<<endl;
        cin>>nivel;
        system("cls");
    }
    while (nivel<=0 || nivel>3);
    // o trecho 'switch' seguinte mistura a localização dos valores
    // Também determina o tamanho do vetor.
    // Funciona assim: Se o seu vetor estiver no nível "fácil", o código mistura apenas os 6 primeiros valores.
    // Se estiver no nível médio, as 7 primeiras localizações de memória são misturadas. Para o difícil, todo o vetor é
    // embaralhado.
    switch(nivel)
    {
    case 1:
        random_shuffle(&senha[0],&senha[6]);
        tamanho = 6;
        break;
    case 2:
        random_shuffle(&senha[0],&senha[7]);
        tamanho = 7;
        break;
    case 3:
        random_shuffle(&senha[0],&senha[8]);
        tamanho = 8;
        break;
    }
    for(int i=0;i<tamanho;i++){
        cout<<senha[i]<<"  ";
    }
    cin>>tamanho;

}

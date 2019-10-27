// Suponha que cada cor se relacionar� a um dado valor
// num�rico inteiro. O n�vel f�cil ir� se relacionar a
// 6 cores poss�veis (valores de 0 a 5). O m�dio dever�
// lidar com 7 cores (valores de 0 a 6) e o dif�cil com 8 cores (0 a 7).


// a biblioteca stime � necess�ria para gerar o vetor de valores aleat�rios.
//

#include<iostream>
#include<algorithm> //precisa disso para usar o random_shuffle
#include<ctime> // precisa disso para usar o seed
#include<locale.h>
#include <cstdlib>

using namespace std;

int main(){
    setlocale(LC_ALL,"Portuguese");
    srand(time(0)); // inicializa raiz (processo de gerar vetor de valores aleat�rios)
    int senha[8]={0,1,2,3,4,5,6,7};
    int nivel; // vari�vel que recebe n�vel de dificuldade
    int tamanho=0;
    do
    {
        cout<<"Escolha um n�vel: "<<endl<<"1 - F�cil;"<<endl<<"2 - Intermedi�rio"<<endl<<"3 - Dif�cil."<<endl;
        cin>>nivel;
        system("cls");
    }
    while (nivel<=0 || nivel>3);
    // o trecho 'switch' seguinte mistura a localiza��o dos valores
    // Tamb�m determina o tamanho do vetor.
    // Funciona assim: Se o seu vetor estiver no n�vel "f�cil", o c�digo mistura apenas os 6 primeiros valores.
    // Se estiver no n�vel m�dio, as 7 primeiras localiza��es de mem�ria s�o misturadas. Para o dif�cil, todo o vetor �
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

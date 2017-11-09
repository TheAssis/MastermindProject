// Suponha que cada cor se relacionar� a um dado valor
// num�rico inteiro. O n�vel f�cil ir� se relacionar a
// 6 cores poss�veis (valores de 0 a 5) e 4 pinos. O m�dio dever�
// lidar com 7 cores (valores de 0 a 6) e 5 pinos; e o dif�cil com
// 8 cores (valores de 0 a 7) e 6 pinos.

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
    // Tamb�m determina o tamanho do vetor. Funciona assim: se o seu
    // vetor estiver no n�vel "f�cil", o c�digo mistura apenas os 6
    // primeiros valores. Se estiver no n�vel m�dio, as 7 primeiras
    // localiza��es de mem�ria s�o misturadas.Para o dif�cil, todo o
    // vetor � embaralhado.
    // O 'tamanho' criado � a quantidade de pinos que devem ser analisados.
    switch(nivel)
    {
    case 1:
        random_shuffle(&senha[0],&senha[6]);
        tamanho = 4;
        break;
    case 2:
        random_shuffle(&senha[0],&senha[7]);
        tamanho = 5;
        break;
    case 3:
        random_shuffle(&senha[0],&senha[8]);
        tamanho = 6;
        break;
    }
    int senha_usuario[tamanho];
    char vetor_resposta[tamanho];

    cout<<endl<<"E a gerada: "<<endl;
    for(int i=0;i<tamanho;i++){
        cout<<senha[i]<<"  ";
    }

    cout<<"Digite sua senha: "<<endl;
    for(int i=0;i<tamanho;i++){
        cout<<"Posi��o "<<i<<" : ";
        cin>>senha_usuario[i];
    }
    // O trecho a seguir � respons�vel por ler o vetor digitado e
    // confirmar se ele existe
    //
    //
    //
    //
    //

    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(senha[i]==senha_usuario[j]&&i==j){
                vetor_resposta[i]='b';
                break;
            }
            else if (senha[i]==senha_usuario[j]&&i!=j){
                vetor_resposta[i]='v';
                break;
            }
            else {
                vetor_resposta[i]='p';
            }
        }
    }
    system("cls");
    cout<<"A senha digitada �: "<<endl;
    for(int i=0;i<tamanho;i++){

        cout<<senha_usuario[i]<<"  ";
    }
    cout<<endl<<"E a gerada: "<<endl;
    for(int i=0;i<tamanho;i++){
        cout<<senha[i]<<"  ";
    }
    cout<<endl<<"E o vetor resposta:"<<endl;
     for(int i=0;i<tamanho;i++){
        cout<<vetor_resposta[i]<<"  ";
    }


}

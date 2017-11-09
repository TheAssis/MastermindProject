// Suponha que cada cor se relacionará a um dado valor
// numérico inteiro. O nível fácil irá se relacionar a
// 6 cores possíveis (valores de 0 a 5) e 4 pinos. O médio deverá
// lidar com 7 cores (valores de 0 a 6) e 5 pinos; e o difícil com
// 8 cores (valores de 0 a 7) e 6 pinos.

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
    // Também determina o tamanho do vetor. Funciona assim: se o seu
    // vetor estiver no nível "fácil", o código mistura apenas os 6
    // primeiros valores. Se estiver no nível médio, as 7 primeiras
    // localizações de memória são misturadas.Para o difícil, todo o
    // vetor é embaralhado.
    // O 'tamanho' criado é a quantidade de pinos que devem ser analisados.
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
        cout<<"Posição "<<i<<" : ";
        cin>>senha_usuario[i];
    }
    // O trecho a seguir é responsável por ler o vetor digitado e
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
    cout<<"A senha digitada é: "<<endl;
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

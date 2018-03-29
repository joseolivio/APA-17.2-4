/* Counting Sort algoritmo de ordenação pseudo-linear onde não há comparação entre os elementos do array a ser ordenado */

#include <iostream>

using namespace std;

void CountingSort(int aray[],int tamanho){ // O escopo é o maior elemento somado de 1, para incluir o zero.

    int b[tamanho]; // Array B usado na orndenação..

    int escopo = aray[0]; // Aqui nesse for eu calculo o escopo, isso é necessário pois vai me dar o tamanho do array C.. eu somo 1 no final para contemplar o 0.
    for (int i = 1; i < tamanho; i++)
        if (aray[i] > escopo)
            escopo = aray[i]+1;

    int c[escopo]={0}; // Cria o C dependendo dos elementos do array de entrada e o inicia tudo com zero;

    for(int i=0;i<tamanho;i++) { // Contagem da frequência,

        ++c[aray[i]]; // o c[] vai receber como indice um elemento do array de entrada..
    }

    for(int i=1;i<escopo;i++) { // Faz o somatório das partes lá no C, podemos considerar que o numero representa quantos algarismos temos a esquerda do numero..

    c[i]+=c[i-1];

    }

    for(int i=tamanho-1;i>=0;i--){ // Percore do final pro final, para garantir que o algoritmo é estável.

        b[c[aray[i]]-1]=aray[i]; // O C vai determinar em qual local o aray[i] vai ser colocado no array de suporte, B.
        --c[aray[i]];
    }

    for(int i=0;i<tamanho;i++) {
    aray[i]=b[i]; // Joga os valores de b que já estão ordenados no array de foi entrado..
    }


}

int main()
{
    int aray[] = {5,1,5,8,9,3,1,8,58,582,84,85,1,0,14,5,888,1000,1,5,1,2,41,4,5,1,14,51,45,2,4,522,1,4,5,14,5,4,15};
    int tamanho = sizeof(aray)/sizeof(aray[0]);

   cout << "Antes de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    CountingSort(aray, tamanho);

    cout << "Depois de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    return 0;
}

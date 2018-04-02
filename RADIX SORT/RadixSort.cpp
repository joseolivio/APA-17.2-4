/* Radix Sort, algoritmo de ordenação pseudo-linear, ideal para ordenar datas, ele ordena primeiro do bit menos significativo para o mais significativo */

#include<iostream>]

using namespace std;


void CountingSort(int aray[], int tamanho, int expoente)
{
    int B[tamanho]; // Array B.
    int i, C[10] = {0}; // Criando o C, vai de 0 a 9, e inicio tudo com zero. Como o radix sort vou ordenar cada casa por vez, não tem problema.

    for (i = 0; i < tamanho; i++)
        C[(aray[i]/expoente)%10]++; // "Cria os baldes" das dezenas, centenas, etc... e conta as frequencias..

    for (i = 1; i < 10; i++)
        C[i] += C[i - 1]; // Faz as somas da casas, no final das contas vai dar a posicao correta do numero..

    for (i = tamanho - 1; i >= 0; i--) // O array é percorrido de tras para frente para manter-se estavel.
    {
        B[C[(aray[i]/expoente)%10]-1] = aray[i]; // Joga os valores de A em B através do valor de C, fazemos isso para nao perder o valor em A.
        C[(aray[i]/expoente)%10]--;
    }

    for (i = 0; i < tamanho; i++) // Joga os elementos de B em A, já ordenados.
        aray[i] = B[i];
}


void RadixSort(int aray[], int tamanho)
{
    int maior = aray[0];
    for (int i = 1; i < tamanho; i++) // Nesse for eu calculo o maior valor, dessa forma eu conssigo saber quantas casas decimais eu tenho,
        if (aray[i] > maior)         //  esse valor maximo poderia ser pedido na propia função do radix sort tambem...
            maior = aray[i];

    for (int expoente = 1; maior/expoente > 0; expoente *= 10) // Se por exemplo, o meu maior valor é 3, esse for vai ser executado 3 vezes, percorrendo todos os digitos,
        CountingSort(aray, tamanho, expoente);                 // e aplicando o Counting Sort por casa decimal, do menos significativo para o mais significativo.
}




int main()
{
    int aray[] = {5,1,5,8,9,3,1,8,58,582,84,85,1,0,14,5,888,150,944,814,514,54,424,521,420,455,145,148,585,517,214,514,514,511,45,17,52,488,51,1,85,1,45};
    int tamanho = sizeof(aray)/sizeof(aray[0]);

   cout << "Antes de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    RadixSort(aray, tamanho);

    cout << "Depois de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    return 0;
}


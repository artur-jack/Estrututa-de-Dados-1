#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

//Creio que esse não é o quick sort mais eficiente.

int partition(int *v,  int l, int r)
{  
	int i = l; //Inicializa o índice i com o valor do índice esquerdo l, que representa o início do subvetor a ser particionado.
	int j = r+1; //Inicializa o índice j com o valor do índice direito r acrescido de 1, que representa o fim do subvetor a ser particionado.
	int pivot = v[l]; //Seleciona o elemento no índice l como pivô. Geralmente, o pivô é escolhido como o primeiro elemento do subvetor

    while (i<j)
    {
        while (v[++i] < pivot && i < r); //Incrementa i e avança para o próximo elemento até encontrar um elemento maior ou igual ao pivô ou alcançar o índice direito r
        while (v[--j] > pivot && j > l); //Decrementa j e retrocede para o elemento anterior até encontrar um elemento menor ou igual ao pivô ou alcançar o índice esquerdo l
        if (i < j) //Se i<j, significa que encontramos dois elementos que estão do lado errado do pivô, portanto, precisamos trocá-los
        {
            int aux = v[i]; //Faz a troca
            v[i] = v[j];
            v[j] = aux;
        }
        //Continua o loop até que i=j, o que significa que todos os elementos menores que o pivô estão à esquerda e todos os elementos maiores estão à direita.
    }

    int aux = v[l]; // Troca o elemento do pivô v[l] com o elemento
    v[l] = v[j];    // na posição v[j], colocando o pivô em sua posição correta no vetor.
    v[j] = aux;

    return j;   //Retorna j, que representa a posição correta do pivô no vetor.

}

void quickSort(int *v,  int l, int r)
{
    if(r<=l) return; // condição de parada da recursão
    
    int p = partition(v, l, r);//divide o subvetor em duas partes com base em um pivô e retorna o índice p, que representa a posição correta do pivô no vetor.
	quickSort(v, l, p-1);//usa a recursão para ordenar o subvetor à esquerda do pivô, ou seja, do índice l até p-1
	quickSort(v, p+1, r);//usa a recursão para ordenar o subvetor à direita do pivô, ou seja, do índice p+1 até r
}

void quick_sortM3I(int *v,  int l, int r) //mediana de 3
{
    if(r-l<=15){
        return;
    } 
    
    exch(v[(l+r)/2], v[r-1]);
    compexch(v[l], v[r-1]);
    compexch(v[l], v[r]);
    compexch(v[r-1], v[r]);

    int p = partitionRSEDGEWICK(v, l+1, r-1);
	quick_sortM3I(v, l, p-1);
	quick_sortM3I(v, p+1, r);
}

int main(){

    Item vetor[100];
    for (int i = 0; i < 100; i++)   
    {
        vetor[i] = rand()%1000;  //preenche o vetor com números aleatórios DE 0 a 100
    }
    quickSort(vetor, 0, 99);
    //caso queira printar o vetor, só descomentar essa parte abaixo:
    for (int j = 0; j < 100; j++)
    {
        printf("%d ",vetor[j]);
    }
    
    return 0;
}

/*
 Vetor inicial: [5, 2, 8, 9, 3, 1]

Chamada da função partition(vetor, 0, 5):

Primeiro loop:
i = 0, j = 6
Incrementa i e avança para o próximo elemento até encontrar um elemento maior ou igual ao pivô ou alcançar o índice direito r:
i = 1 (2 < 5)
i = 2 (8 > 5)
Decrementa j e retrocede para o elemento anterior até encontrar um elemento menor ou igual ao pivô ou alcançar o índice esquerdo l:
j = 5 (1 < 5)
Troca os elementos v[i] e v[j]:
Vetor após a troca: [5, 2, 1, 9, 3, 8]
Segundo loop:
Incrementa i e avança para o próximo elemento até encontrar um elemento maior ou igual ao pivô ou alcançar o índice direito r:
i = 3 (9 > 5)
Decrementa j e retrocede para o elemento anterior até encontrar um elemento menor ou igual ao pivô ou alcançar o índice esquerdo l:
j = 4 (3 < 5)
Troca os elementos v[i] e v[j]:
Vetor após a troca: [5, 2, 1, 3, 9, 8]
Terceiro loop:
Incrementa i e avança para o próximo elemento até encontrar um elemento maior ou igual ao pivô ou alcançar o índice direito r:
i = 5 (8 > 5)
Decrementa j e retrocede para o elemento anterior até encontrar um elemento menor ou igual ao pivô ou alcançar o índice esquerdo l:
j = 3 (3 < 5)
Os índices i e j se encontram, então o loop é interrompido.
Troca o elemento do pivô v[l] (5) com o elemento na posição v[j] (3):
Vetor após a troca: [3, 2, 1, 5, 9, 8]

Continua na função quick sort...
*/

#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

void BubbleSort(Item *vetor, int left, int right){
    
for (int i = left; i < right; i++)
{
    for (int j = left; j < right; j++)
    {   
        cmpswap(vetor[j+1], vetor[j]); //essa macro faz a mesma coisa que o if embaixo 
        
        /*if (less(vetor[j+1], vetor[j]))
        {
            swap(vetor[j+1], vetor[j]);
        }*/
    }
} 
}

//Uma forma de melhorar seria se não fosse feita nenhuma troca no segundo for encerrar o programa. Pois provavelmente já está ordenado.

int main(){

    Item vetor[20];
    for (int i = 0; i < 20; i++)   
    {
        vetor[i] = rand()%100;  //preenche o vetor com números aleatórios DE 0 a 100
    }
    BubbleSort(vetor, 0, 19);
    //caso queira printar o vetor, só descomentar essa parte abaixo:
    for (int j = 0; j < 20; j++)
    {
        printf("%d ",vetor[j]);
    }
    
    return 0;
}
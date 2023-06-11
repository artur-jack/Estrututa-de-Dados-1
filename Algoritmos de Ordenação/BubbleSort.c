#include <stdio.h>
#include <stdlib.h>
#include <Macros.h>

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
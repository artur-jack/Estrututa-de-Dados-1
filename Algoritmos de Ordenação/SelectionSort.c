#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

void selectionSort(Item *vetor, int left, int right){

if(left == right) return;

int menor = left;   // o menor valor começa sendo o mais a esquerda
for(int j = left+1; j <= right; j++){ //percorre o vetor
    if(less(vetor[j], vetor[menor])){ // se o valor no indice j menor que o mais a esquerda troca
        menor = j;                    // e j vira o menor valor
    }
}
exch(vetor[menor], vetor[left]);  //o valor no indice do menor valor achado troca de lugar e vai para a posição
                                  //do item no indice esquerda (Assim o menor elemento fica mais a esquerda do vetor)
selectionSort(vetor, left+1, right);
}

// ========== SEM USAR RECURSÃO: ====================================================================================

void selectionSortSemRecursao(Item *vetor, int left, int right){

for(int i = left; i < right; i++){

    int menor = i;   // o menor valor começa sendo o mais a esquerda
    for(int j = i+1; j <= right; j++){ //percorre o vetor
        if(less(vetor[j], vetor[menor])){ // se o valor no indice j menor que o mais a esquerda troca
            menor = j;                    // e j vira o menor valor
        }
    }
    exch(vetor[i], vetor[menor]);  //o valor no indice do menor valor achado troca de lugar e vai para a posição
                                  //do item no indice esquerda (Assim o menor elemento fica mais a esquerda do vetor)
}
}

int main(){

    Item vetor[10];
    for (int i = 0; i < 10; i++)   
    {
        vetor[i] = rand()%100;  //preenche o vetor com números aleatórios DE 0 a 100
    }
    selectionSort(vetor, 0, 9);
    //caso queira printar o vetor, só descomentar essa parte abaixo:
    /*for (int j = 0; j < 10; j++)
    {
        printf("%d ",vetor[j]);
    }
    */
    return 0;
}
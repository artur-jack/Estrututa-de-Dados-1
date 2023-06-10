#include <stdio.h>
#include <stdlib.h>
//#include <Macros.h>
typedef int Item;

#define Key(A) (A); //Key(A) retorna (A.chave) nesse caso o própio A.
#define less(A,B) (A < B) //Define uma macro que recebe dois itens e retorna se A menor que B.
#define swap(A,B) {Item t = A; A = B; B = t;} // faz a troca de A e B usando um item temporario como auxiliar.
#define cmpswap(A,B) {if(less(B,A))swap(A,B)} // faz a comparação e se B < A faz a troca.
void selectionSort(Item *vetor, int left, int right){

if(left == right) return;

int menor = left;   // o menor valor começa sendo o mais a esquerda
for(int j = left+1; j <= right; j++){ //percorre o vetor
    if(less(vetor[j], vetor[menor])){ // se o valor no indice j menor que o mais a esquerda troca
        menor = j;                    // e j vira o menor valor
    }
}
swap(vetor[menor], vetor[left]);  //o valor no indice do menor valor achado troca de lugar e vai para a posição
                                  //do item no indice esquerda (Assim o menor elemento fica mais a esquerda do vetor)
selectionSort(vetor, left+1, right);
}

// ========== SEM USAR RECURSÃO: ====================================================================================

void selectionSortSemRecursao(Item *vetor, int left, int right){

for(int i = left; i <= right; i++){

    int menor = i;   // o menor valor começa sendo o mais a esquerda
    for(int j = i+1; j <= right; j++){ //percorre o vetor
        if(less(vetor[j], vetor[menor])){ // se o valor no indice j menor que o mais a esquerda troca
            menor = j;                    // e j vira o menor valor
        }
    }
    swap(vetor[menor], vetor[left]);  //o valor no indice do menor valor achado troca de lugar e vai para a posição
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
    for (int j = 0; j < 10; j++)
    {
        printf("%d ",vetor[j]);
    }
    
    return 0;
}
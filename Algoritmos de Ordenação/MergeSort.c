#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

void merge(Item *v, int left, int meio, int right){

    //alocar espaço auxiliar
    int *aux = malloc(sizeof(int)*(right+1-left));
    
    //auxiliares
    int i=left; //inicio do sub-vetor esquerdo
    int j=meio+1; //inicio do sub-vetor direito
    int k=0; //inicio do vetor auxiliar
    
    while(i<=meio && j<=right) //percorrer os sub-vetores
    {   //faz a ordenção de acordo com cada sub-vetor
        if(v[i] <= v[j]) //testar sub-vetores 
            aux[k++] = v[i++];//ordenar no vetor auxiliar
        else 
            aux[k++] = v[j++];//ordenar no vetor auxiliar
    }

    //ainda tem elementos no sub-vetor esquerdo?
    while(i<=meio) aux[k++] = v[i++];

    //ainda tem elementos no sub-vetor direito?
    while(j<=right) aux[k++] = v[j++];


    k=0; //indice do aux
    for(i=left; i<=right; i++) //indice do v
        v[i] = aux[k++];//copiar o aux[k] para v[i]
        
    //liberar memoria
    free(aux);

}

void merge_sort(int *v, int left, int right)
{
    if (left >= right) return;  //condição de parada da recursão
    int m = (right+left)/2;
    merge_sort(v, left, m);     //recursão esquerda
    merge_sort(v, m+1, right);  //recursão direita
    merge(v, left, m, right);   //usa o merge para juntar ordenando
}

/*int main(){

    Item vetor[100];
    for (int i = 0; i < 100; i++)   
    {
        vetor[i] = rand()%1000;  //preenche o vetor com números aleatórios DE 0 a 100
    }
    merge_sort(vetor, 0, 99);
    //caso queira printar o vetor, só descomentar essa parte abaixo:
    for (int j = 0; j < 100; j++)
    {
        printf("%d ",vetor[j]);
    }
    
    return 0;
}*/
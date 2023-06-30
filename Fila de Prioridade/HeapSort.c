#include <stdio.h>

void heapSort(int *v, int N){
    int i, aux;
    for(i=(N-1)/2; i>=0; i--){
        criaHeap(v, i, N-1);
    }
    for ( i = N-1; i >= 1; i--)
    {
        aux = v[0];         // Pega o maior elemento da heap e coloca 
        v[0] = v[i];        // na sua posição correspondente no array
        v[i] = aux;
        criaHeap(v, 0, i-1);    // Recostruir heap
    }
}

void criaHeap(int *v, int i, int f){
    int aux = v[i];
    int j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {                           
            if (v[j] < v[j+1])  // Pai tem 2 filhos?
            {                   // Quem é o maior?
                j = j+1;
            }
        }
        if (aux < v[j])     // Filho maior que o pai?
        {                   // Filho se torna o pai!
            v[i] = v[j];    // Repete o processos
            i = j;
            j = 2*i+1;
        }
        else{
            j = f+1;
        }
    }
    v[i] = aux;     //Antigo Pai ocupa o lugar do ultimo filho analisado
}
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A, B) ((A) < (B))

void countsort(Item *v, int begin, int end) {
  int R = 0;
  for (int i = begin; i <= end; i++) {  //Percorre o vetor procurando o maior elemento
    if (v[i] > R) {
      R = v[i];
    }
  }
  R += 2;   //Precisa ter o maior elemento + 2

  int *count = calloc(sizeof(int), R);  //Aloca o nosso vetor auxiliar já zerado para fazer a contagem
  for (int i = begin; i <= end; i++) {
    count[v[i] + 1]++;
  }

  for (int i = 1; i < R; i++) {     //percorre o vetor count
    count[i] += count[i - 1];   //soma com o anterior
  }

  Item *aux = malloc(sizeof(Item) * (end - begin + 1)); //Aloca o vetor auxiliar onde ficara nosso vetor ordenado
  for (int i = begin; i <= end; i++) {  
    aux[count[v[i]]] = v[i];   //meio que vai colocar no vetor aux o item i na posição que o count contou desse item 
    count[v[i]]++;  //somar 1 no contador desse item(fazendo com que assim o proximo count de um item igual vá para a posição desse + 1, no caso a posição seguinte)
  } //depois desse for, teremos o vetor ordenado já

  for (int i = begin; i <= end; i++) {
    v[i] = aux[i - begin];  //faz isso para tirar a relatividade da variavel inicio, que pode n ser realmente o inicio do vetor
  }
  free(count);  //libera a memoria
  free(aux);
}

int main() {
  int sla[] = {1, 23, 43, 312, 321, 5, 42, 1};
  int n = sizeof(sla) / sizeof(int);

  countsort(sla, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", sla[i]);
  }
}
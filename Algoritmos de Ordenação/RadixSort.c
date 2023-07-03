#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A, B) ((A) < (B))
#define digit(A, m) ((A / n) % 10) //pega o modulo 10, para pegar o ultimo digito

//Diferença desse countSort é que ele recebe um parametro n a mais, que seria qual a casa decimal que quero verificar
void countsort(Item *v, int begin, int end, int n) {
  int R = 0;
  for (int i = begin; i <= end; i++) {
    if (digit(v[i], n) > R) {
      R = digit(v[i], n);
    }
  }
  R += 2;

  int *count = calloc(sizeof(int), R);
  for (int i = begin; i <= end; i++) {
    count[digit(v[i], n) + 1]++;
  }

  for (int i = 1; i < R; i++) {
    count[i] += count[i - 1];
  }

  Item *aux = malloc(sizeof(Item) * (end - begin + 1));
  for (int i = begin; i <= end; i++) {
    aux[count[digit(v[i], n)]] = v[i];
    count[digit(v[i], n)]++;
  }

  for (int i = begin; i <= end; i++) {
    v[i] = aux[i - begin];
  }
  free(count);
  free(aux);
}

void radixsort(Item *v, int begin, int end) {
  int R = 0;
  for (int i = begin; i <= end; i++) {
    if (v[i] > R) {
      R = v[i];
    }
  }

  int n = 1;
  while (R / n) {
    countsort(v, begin, end, n);
    n *= 10;
  }
}

int main() {
  int sla[] = {1, 23, 43, 312, 321, 5, 42, 1};
  int n = sizeof(sla) / sizeof(int);

  radixsort(sla, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", sla[i]);
  }
}
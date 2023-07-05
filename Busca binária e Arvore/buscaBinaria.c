#include <stdio.h>

#define less(A, B) (A < B)

int buscaBinaria(int *v, int begin, int end, int target) {
  int mid;

  int i = 0;
  while (end >= begin) {
    i++;
    mid = (begin + end) / 2; //mid recebe o calculo do meio do vetor

    if (less(v[mid], target)) {
      begin = mid + 1;      //se o meio for menor doque o item q procuramos, vamos procurar a direita do meio(maiores que o meio)
                        //o vetor vai ficar com o inicio começando em meio+1 e vai até o final
    } else if (less(target, v[mid])) {
      end = mid - 1;    //se o que procuramos for menor que o meio, procuramos a esquerda do meio
                        //o vetor vai ficar com o inicio normal e seu final vair ser o meio-1.
    } else {
      printf("Foram feitas %d iterações\n", i);
      return mid;   //se n for maior nem menor, só pode ser o meio! Retorna o meio
    }
  }

  printf("Foram feitas %d iterações\n", i);
  return -1;    //retorna -1 caso ele n exista(condição do while)
}

int buscaBinariaRecursiva(int *v, int begin, int end, int target) {
  if (end < begin) {
    return -1;  //caso não exista
  }

  int mid = (begin + end) / 2;  //calculo do meio
  if (less(v[mid], target)) {
    return buscaBinaria(v, mid + 1, end, target);  //se meio for menor q nosso alvo, passa a busca com o vetor começando em meio+1 
  } else if (less(target, v[mid])) {
    return buscaBinaria(v, begin, mid - 1, target);//se meio for mair q o alvo, passa o vetor com fim em meio-1
  } else {
    return mid; //se não for menor nem maior retorna o meio
  }
}

int main() {
  int a[] = {1, 3, 5, 128, 300};
  int len = sizeof(a) / sizeof(int);

  int index = buscaBinaria(a, 0, len - 1, 128);
  printf("%d é o indice do elemento a ser buscado\n", index);
}
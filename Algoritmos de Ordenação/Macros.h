#include <stdio.h>

typedef int Item;

#define Key(A) (A) //Key(A) retorna (A.chave) nesse caso o própio A.
#define less(A,B) (A < B) //Define uma macro que recebe dois itens e retorna se A menor que B.
#define swap(A,B) {Item t = A; A = B; B = t;} // faz a troca de A e B usando um item temporario como auxiliar.
#define cmpswap(A,B) {if(less(A,B))swap(A,B)} // faz a comparação e se B < A faz a troca.

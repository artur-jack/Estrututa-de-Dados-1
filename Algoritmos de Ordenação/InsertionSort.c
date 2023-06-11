#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

//Implementação mais fácil e menos eficiente do InsertionSort

void InsertionSort(Item *vetor, int left, int right){

    for (int i = left+1; i <= right; i++)
    {
        for (int j = i; j > left; j--)
        {
            cmpswap(vetor[j], vetor[j-1])
        } 
    }
}

/*
Primeira Iteração:

       0    1    2    3    4
    | 30 | 20 | 40 | 10 | 15 |

i = 1, j =1
v[1] < v[0]? Sim, troca
j--
para o for do j poís j = left, então volta pro primeiro for i++

Segunda Iteração:

       0    1    2    3    4
    | 20 | 30 | 40 | 10 | 15 |

i = 2, j = 2
v[2] < v[1]? Não(no caso não troca pq a condição não é valida)
j--
j = 1
j > left
v[1] < v[0]? Não
j--
j = left, saí do for do j
i++

...

*/
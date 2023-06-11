#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

void InsertionSort(Item *vetor, int left, int right){

    for (int i = right; i > left; i--)
    {
        cmpswap(vetor[i-1], vetor[i]);  //esse for pega o menor valor
    }
    for (int i = left+2; i <= right; i++)
    {
        int j = i; Item tmp = v[j]; //segura quem tá no indice j, no caso left+2
        while (less(tmp, v[j-1]))   //se tmp(q é o valor q estou segurando) for < que v[j-1]
        {                           
            v[j] = v[j-1];          //v[j-1] vai pra posição de v[j](que era a posição do tmp)
            j--                 // eu continuo com o menor valor armazenado em tmp
        }
        v[j] = tmp;     //se o tmp não for menor que v[j-1], coloca em v[j]
    } 
    
}

/*
Primeira Iteração:
(Já foi feito o primeiro for para achar o menor valor)
       0    1    2    3    4
    | 10 | 30 | 20 | 40 | 15 |

i = 2, direita = 4
i<= direita ? Sim
j = i = 2
tmp = v[2] = 20
(tmp)20 < v[j-1](30)? Sim, então v[2] = v[1](30)

       0    1    2    3    4
    | 10 | 30 | 30 | 40 | 15 |

j--, j = 1
(tmp)20 < v[j-1](10)? Não, então Sai do while e v[j] = tmp(20)

       0    1    2    3    4
    | 10 | 20 | 30 | 40 | 15 |

Volta pro for;
i++

Segunda Iteração:

       0    1    2    3    4
    | 10 | 20 | 30 | 40 | 15 |

i = 3, direita = 4
i<= direita ? Sim
j = i = 3
tmp = v[3] = 40
(tmp)40 < v[j-1](30)? Não, então sai do while e v[j] = tmp(40)

Volta pro for;
i++

Terceira Iteração:

       0    1    2    3    4
    | 10 | 20 | 30 | 40 | 15 |

i = 4, direita = 4
i<= direita ? Sim
j = i = 4
tmp = v[4] = 15
(tmp)15 < v[j-1](40)? Sim, então v[4] = v[3](40)

       0    1    2    3    4
    | 10 | 20 | 30 | 40 | 40 |

j--, j = 3
(tmp)15 < v[j-1](30)? Sim, então v[3] = v[2](30)

       0    1    2    3    4
    | 10 | 20 | 30 | 30 | 40 |

j--, j = 2
(tmp)15 < v[j-1](20)? Sim, então v[2] = v[1](20)

       0    1    2    3    4
    | 10 | 20 | 20 | 30 | 40 |

j--, j = 1
(tmp)15 < v[j-1](10)? Não, então sai do while e v[j] = tmp(15)

       0    1    2    3    4
    | 10 | 15 | 20 | 30 | 40 |

Volta pro for;
i++
i = 5, i <= direita? Não então acaba o algoritmo.
...

*/
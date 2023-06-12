#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

//Insertion Sort módificado para usar no shell sort

void insertionSortH(Item *v, int left, int right, int h){
    for (int i = left+h; i <= right; i++)
    {
       int j = i; Item tmp = v[j];
       while (j>=left+h && less(tmp, v[j-h]))   //se tmp(q é o valor q estou segurando) for < que v[j-1]
        {                           
            v[j] = v[j-h];  //v[j-h] vai pra posição de v[j](que era a posição do tmp)
            j-= h;                
        }
        v[j] = tmp;
    }
    
}

void shellSort(Item *v, int left, int right){

    int h;
    for (int h = 1; h <= (right-left)/9; h=3*h+1) //com esse laço ele vai passar por 1, 4, 13, 40, 121, 364...
    {
        for(;h>0; h=h/3){
            insertionSortH(v, left, right, h);
        }
    }
}
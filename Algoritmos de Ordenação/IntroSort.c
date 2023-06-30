#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

void intro(int *v,  int l, int r, int maxdepth){ 
    if(r-l<=15){
        insertion_sort(v, l, r);

    } else if(maxdepth == 0) {
        merge_sort(v, l, r);
        //heap_sort(v, l, r);

    } else {
        exch(v[(l+r)/2], v[r-1]);
        compexch(v[l], v[r-1]);
        compexch(v[l], v[r]);
        compexch(v[r-1], v[r]);

        int p = partitionRSEDGEWICK(v, l+1, r-1);
	    intro(v, l, p-1, maxdepth-1);
	    intro(v, p+1, r, maxdepth-1);
    }
}

void intro_sort(int *v,  int l, int r){
    int maxdepth = 2*((int)log2((double)(r-l+1)));
    intro(v, l, r, maxdepth);
}
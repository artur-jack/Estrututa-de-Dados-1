//https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html
//https://brunoribas.com.br/apostila-eda/ordenacao-elementar.html
//https://github.com/bcribas/benchmark-ordenacao

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)

#define bitsbyte 8
#define bytesword 4

#define R (1 << bitsbyte) //00000001 << 8 = 00000001 00000000 = 2^8 = 256
#define digit(N,D) (((N) >> ((D)*bitsbyte)) & (R-1))

void show(int v[], int l, int r){
    for(int i=l; i<=r; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int is_sorted(int v[], int l, int r){
    int p;
    for(p=r; p>l && v[p-1]<=v[p]; p--);

    return (p==0);
}

void selection_sort(int v[], int l, int r){
    int menor;

    for(int i=l; i<=r; i++){
        //procurar o menor para trocar com a primeira posicao
        //indice do menor elemento inicialmente
        menor = i;

        //procurar elemento menor
        for(int j=i+1; j<=r; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            } 
        }

        if(v[i] != v[menor]){
            int a = v[i];
            v[i] = v[menor];
            v[menor] = a;
        }
        //show(v, l, r);
    }
    
}

int bubble_sort(int v[], int l, int r){
    //flutuar o ultimo elemento em direcao ao topo
    //quem flutua? ultimo elemento
    //como flutua? comparando com o adjacente
    for(int i=l; i<=r; i++){
        for(int j=r; j>i; j--)
        {
            if(v[j] < v[j-1]){
                int a = v[j];
                v[j] = v[j-1];
                v[j-1] = a;
            }
        }
        //show(v, l, r);
    }
    
}


void shaker_sort(int v[], int l, int r){

    int swap = 0;
    for(int i=l; !swap && i<=r; i++, r--){
        swap = 1;
        for (int j=i; j<=r; j++)
        {
            if (v[j] > v[j+1]) {
                int a = v[j];
                v[j] = v[j+1];
                v[j+1] = a;
                swap = 0;
            }
        }
        
        for(int j=r; j>i; j--)
        {
            if(v[j] < v[j-1]){
                int a = v[j];
                v[j] = v[j-1];
                v[j-1] = a;
                swap = 0;
            }
        }
        
    }
        
}

void insertion_sort(int v[], int l, int r)
{
    for(int i=l+1; i<=r; i++)
    {
        for(int j=i; j>l && v[j]<v[j-1]; j--){
            int a = v[j];
            v[j] = v[j-1];
            v[j-1] = a;
        }
        //show(v, l, r);
    }
}

void shell_sort(int v[], int l, int r)
{
    int h = 1;
    while(h < (r-l+1)/3) h = 3*h+1;

    while(h>=1){
        for(int i=l+h; i<=r; i++)
        {
            for(int j=i; j>=l+h && v[j]<v[j-h]; j-=h)
            {
                int a = v[j];
                v[j] = v[j-h];
                v[j-h] = a;
            }
        }
        h = h/3;
    }
}

void merge1(int *v,  int l, int m, int r)
{
    
    //alocar espaÃ§o auxiliar
    int *aux = malloc(sizeof(int)*(r+1-l));
    
    //auxiliares
    int i=l; //inicio do sub-vetor esquerdo
    int j=m+1; //inicio do sub-vetor direito
    int k=0; //inicio do vetor auxiliar
    
    while(i<=m && j<=r) //percorrer os sub-vetores
    {
        if(v[i] <= v[j]) //testar sub-vetores 
            aux[k++] = v[i++];//ordenar no vetor auxiliar
        else 
            aux[k++] = v[j++];//ordenar no vetor auxiliar
    }

    //ainda tem elementos no sub-vetor esquerdo?
    while(i<=m) aux[k++] = v[i++];

    //ainda tem elementos no sub-vetor direito?
    while(j<=r) aux[k++] = v[j++];


    k=0; //indice do aux
    for(i=l; i<=r; i++) //indice do v
        v[i] = aux[k++];//copiar o aux[k] para v[i]
        
    //liberar memÃ³ria
    free(aux);

}

void merge(int *v, int l, int m, int r)
{
    //quanto espaÃ§o?
    int tam = r+1-l;

    //alocar espaÃ§o auxiliar
    int *aux = malloc(tam*sizeof(int));

    //auxiliares
    int i=l; //inicio do sub-vetor esquerdo
    int j=m+1; //inicio do sub-vetor direito
    int k=0; //inicio do vetor auxiliar

    //ordenar em aux[k]
    while(k<tam) //condiÃ§Ã£o de parada do aux
    {
        if(i>m) //ordenou todo o primeiro sub-vetor
            aux[k++] = v[j++];//consome o segundo sub-vetor -> ordene no aux

        else if (j>r) //ordenou todo o segundo sub-vetor
            aux[k++] = v[i++];//consome o primeiro sub-vetor -> ordene no aux

        else if (v[i] < v[j]) //testar sub-vetores
            aux[k++] = v[i++];//ordene no aux
        else
            aux[k++] = v[j++];//ordene no aux
    }

    k=0; //indice do aux
    for(i=l; i<=r; i++) //indice do v
        v[i] = aux[k++];//copiar o aux[k] para v[i]
        
    //liberar memÃ³ria
    free(aux);
   
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r) return;
    int m = (r+l)/2;
    //printf("merge_sort(v, %d, %d)\n", l, m);
    //printf("merge_sort(v, %d, %d)\n", m+1, r);
    //printf("merge(v, %d, %d, %d)\n", l, m, r);
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge1(v, l, m, r);
}

void mergeBU_sort(int *v, int l, int r)
{
     
    int tam = (r-l+1);

    for (int sz=1; sz<tam; sz=sz+sz)
    {
        for (int lo=l; lo<tam-sz; lo+=sz+sz)
        {
            int hi = lo+sz+sz-1;
            if(hi>tam-1) hi = tam-1;

            merge(v, lo, lo+sz-1, hi); 
        }
    }
}

int partition(int *v,  int l, int r)
{  
	int i = l;
	int j = r+1;
	int pivot = v[l];

    while (i<j)
    {
        while (v[++i] < pivot && i < r);
        while (v[--j] > pivot && j > l);
        if (i < j)
        {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }

    int aux = v[l];
    v[l] = v[j];
    v[j] = aux;

    return j;

}

int partitionCORMEM(int *v, int l, int r)
{
    int pivot = v[r];
    int j = l;
    for(int i=l; i<r; i++)
    {
        if(less(v[i],pivot)){
            exch(v[i], v[j]);
            j++;
        }
    }

    exch(v[r], v[j]);

    return j;
}

void quick_sortC(int *v,  int l, int r)
{
    if(r<=l) return;
    
    int p = partitionCORMEM(v, l, r);
	quick_sortC(v, l, p-1);
	quick_sortC(v, p+1, r);
}

int partitionRSEDGEWICK(int *v, int l, int r)
{
    int i=l-1, j=r, pivot = v[r];
    
    while(1)
    {
        while(v[++i] < pivot);
        while(pivot < v[--j]) if(j==l) break;
        if(i>=j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    

    return i;
}

void quick_sortR(int *v,  int l, int r)
{
    if(r<=l) return;

    int p = partitionRSEDGEWICK(v, l, r);
    //show(v, l, r);
	quick_sortR(v, l, p-1);
	quick_sortR(v, p+1, r);
}

void quick_sortRM3(int *v,  int l, int r)
{
    if(r<=l) return;

    compexch(v[l], v[(l+r)/2]);
    compexch(v[l], v[r]);
    compexch(v[r], v[(l+r)/2]);

    int p = partitionRSEDGEWICK(v, l, r);
    //show(v, l, r);

	quick_sortRM3(v, l, p-1);
	quick_sortRM3(v, p+1, r);
}

int partitionLSEDGEWICK(int *v,  int l, int r)
{  
	int i = l;
	int j = r+1;
	int pivo = v[l];

    while (1)
    {
        while (v[++i] < pivo) if (i == r) break;
        while (pivo < v[--j]) if (j == l) break;
        if (i >= j) break;
        
        exch(v[i], v[j]);
    }
    exch(v[l], v[j]);//atualiza a posicao do pivot

    return j;

}

void quick_sortLM3(int *v,  int l, int r)
{
    if(r<=l) return;

    compexch(v[(l+r)/2], v[r]);
    compexch(v[l], v[r]);
    compexch(v[(l+r)/2], v[l]);

    int p = partitionLSEDGEWICK(v, l, r);
    //show(v, l, r);
	quick_sortLM3(v, l, p-1);
	quick_sortLM3(v, p+1, r);
}

void quick_sortL(int *v,  int l, int r)
{
    if(r<=l) return;

    int p = partitionLSEDGEWICK(v, l, r);
    //show(v, l, r);
	quick_sortL(v, l, p-1);
	quick_sortL(v, p+1, r);
}

void quick_sortM3I(int *v,  int l, int r)
{
    if(r-l<=15){
        return;
    } 
    
    exch(v[(l+r)/2], v[r-1]);
    compexch(v[l], v[r-1]);
    compexch(v[l], v[r]);
    compexch(v[r-1], v[r]);

    int p = partitionRSEDGEWICK(v, l+1, r-1);
	quick_sortM3I(v, l, p-1);
	quick_sortM3I(v, p+1, r);
}


void partition3Way(int *v, int l, int r, int *a, int *b)
{
    int pivot = v[r];
    int i=l-1, j=r;
    int p=l-1, q=r;

    while(1)
    {
        while(v[++i] < pivot);
        while(pivot < v[--j]) if(j==l) break;
        if(i>=j) break;
    
        exch(v[i], v[j]);

        if(v[i]==pivot){
            p++;
            exch(v[i], v[p]);
        }
        if(v[j]==pivot){
            q--;
            exch(v[j], v[q]);
        }
    }
    exch(v[i], v[r]);

    j = i-1;
    i = i+1;

    for(int k=l; k<p; k++, j--){
        exch(v[k], v[j]);
    }

    for(int k=r-1; k>q; k--, i++){
        exch(v[k], v[i]);
    }
    *a = i;
    *b = j;
}

void quick_sortM3W(int *v,  int l, int r)
{
    if(r<=l) return;
    

    int lt = l, gt = r;
    int pv = v[l];

    int i = l+1;
    while (i <= gt) {
        
        if (v[i]<pv){
            exch(v[lt], v[i]);
            lt++; i++;
        } 
        else if (v[i]>pv){
            exch(v[i],v[gt]);
            gt--;
        }
        else  i++;
    }
    // a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi].
    quick_sortM3W(v, l, lt-1);
    quick_sortM3W(v, gt+1, r);
}


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




void radix_sort(int *v,  int l, int r)
{
    int aux[r-l+1];
    int i, w, count[R+1];

    //for(w=bytesword-1; w>=0; w--){
    for(w=0; w<bytesword; w++){
        for(i=0; i<=R; i++)
            count[i] = 0;

        for(i=l; i<=r; i++)
            count[digit(v[i], w)+1]++;
        
        for(i=1; i<=R; i++)
            count[i] += count[i-1];
        
        for(i=l; i<=r; i++){
            aux[count[digit(v[i], w)]] = v[i];
            count[digit(v[i], w)]++;
        }

        for(i=l; i<=r; i++)
            v[i] = aux[i-l]; //como Ã© intervalo de l-r 
                             //i-l garante a varredura de aux a partir de zero
    }
    
}

//./a.out counting < exemplo.txt
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    
    int *v = malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    if(n<50) 
        show(v, 0, n-1);

    if(argc>1){
        if(!strcmp(argv[1], "shaker"))
            shaker_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "bubble"))
            bubble_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "selection"))
            selection_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "insertion"))
            insertion_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "shell"))
            shell_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "merge"))
            merge_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "mergebu"))
            mergeBU_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "quickC"))
            quick_sortC(v, 0, n-1);
        else if(!strcmp(argv[1], "quickR"))
            quick_sortR(v, 0, n-1);
        else if(!strcmp(argv[1], "quickRM3"))
            quick_sortRM3(v, 0, n-1);
        else if(!strcmp(argv[1], "quickLM3"))
            quick_sortLM3(v, 0, n-1);
        else if(!strcmp(argv[1], "quickL"))
            quick_sortL(v, 0, n-1);
        else if(!strcmp(argv[1], "quickM3I")){
            quick_sortM3I(v, 0, n-1);
            insertion_sort(v, 0, n-1);
        }
        else if(!strcmp(argv[1], "quickM3W"))
            quick_sortM3W(v, 0, n-1);
        else if(!strcmp(argv[1], "intro"))
            intro_sort(v, 0, n-1); 
        else if(!strcmp(argv[1], "radix"))
            radix_sort(v, 0, n-1); 
    }
    

    if(n<50) 
        show(v, 0, n-1);

    if(is_sorted(v, 0, n-1)) printf("ordenado.\n");
    else printf("nÃ£o ordenado.\n");

    
    return 0;
}



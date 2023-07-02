#include <stdio.h>

typedef int Item;

typedef struct {
    int size;
    Item *v;
} Heap;

Heap *Heap_new(int capacity){
    Heap* newHeap = malloc(sizeof(Heap));
    newHeap->v = malloc(sizeof(Item)*(capacity+1));
    newHeap->size = 0;
}

//FixUp é usado na inserção na fila de prioridade(heap)
// FORMA RECURSIVA FIXUP(PROVAVELMENTE NÃO CAI NA PROVA)
void fixUp(Heap* h, int i){
    if(i <= 1){
        return;     //Se tiver na raiz retorna, pois já é a maior prioridade
    }
    int parent = i/2;   //Esse é o pai

    if (h->v[parent] < h->v[i])     //Se o pai for menor que o filho, troca
    {
        //exch(A, B)
        Item tmp = h->v[parent];
        h->v[parent] = h->v[i];
        h->[i] = tmp;
        fixUp(h, parent);
    }
}

// FORMA FIXUP QUE DEVE CAIR
void fixUpIterativo(Heap* h, int i){
                                            //Faz as mesmas condições da fixUp recursiva, só quem um while
    while(i > 1 && h->v[i/2] < h->v[i]){    //Verifica se o indice 'i' é a raiz e se o pai é menor que o filho
        //exch(A, B)                        //Se i não for a raiz e o pai for menor que o filho entra no while
        Item tmp = h->v[i/2];   //Faz a troca
        h->v[i/2] = h->v[i];
        h->[i] = tmp;

        i = i/2;    //O i vira o pai
    }
}

// Inserir um novo elemento na Fila
void insert(Heap* h, Item i){
    h->v[h->size + 1] = i;  //Coloca o item a ser inserido na ultima posição, pegando o indice tamanho + 1 pois o indice 0 é ignorado na heap
    h->size ++; //Novo tamanho da fila, já que inseriu mais um item
    fixUp(h, h->size);
}

//Ver a maior prioridade(raiz)
Item top(Heap* h){
    return h->v[1];
}

//Usado na função de deletar da heap
void fixDown(Heap* h, int i){

    int child;
    while (i*2 <= h->size)  //Verifica se o filho existe, vendo se o indice desse filho não excede o tamanho da fila
    {
        child = 2 * i;  //O indice do filho vai ser i * 2, no caso o child começa sendo o filho da esquerda
        if(child != h->size && h->v[child] < h->v[child + 1]){  //Verifica se o indice child não é filho unico(por ser o ultimo item) e se o filho da direita é maior(prioridade maior)
            child ++;   //Se o filho da direita for maior, ele passa a ser o child
        }

        if(h->v[i] < h->v[child]){  //Verifica se eu(i) é menor que o filho, se é troca
            Item tmp = h->v[child];   //Faz a troca
            h->v[child] = h->v[i];
            h->[i] = tmp;

            i = child;  //O pai vira o filho e volta pro while, pq pode ser que ele ainda n esteja na posição correta
        }
        else{
            break;
        }
    }
}

//Deletar da heap
void pop(Heap* h){
    Item tmp = h->v[1];   //Faz a troca da raiz com o ultimo elemento
    h->v[1] = h->v[h->size];
    h->[h->size] = tmp;
    h->size--;  //remove da fila, pq o item foi pro final e diminuimos os tamanho da fila aqui, logo ele é "removido"

    fixDown(h, 1); //fixDown do elemento que a gente trocou com a raiz para coloca-lo em sua posição correta
}

int main(){

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULLitem ((Item){})
#define info(A) (A.info)
#define key(A) (A.chave)
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)

typedef int Key;
typedef struct data Item;
struct data {
    Key chave;
    char info[100];
};


typedef struct node STnode;
struct node {
    Item item;
    STnode *esq;
    STnode *dir;
};

STnode *new(Item x, STnode *e, STnode *d)
{
    STnode *no = malloc(sizeof(STnode));
    no->esq = e;
    no->dir = d;
    no->item = x;
    return no;
}


Item STsearch(STnode *no, Key v)
{
    if(no == NULL) return NULLitem;
    Key t = key(no->item);
    if(eq(v, t)) return no->item;
    if(less(v, t)) return STsearch(no->esq, v);
    else return STsearch(no->dir, v);
}

STnode *STinsert(STnode *no, Item item){
    
    if(no == NULL)
        return new(item, NULL, NULL);
    
    Key novo = key(item);
    Key atual = key(no->item);
    if(less(novo, atual))
        no->esq = STinsert(no->esq, item);
    else
        no->dir = STinsert(no->dir, item);

    return no;
}


STnode *min(STnode *no)
{
    if (no->esq == NULL) return no;
    return min(no->esq);
}

STnode *deleteMin(STnode *no)
{
    if (no->esq == NULL) return no->dir;

    no->esq = deleteMin(no->esq);
    return no;
}

STnode *STdelete(STnode *no, Key remove)
{
    if (no == NULL) return NULL;

    Key atual = key(no->item);
    if(less(remove, atual)) no->esq = STdelete(no->esq, remove);
    else if(less(atual, remove)) no->dir = STdelete(no->dir, remove);
    else
    {
        STnode *aux;
        if (no->dir == NULL) {
            aux = no->esq;
            free(no);
            return aux;
        }
        if (no->esq == NULL){
            aux = no->dir;
            free(no);
            return aux;
        }

        aux = no;
        no = min(aux->dir);
        no->dir = deleteMin(aux->dir);
        no->esq = aux->esq;

        free(aux);
    }
    
    return no;
}


void preordem(STnode *raiz) {
    if (raiz != NULL) {
        printf("%d %s\n", key(raiz->item), info(raiz->item)); /* visita raiz */
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
}

void inordem(STnode *raiz) {
    if (raiz != NULL) {
        inordem(raiz->esq);
        printf("%d %s\n", key(raiz->item), info(raiz->item)); /* visita raiz */
        inordem(raiz->dir);
    }
}

void posordem(STnode *raiz) {
    if (raiz != NULL) {
        posordem(raiz->esq);
        posordem(raiz->dir);
        printf("%d %s\n", key(raiz->item), info(raiz->item)); /* visita raiz */
    }
}

//./a.out 74 < n10.txt
int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    STnode *tree = NULL;
    for(int i=0; i<n; i++) {
        Item v;
        scanf("%d %s", &v.chave, v.info);
        tree = STinsert(tree, v);
    }    
    inordem(tree);
    printf("\n\nRemovendo a chave 7:\n");
    tree = STdelete(tree, 7);
    inordem(tree);

    if(argc>1){
        printf("\n\nProcurando a chave %d:\n", atoi(argv[1]));
        Item a = STsearch(tree, atoi(argv[1]));
        printf("%d %s\n", key(a), info(a));
    } 
    //faca a função que percorra a árvore em largura

    return 0;
}
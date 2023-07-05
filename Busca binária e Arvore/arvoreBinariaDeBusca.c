#include <stdlib.h>

typedef int Key;

typedef struct {
  Key key;
  int value;
} Item;

#define key(A) ((A).key)
#define lessKey(A, B) ((A) < (B))
#define less(A, B) (lessKey(key(A), key(B)))

typedef struct Node {
  Node *left, *right;   //nó da árvore
  Item item;
} Node;

Node *inserir(Node *root, Item item) {
  if (root == NULL) {
    Node *newNode = malloc(sizeof(Node));   //se não tiver elemento raiz, ele vai ser o primeiro
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->item = item;

    return root;
  }

  if (less(root->item, item)) {     //Se o item a ser inserido for maior que o da raiz
    root->right = inserir(root->right, item);   //faz recursão para o filho direito da raiz
  } else if (less(item, root->item)) {  //Se o item a ser inserido for menor que o da raiz
    root->left = inserir(root->left, item); //faz recursão para o filho esquerdo da raiz
  } else {
    root->item = item;  //se for igual reatribui o valor
  }

  return root;
}

Node *buscar(Node *root, Key k) {
  if (root == NULL) {
    return NULL;
  }

  Key actualKey = key(root->item);

  if (lessKey(actualKey, k)) {
    return buscar(root->right, k);
  } else if (lessKey(k, actualKey)) {
    return buscar(root->left, k);
  } else {
    return root;
  }
}

Node *minNode(Node *root) { //Pegar o menor nó
  if (root->left == NULL) {
    return root;    //se o elemento a esquerda for nul,q uer dizer que esse é o menor
  }

  return minNode(root->left);   //se não faz a recursão passando o proximo elemento a esquerda
}

Node *deleteMinNode(Node *root) {
  if (root->left == NULL) { //se for nuul a esquerda, ele é o elemento a ser deletado
    return root->right;     //retorna o filho da direita desse menor elemento, assim o pai do deletado vai assumir o orfão
  }

  root->left = deleteMinNode(root->left);//se tiver elemento a esquerda, usa a recursão passando o filho a esquerda
  return root;
}

Node *deleteNode(Node *root, Key k) {
  if (root == NULL) { //se for null item não existe
    return NULL;
  }

  Key actualKey = key(root->item);

  if (lessKey(actualKey, k)) {
    root->right = deleteNode(root->right, k);//busca o elemento
  } else if (lessKey(k, actualKey)) {
    root->left = deleteNode(root->left, k);//busca o elemento
  } else {
    if (root->left == NULL) {
      Node *aux = root->right;
      free(root);
      return aux;
    }

    if (root->right == NULL) {
      Node *aux = root->left;
      free(root);
      return aux;
    }

    Node *aux = root;
    root = minNode(aux->right);
    root->left = aux->left;
    root->right = deleteMinNode(aux->right);
    free(aux);
  }

  return root;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  struct no* pai;
  struct no* esquerda;
  struct no* direita;
  float v;
} No;

typedef struct arvore {
  No* raiz;
} Arvore;

Arvore* cria() {
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  
  return arvore;
}

int vazia(Arvore* arvore) {
  return (arvore->raiz == NULL);
}

No* adiciona(Arvore* arvore, No* pai, float valor) {
  No *no = malloc(sizeof(No));
  no->pai = pai;
  
  no->esquerda = NULL;
  no->direita = NULL;
  
  no->v = valor;

  if (pai == NULL)
    arvore->raiz = no;
  
  return no;
}

void percorre(No* no) {
  No **nivel = malloc(sizeof(No));
  nivel[0] = no;

  int tam = 1;

  while(tam != 0) {
    int filhos = 0;

    for(int i = 0; i < tam; i++){
      if (nivel[i]->esquerda != NULL){
        filhos++;
      }

      if (nivel[i]->direita != NULL){
        filhos++;
      }
    }

    No** nos = malloc(filhos * sizeof(No));
    filhos = 0;
    
    for(int i = 0; i < tam; i++){
      if (nivel[i]->esquerda != NULL){
        nos[filhos++] = nivel[i]->esquerda;
      }

      if (nivel[i]->direita != NULL){
        nos[filhos++] = nivel[i]->direita;
      }

      printf("%f ", nivel[i]->v);
    }

    printf("\n");

    free(nivel);
    
    nivel = nos;
    tam = filhos;
  }
}

int main(void) {
  Arvore *arvore = (void*) cria();

  No *no5 = adiciona(arvore, NULL, 5);

  No *no3 = adiciona(arvore,no5,3);
  No *no7 = adiciona(arvore,no5,7);

  no5->esquerda = no3;
  no5->direita = no7;

  No *no2 = adiciona(arvore,no3,2);
  No *no4 = adiciona(arvore,no3,4);

  no3->esquerda = no2;
  no3->direita = no4;

  No *no6 = adiciona(arvore,no7,6);
  No *no8 = adiciona(arvore,no7,8);

  no7->esquerda = no6;
  no7->direita = no8;

  percorre(arvore->raiz);

  printf("\n");

  return 0;
}


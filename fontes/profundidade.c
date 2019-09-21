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
  if (no != NULL) {
    printf("%f ", no->v);
    percorre(no->esquerda);
    percorre(no->direita);
  }
}

int main(void) {
  Arvore *arvore = cria();

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

  percorre(no3);

  printf("\n");

  return 0;
}


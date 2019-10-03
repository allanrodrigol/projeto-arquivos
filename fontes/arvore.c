#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
  struct no *pai;
  struct no *esquerda;
  struct no *direita;
  void *v;
} No;

typedef struct arvore {
  No *raiz;
  int tamanho;
} Arvore;

Arvore* cria(int tamanho) {
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  arvore->tamanho = tamanho;
  
  return arvore;
}

int vazia(Arvore *arvore) {
  return (arvore->raiz == NULL);
}

No* adiciona(Arvore *arvore, No *pai, void *valor) {
  No *no = malloc(sizeof(No));
  no->pai = pai;
  
  no->esquerda = NULL;
  no->direita = NULL;
  
  no->v = malloc(arvore->tamanho);
  memcpy(no->v,valor,arvore->tamanho);

  if (pai == NULL)
    arvore->raiz = no;
  
  return no;
}

void percorre(No* no, void (visita)(void *valor)) {
  if (no != NULL) {
    visita(no->v);

    percorre(no->esquerda, visita);
    percorre(no->direita, visita);
  }
}

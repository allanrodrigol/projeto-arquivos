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

  int (*compara)(void *, void *);
} Arvore;

Arvore* cria(int tamanho, int (compara)(void *, void *) ) {
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  arvore->tamanho = tamanho;
  arvore->compara = compara;
  
  return arvore;
}

int vazia(Arvore *arvore) {
  return (arvore->raiz == NULL);
}

No* localiza(Arvore *arvore, No *no, void *valor) {
  if (arvore->compara(valor,no->v) > 0) {
    if (no->direita != NULL) {
      return localiza(arvore, no->direita, valor);
    }
  } else {
    if (no->esquerda != NULL) {
      return localiza(arvore, no->esquerda, valor);
    }
  }

  return no;
}

No* adiciona(Arvore *arvore, void *valor) {
  No *pai = NULL;

  if (arvore->raiz != NULL) {
    pai = localiza(arvore, arvore->raiz, valor);
  }

  No *no = malloc(sizeof(No));
  no->pai = pai;
  
  no->esquerda = NULL;
  no->direita = NULL;
  
  no->v = malloc(arvore->tamanho);
  memcpy(no->v,valor,arvore->tamanho);

  if (pai == NULL) {
    arvore->raiz = no;
  } else {
    if (arvore->compara(no->v,pai->v) > 0) {
      pai->direita = no;
    } else {
      pai->esquerda = no;
    }
  }
  
  return no;
}

void percorre(No* no, void (visita)(void *valor)) {
  if (no != NULL) {
    visita(no->v);

    percorre(no->esquerda, visita);
    percorre(no->direita, visita);
  }
}

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

No* localiza(No *no, void *valor, int (compara)(void *v1, void *v2)) {
  if (compara(valor,no->v) > 0) {
    if (no->direita == NULL) {
      return no;
    } else {
      return localiza(no->direita, valor, compara);
    }
  } else {
    if (no->esquerda == NULL) {
      return no;
    } else {
      return localiza(no->esquerda, valor, compara);
    }
  }
}

No* adiciona(Arvore *arvore, void *valor, int (compara)(void *v1, void *v2)) {
  No *pai = NULL;
  
  if (arvore->raiz != NULL) {
    pai = localiza(arvore->raiz, valor, compara);
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
    if (compara(no->v,pai->v) > 0) {
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

#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

void exibe(void *);
int compara(void *, void *);

int main(void) {
  Arvore *arvore = cria(sizeof(int), compara);

  int valor = 5;
  adiciona(arvore, &valor);

  valor = 3;
  adiciona(arvore, &valor);

  valor = 7;
  adiciona(arvore, &valor);

  valor = 2;
  adiciona(arvore, &valor);

  valor = 4;
  adiciona(arvore, &valor);

  valor = 6;
  adiciona(arvore, &valor);

  valor = 8;
  adiciona(arvore, &valor);

  percorre(arvore->raiz, exibe);
  printf("\n");

  return 0;
}

int compara(void *v1, void *v2) {
  if (*(int*) v1 > *(int*) v2) {
    return 1;
  } else if (*(int*) v1 == *(int*) v2) {
    return 0;
  } else {
    return -1;
  }
}

void exibe(void *valor) {
  printf("%d ",* (int*) valor);
}

#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

void exibe(void *valor);

int main(void) {
  Arvore *arvore = cria(sizeof(int));

  int valor = 5;
  No *no5 = adiciona(arvore, NULL, &valor);

  valor = 3;
  No *no3 = adiciona(arvore,no5,&valor);

  valor = 7;
  No *no7 = adiciona(arvore,no5,&valor);

  no5->esquerda = no3;
  no5->direita = no7;

  valor = 2;
  No *no2 = adiciona(arvore,no3,&valor);

  valor = 4;
  No *no4 = adiciona(arvore,no3,&valor);

  no3->esquerda = no2;
  no3->direita = no4;

  valor = 6;
  No *no6 = adiciona(arvore,no7,&valor);

  valor = 8;
  No *no8 = adiciona(arvore,no7,&valor);

  no7->esquerda = no6;
  no7->direita = no8;

  percorre(arvore->raiz, exibe);
  printf("\n");

  return 0;
}

void exibe(void *valor) {
  printf("%d ",* (int*) valor);
}

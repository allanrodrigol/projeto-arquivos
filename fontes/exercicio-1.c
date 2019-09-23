#include <stdio.h>
#include <stdlib.h>

/**
 * Dado um vetor de números inteiros v de tamanho n e um número k, retorne
 * verdadeiro se a soma de qualquer par de números em v for igual a k.
 * Exemplo: dado v = [10,15,3,7] e k = 17, a saída deve ser true, pois 10 + 7 é 17.
 */
int soma(int *v, int tamanho, int soma) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (v[i] + v[j] == soma) {
                return 1;
            }
        }
    }
    
    return 0;
}

int main() {
    int v[4] = {10,15,3,7};

    printf("%s\n",soma(v,4,17) ? "true" : "false");
}
	

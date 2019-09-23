#include <stdio.h>
#include <stdlib.h>

/**
 * Dado um vetor de números inteiros v, retorne um novo vetor de forma que
 * cada elemento no índice i seja o produto de todos os números na matriz
 * original, com exceção de i.
 * Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24].
 * Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6].
 *
 */
int* multiplica(int *v, int tamanho) {
    int *r = malloc(sizeof(int) * tamanho);
		
    for (int i = 0; i < tamanho; i++) {
        r[i] = 1;
        
        for (int j = 0; j < tamanho; j++) {
            if (i != j) {
                r[i] *= v[j];
            }
        }
    }
		
    return r;
}
	
void imprime(int *v, int tamanho) {
	printf("[");
		
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d,", v[i]);
    }
		
    if (tamanho > 0) {
        printf("%d", v[tamanho - 1]);
    }
		
	printf("]\n");
}

int main() {
    int v1[] = {1,2,3,4,5};
    imprime(multiplica(v1,5),5);
    
    int v2[] = {3,2,1};
    imprime(multiplica(v2,3),3);
}

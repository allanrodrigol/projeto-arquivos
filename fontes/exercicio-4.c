#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Dado um vetor inteiros v, retorne a maior soma dos números não adjacentes. Os
 * números podem incluir 0 ou negativos no vetor.
 * Exemplo 1, dado v = [2,4,6,2,5], a saída esperada é 13, considerando 2 + 6 + 5
 * Exemplo 2, dado v = [5,1,1,5], a saída esperada é 10, considerando 5 + 5
 */
	
void imprime(int *v, int tamanho) {
    printf("[");
    
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d,",v[i]);
    }
    
    if (tamanho > 0) {
        printf("%d",v[tamanho - 1]);
    }
    
    printf("]\n");
}

int soma(int *v, int tamanho) {
	int total = pow(2, tamanho);
    int **m = malloc(sizeof(int*) * total);

    for (int i = 0; i < total; i++) {
        m[i] = malloc(sizeof(int) * tamanho);
    }

    for (int j = 0; j < tamanho; j++) {
        int c = 0;
        int b = 0;
        
        for (int i = 0; i < total; i++) {
            m[i][j] = b ? v[j] : 0;
            c++;
            
            if (c == pow(2, j)) {
                c = 0;
                b = !b;
            }
        }
    }

    int maior = 0;
    int k = 0;
    
    for (int i = 0; i < total; i++) {
        int adjacente = 0;
        
        for (int j = 0; j < tamanho - 1; j++) {
            if (m[i][j] != 0 && m[i][j + 1] != 0) {
                adjacente = 1;
                break;
            }
        }
        
        if (adjacente) {
            continue;
        }
        
        int soma = 0;
        
        for (int j = 0; j < tamanho; j++) {
            soma += m[i][j];
        }
        
        if (soma > maior) {
            maior = soma;
            k = i;
        }
    }

    imprime(m[k], tamanho);
    
    return maior;
}

int main() {
    int v1[] = {2,4,6,2,5};
	printf("%d\n", soma(v1,5));

    int v2[] = {5,1,1,5};
	printf("%d\n", soma(v2,4));
}

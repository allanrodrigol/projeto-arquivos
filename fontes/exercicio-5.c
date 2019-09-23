#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Considere uma escadaria com n degraus e você pode subir 1 ou 2 degraus por
 * vez. Dado n, retorne o número de maneiras únicas de subir a escada.
 * Exemplo, dado n = 4, existem 5 maneiras exclusivas
 * [1,1,1,1], [2,1,1], [1,2,1], [1,1,2], [2, 2]
 */
	
void imprime(int* v, int limite) {
    printf("[");
		
    for (int i = 0; i < limite - 1; i++) {
        printf("%d,", v[i]);
    }
    
    if (limite > 0) {
        printf("%d", v[limite - 1]);
    }
    
    printf("]\n");
}
	
void degrau(int n) {
    int* v = malloc(sizeof(int) * n);
		
    for (int i = 0; i < n; i++) {
        v[i] = 1;
    }
		
    imprime(v, n);
    free(v);

    int total = pow(2, n - 1);
    int** m = malloc(sizeof(int*) * total);
		
    for (int i = 0; i < total; i++) {
        m[i] = malloc(sizeof(int) * (n - 1));
    }
		
    for (int j = 0; j < n - 1; j++) {
        int c = 0;
        int b = 0;
        
        for (int i = 0; i < total; i++) {
            m[i][j] = b ? 1 : 2;
            c++;
            
            if (c == pow(2, j)) {
                c = 0;
                b = !b;
            }
        }
    }
    
    for (int i = 0; i < total; i++) {
        int soma = 0;
        int limite;
        
        for (limite = 0; limite < n - 1; limite++) {
            if (soma + m[i][limite] > n) {
                break;
            }
            
            soma += m[i][limite];
        }
        
        if (soma == n) {
            if (i < pow(2, limite)) {
                imprime(m[i], limite);
            }
        }
    }
}

int main() {
    degrau(4);
}

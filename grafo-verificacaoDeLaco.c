#include <stdio.h>
#include <stdlib.h>
#define ORDEM_MATRIZ 3

int** criarMatrizAdjacencia(int quantidadeVertices){
    int ordemMatriz = quantidadeVertices, linha, coluna, **matriz;
    matriz = (int**)malloc(ordemMatriz * sizeof(int*));
    for(linha = 0; linha < ordemMatriz; linha++){
        matriz[linha] = (int*)malloc(ordemMatriz * sizeof(int));
    }
    
    for(linha = 0; linha < ordemMatriz; linha++){
        for (coluna = 0; coluna < ordemMatriz; coluna++){
            matriz[linha][coluna] = 0;
        }
    }
    return matriz;
}

void funcao(int **matriz, int *n, int *m){
    int i, j, terLaco = 0;

    for(i = 0; i < *n; i++){
        for(j = 0; j < *n; j++){
            if((i == j) && (matriz[i][j] == 1)){
                terLaco = 1;
            }
        }
    }
    if(terLaco){
        printf("O grafo possui laço!\n");
    }
    else{
        printf("O grafo não possui laço!\n");
    }
}

int main(){
    
    int n = 3, m = 4,**matriz;
    
    matriz = criarMatrizAdjacencia(ORDEM_MATRIZ);

    matriz[0][0] = 0;
    matriz[0][1] = 0;
    matriz[0][2] = 1;
    matriz[1][0] = 1;
    matriz[1][1] = 0;
    matriz[1][2] = 0;
    matriz[2][0] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 0;

    funcao(matriz, &n, &m);

    return 0;
}
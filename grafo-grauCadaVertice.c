#include <stdio.h>
#include <stdlib.h>

int** criarMatrizIncidencia(int quantidadeVertices, int quantidadeArestas){
    int linha, coluna, **matriz;
    matriz = (int**)malloc(quantidadeArestas * sizeof(int*));
    for(linha = 0; linha < quantidadeVertices; linha++){
        matriz[linha] = (int*)malloc(quantidadeArestas * sizeof(int));
    }
    
    for(linha = 0; linha < quantidadeVertices; linha++){
        for (coluna = 0; coluna < quantidadeArestas; coluna++){
            matriz[linha][coluna] = 0;
        }
    }
    return matriz;
}

void funcao(int **matriz, int *n, int *m){
    int i, j, vetorGraus[*n];
    
    for(i = 0; i < *n; i++){
        vetorGraus[i] = 0;
    }

    for(i = 0; i < *n; i++){
        for (j = 0; j < *m; j++){
            if(matriz[i][j] == 1){
                vetorGraus[i] +=1;
            }
        }
    }

    for(i = 0; i< *n; i++){
        printf("Grau do vértice %d: %d\n", i+1, vetorGraus[i]);
    }
}

int main(){
    
    int n = 4, m = 5,**matriz;
    
    matriz = criarMatrizIncidencia(4,5);

    matriz[0][0] = 1;
    matriz[0][1] = 1;
    matriz[0][2] = 1;
    matriz[0][3] = 0;
    matriz[0][4] = 0;

    matriz[1][0] = 1;
    matriz[1][1] = 0;
    matriz[1][2] = 0;
    matriz[1][3] = 1;
    matriz[1][4] = 0;

    matriz[2][0] = 0;
    matriz[2][1] = 1;
    matriz[2][2] = 0;
    matriz[2][3] = 1;
    matriz[2][4] = 1;

    matriz[3][0] = 0;
    matriz[3][1] = 0;
    matriz[3][2] = 1;
    matriz[3][3] = 0;
    matriz[3][4] = 1;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    funcao(matriz, &n, &m);

    return 0;
}
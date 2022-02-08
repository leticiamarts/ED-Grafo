#include <stdio.h>
#include <stdlib.h>

typedef struct Adjacentes{
    int vertice;
    struct Adjacentes *adjacente;
}Adjacentes;

typedef struct{
    int totalVertices;
    Adjacentes **listaAdjacentes;
}Lista;


Lista* criarLista(int quantidadeVertices){
    
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->totalVertices = quantidadeVertices;
    lista->listaAdjacentes = (Adjacentes **)malloc((quantidadeVertices+2) * sizeof(Adjacentes*));

	for (int i = 1; i <= quantidadeVertices; i++){
        lista->listaAdjacentes[i] = NULL;
    }
    

	return lista;
}

void conexao(Lista *lista, int verticeA, int verticeB){
	Adjacentes *novaAresta = (Adjacentes *)malloc(sizeof(Adjacentes));
    Adjacentes *aux;

    novaAresta->vertice = verticeB;
    if(lista->listaAdjacentes[verticeA] == NULL){
        lista->listaAdjacentes[verticeA] = novaAresta;
        
    }
    else{
        aux = lista->listaAdjacentes[verticeA];
        while(aux->adjacente != NULL){
            aux = aux->adjacente;
        }
        aux->adjacente = novaAresta;
    }
    
    novaAresta->adjacente = NULL;
	aux = lista->listaAdjacentes[verticeA];

}

void exibirLista(Lista *lista){
    int i;
	for (i = 1; i <= lista->totalVertices; i++){
		Adjacentes *aux = lista->listaAdjacentes[i];
		printf("\n Lista de adjacencias do vertice %d:\n ", i);
		while (aux != NULL){
			if(aux->adjacente != NULL){
                printf(" %d  -> ", aux->vertice);
            }
            else{
                printf(" %d ", aux->vertice);
            }
			aux = aux->adjacente;
		}
		printf("\n");
	}
}

int** criarMatrizAdjacencia(int quantidadeVertices){
    int ordemMatriz = quantidadeVertices, linha, coluna, **matriz;
    matriz = (int**)malloc(ordemMatriz * sizeof(int*));
    for(linha = 0; linha <= ordemMatriz; linha++){
        matriz[linha] = (int*)malloc(ordemMatriz * sizeof(int));
    }
    
    for(linha = 0; linha <= ordemMatriz; linha++){
        for (coluna = 1; coluna<= ordemMatriz; coluna++){
            matriz[linha][coluna] = 0;
        }
    }
    return matriz;
}

int** criarMatrizIncidencia(int quantidadeVertices, int quantidadeArestas){
    int ordemMatriz = quantidadeVertices, linha, coluna, **matriz;
    matriz = (int**)malloc(quantidadeArestas * sizeof(int*));
    for(coluna = 0; coluna <= quantidadeArestas; coluna++){
        matriz[coluna] = (int*)malloc((quantidadeArestas+1) * sizeof(int));
    }

    for(linha = 0; linha <= ordemMatriz; linha++){
        for (coluna = 0; coluna<= quantidadeArestas; coluna++){
            matriz[linha][coluna] = 0;
        }
    }
   
    return matriz;
}

int** preencherMatrizAdjacente(int **matriz, int verticeA, int verticeB, int quantidadeVertices){
    int ordemMatriz = quantidadeVertices, linha, coluna;
    
    for(linha = 1; linha <= ordemMatriz; linha++){
        for (coluna = 1; coluna<= ordemMatriz; coluna++){
            if((linha == verticeA) && (coluna == verticeB)){
                matriz[linha][coluna] = 1;
            }
        }
    }

    for(linha = 1; linha <= ordemMatriz; linha++){
        for (coluna = 1; coluna<= ordemMatriz; coluna++){
            if((linha == verticeB) && (coluna == verticeA)){
                matriz[linha][coluna] = 1;
            }
        }
    }
    
    return matriz;
}

int** preencherMatrizIncidente(int **matriz, int verticeA, int verticeB, int quantidadeVertices, int quantidadeArestas, int arestaAtual){
    int ordemMatriz = quantidadeVertices, linha, coluna;

    for (coluna = arestaAtual; coluna <= arestaAtual; coluna++){
        for(linha = 1; linha <= ordemMatriz; linha++){
            if(linha == verticeA){
                matriz[linha][coluna] = 1;
            }
            if(linha == verticeB){
                matriz[linha][coluna] = 1;
            }
        }  
    }
    
    return matriz;
}

void exibirMatrizAdjacencia(int **matriz, int quantidadeVertices){
    int ordemMatriz = quantidadeVertices, linha, coluna;
    for(linha = 0; linha <= ordemMatriz; linha++){
        for(coluna = 0; coluna<= quantidadeVertices; coluna++){
            if(coluna == 0){
                printf(" %d| ", matriz[linha][coluna]);
            }
            else{
                printf(" %d ", matriz[linha][coluna]);
            }
        }
        if(linha == 0){
            printf("\n----------------------------");
        }
        printf("\n");
    }
    printf("\n");
}

void exibirMatrizIncidencia(int **matriz, int quantidadeVertices, int quantidadeArestas, int *vetorVerticesA, int *vetorVerticesB){
    int ordemMatriz = quantidadeVertices, linha, coluna, j;

    for(int j = 0; j < quantidadeArestas; j++){
        if(j == 0){
            printf("     ");
        }
        printf("{%d,%d} ", vetorVerticesA[j], vetorVerticesB[j]);
    }
    printf("\n");

    for(linha = 1; linha <= ordemMatriz; linha++){
        for(coluna = 0; coluna<= quantidadeArestas; coluna++){
            if(linha == 0){
                printf(" %d    ", matriz[linha][coluna]);
            }
            else{
                printf(" %d    ", matriz[linha][coluna]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void criarMargemMatrizAdjacencia(int **matriz, int quantidadeVertices){
    int ordemMatriz = quantidadeVertices, linha, coluna;

    for(linha = 0; linha<=0; linha++){
        for (coluna = 1; coluna<= ordemMatriz; coluna++){
            matriz[linha][coluna] = coluna;
        }
    }

    for(coluna = 0; coluna<=0; coluna++){
        for (linha = 1; linha<= ordemMatriz; linha++){
            matriz[linha][coluna] = linha;
        }
    }
   matriz[0][0] = 0;
}

void criarMargemMatrizIncidencia(int **matriz, int quantidadeVertices, int quantidadeArestas){
    int linha, coluna;

    for(coluna = 0; coluna <=0; coluna++){
        for (linha = 1; linha <= quantidadeVertices; linha++){
            matriz[linha][coluna] = linha;
        }
    }  
}

int main(){
    
    int quantidadeVertices, quantidadeArestas, verticeA, verticeB, arestaAtual = 1, i=0;
    FILE *grafo;

    grafo = fopen("Grafo.txt", "r");

    if(grafo == NULL){
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }
    fscanf(grafo, "%d" "%d", &quantidadeVertices, &quantidadeArestas);
    Lista *lista;
    lista = criarLista(quantidadeVertices);

    int **matrizAdjacencia, **matrizIncidencia;

    int vetorVerticesA[quantidadeArestas], vetorVerticesB[quantidadeArestas];

    matrizAdjacencia = criarMatrizAdjacencia(quantidadeVertices);
    matrizIncidencia = criarMatrizIncidencia(quantidadeVertices, quantidadeArestas);
    
    while(!feof(grafo)){
        fscanf(grafo, "%d" "%d", &verticeA, &verticeB);
        conexao(lista, verticeA, verticeB);
        conexao(lista, verticeB, verticeA);
        vetorVerticesA[i] = verticeA;
        vetorVerticesB[i] = verticeB;
        i++;
        matrizAdjacencia = preencherMatrizAdjacente(matrizAdjacencia, verticeA, verticeB,  quantidadeVertices);
        
        preencherMatrizIncidente(matrizIncidencia, verticeA, verticeB, quantidadeVertices, quantidadeArestas, arestaAtual);
        arestaAtual += 1;
    }
    fclose(grafo);

    criarMargemMatrizAdjacencia(matrizAdjacencia, quantidadeVertices);                 
    criarMargemMatrizIncidencia(matrizIncidencia, quantidadeVertices, quantidadeArestas);
    
    printf("--LISTA DE ADJACÊNCIA:--\n");
    exibirLista(lista);
    
    printf("--MATRIZ DE ADJACÊNCIA:--\n");
    exibirMatrizAdjacencia(matrizAdjacencia, quantidadeVertices);

    printf("--MATRIZ DE INCIDÊNCIA:--\n");
    exibirMatrizIncidencia(matrizIncidencia, quantidadeVertices, quantidadeArestas, vetorVerticesA, vetorVerticesB);

    return 0;
}

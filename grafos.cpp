#include "grafos.h"


//seta todos os valores da matriz com -1, que representa infinito
void inicializaMatrizAdjacencia(Grafo *graf){
    for(int linha = 0; linha < graf->numVertices; linha++){
        for(int coluna = 0; coluna < graf->numVertices; coluna++) {
            graf->matrizAdjacencia[linha][coluna] = -1;
        }
    }
};

//preenche na matriz adjacencia os valores das arestas dadas pelo arquivo
void preencheMatrizAdjacencia(Grafo *graf, ifstream *arquivo){

    int numArestas = 0, vertice1 = 0, vertice2 = 0, peso = -1;

    //primeiro valor do arquivo diz quantidade de vertices
    *arquivo >> graf->numVertices;
    inicializaMatrizAdjacencia(graf);

    //segundo valor do arquivo diz quantidade de arestas
    *arquivo >> numArestas;

    cout << "Lendo a matriz.....";
    //a estrutura da linha tem 3 valores, os dois primeiros os numeros dos vertices
    //e o terceiro o peso da aresta que os liga
    for(int linha = 0; linha < numArestas; linha++){
        *arquivo >> vertice1;
        *arquivo >> vertice2;
        *arquivo >> peso;
        //coloca o valor do peso na matriz adjacencia nos posicoes
        //do primeiro ao segundo vertice e vice versa
        graf->matrizAdjacencia[vertice1][vertice2] = peso;
        graf->matrizAdjacencia[vertice2][vertice1] = peso;
    }

    cout << "OK" << endl;
};

void printMatrizAdjacencia(Grafo graf){
    cout << "  \t";
    for (int nodo = 0; nodo < graf.numVertices; nodo++){
        cout << " " << nodo << "|\t";
    }
    cout << endl;
    for(int linha = 0; linha < graf.numVertices; linha++){
        cout << linha << "|\t";
        for(int coluna = 0; coluna < graf.numVertices; coluna++) {
            if(linha == coluna)
                cout << " 0\t";
            else if(graf.matrizAdjacencia[linha][coluna] == -1)
                cout << " i\t";
            else if(graf.matrizAdjacencia[linha][coluna] < 10)
                cout << " " <<graf.matrizAdjacencia[linha][coluna] << "\t";
            else
                cout << graf.matrizAdjacencia[linha][coluna] << "\t";

        }
        cout << endl;
    }

    cout << endl;

};

//retorna -1 caso nao seja infinito
int distancia(Grafo graf, int vertice1, int vertice2){
    return graf.matrizAdjacencia[vertice1][vertice2];
}

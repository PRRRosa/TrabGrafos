#ifndef TRABALHO_GRAFOS_GRAFOS_H
#define TRABALHO_GRAFOS_GRAFOS_H
#include <iostream>
#include <fstream>
using namespace std;


typedef struct grafo{
    int numVertices;
    int matrizAdjacencia[100][100];
} Grafo;

void inicializaMatrizAdjacencia(Grafo *graf);
void preencheMatrizAdjacencia(Grafo *graf, ifstream *arquivo);
void printMatrizAdjacencia(Grafo graf);
int distancia(Grafo graf, int vertice1, int vertice2);

#endif //TRABALHO_GRAFOS_GRAFOS_H

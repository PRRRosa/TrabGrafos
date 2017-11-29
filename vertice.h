#ifndef TRABALHO_GRAFOS_VERTICE_H
#define TRABALHO_GRAFOS_VERTICE_H
#include <iostream>
#include <fstream>
#include "grafos.h"

using namespace std;

typedef struct vertice{
    int anterior;
    int distanciaOrigem;
    bool nuvem;
} Vertice;


void inicializaVertices(Vertice *vertices, Grafo graf, int source);
void printVertices(Vertice *vertices, int tamanho);
int verticeMenorDistancia(int source, int tamanho, Vertice *vertices);
void atualizaDistancias(Vertice *vertices, Grafo graf, int source);
#endif //TRABALHO_GRAFOS_VERTICE_H

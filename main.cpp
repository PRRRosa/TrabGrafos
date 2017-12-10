#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "vertice.h"

using namespace std;


//seta todos as arestas para fora da nuvem
void inicializaNuvem(Vertice *vertices, int tamanho){
    for(int indice = 0; indice < tamanho; indice++){
        vertices[indice].nuvem = false;
    }
}

void printNuvem(Vertice *vertice, int tamanho){
    cout << "Nuvem: { ";
    for(int indice = 0; indice < tamanho; indice++){
        if(vertice[indice].nuvem){
            cout << " "<<indice;
        }
    }
    cout << " }" << endl;
}

//retorna true caso encontre uma aresta marcada como nao visitada
//caso nao encontre, retorna false
bool temArestasNaoVisitadas(Vertice *vertices, int tamanho){
    for(int indice = 0; indice < tamanho; indice++){
        if(vertices[indice].nuvem == false)
            return true;
    }
    return false;
}

void printDistanciaOrigem(Vertice *vertice, int vert){
        cout << "Distancia de " << vert << " e " << vertice[vert].distanciaOrigem << endl;
}
int dijkstra(Grafo graf, int source, int target, int modo){
    Vertice vertices[100]; //array com as distanciaOrigem para o source
    int verticeAux, temp;
    inicializaNuvem(vertices, graf.numVertices);

    if(source < graf.numVertices && target < graf.numVertices){
        if(source == target){
            return 0;
        }
        else{
            //verifica distancias de source para os vertices
            inicializaVertices(vertices, graf, source);
            vertices[source].nuvem = true; //marca como nuvem
            verticeAux = source;

            if (modo == 2){ //se estiver no modo passo a passo
                printDistanciaOrigem(vertices, source);
                printNuvem(vertices, graf.numVertices);
                printVertices(vertices, graf.numVertices);
            }

            while(vertices[target].nuvem == false &&
                    temArestasNaoVisitadas(vertices, graf.numVertices)){

                temp =  verticeMenorDistancia(verticeAux, graf.numVertices, vertices);
                //se temp foi igual a vertice significa que nao existem mais caminhos a serem percorridos
                if(temp != verticeAux) {
                    verticeAux = temp;
                    vertices[verticeAux].nuvem = true; //marca como nuvem
                    atualizaDistancias(vertices,graf, verticeAux);

                    if (modo == 2){     //se estiver no modo passo a passo
                        printDistanciaOrigem(vertices, verticeAux);
                        printNuvem(vertices, graf.numVertices);
                        printVertices(vertices, graf.numVertices);
                    }
                }
                else{return -1;}

            }

            return vertices[target].distanciaOrigem;
        }
    }
    else
        return -1;
}

//mostra as distancias em modo direto
int resultado(Grafo graf, int source, int target, int modo){
    int distancia;
    distancia =  dijkstra(graf, source, target,modo);
    if(distancia == -1){
        cout << "A distancia entre os vertices e infinita" << endl;
    }
    else {
        cout << "A distancia minima entre " << source << " e " << target << " eh " << distancia << endl;
    }
    return 0;

}

void menu(Grafo graf){
    int modo = 0, source = 0, target = 0;
    cout << "DIJKSTRA" << endl;
    cout << "Encontrar distancia minima entre: " << endl;
    cout << "source: ";
    cin >> source;
    cout << "target: ";
    cin >> target;
    cout << "Escolha 1 para modo direto ou 2 para modo passo a passo" << endl;
    cin >> modo;
    if (modo == 1 || modo == 2){
            resultado(graf,source, target,modo);
    }
    else{
        cout <<"modo invalido" << endl;
        menu(graf);
    }
}

int main() {

    Grafo graf;

    //abre arquivo
    ifstream arquivo;
    arquivo.open("inst22n.dat");

    if(arquivo.fail()){
        cerr << "Falha ao abrir o arquivo!\n";
        exit(1);
    }

    graf.numVertices = -1;
    preencheMatrizAdjacencia(&graf, &arquivo);
    arquivo.close();

    menu(graf);

    return 0;
}

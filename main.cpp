#include <iostream>
#include <fstream>
#include "grafos.h"
#include "vertice.h"

using namespace std;

//seta todos as arestas para fora da nuvem
void inicializaNuvem(Vertice *vertices, int tamanho){
    for(int indice = 0; indice < tamanho; indice++){
        vertices[indice].nuvem = false;
    }
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


int dijkstra(Grafo graf, int source, int target){
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
            while(vertices[target].nuvem == false &&
                    temArestasNaoVisitadas(vertices, graf.numVertices)){

                temp =  verticeMenorDistancia(verticeAux, graf.numVertices, vertices);
                //se temp foi igual a vertice significa que nao existem mais caminhos a serem percorridos
                if(temp != verticeAux) {
                    verticeAux = temp;
                    vertices[verticeAux].nuvem = true; //marca como nuvem
                    atualizaDistancias(vertices,graf, verticeAux);
                }
                else{return -1;}

            }

            return vertices[target].distanciaOrigem;
        }
    }
    else
        return -1;
}


int main() {


    Grafo graf;
    int distancia;

    //abre arquivo
    ifstream arquivo;
    arquivo.open("Insts/inst1.dat");

    if(arquivo.fail()){
        cerr << "Falha ao abrir o arquivo!\n";
        exit(1);
    }

    graf.numVertices = -1;
    preencheMatrizAdjacencia(&graf, &arquivo);
    arquivo.close();

    int source = 0, target = 0;
    cout << "Encontrar distância mínima entre: " << endl;
    cout << "source: ";
    cin >> source;
    cout << "target: ";
    cin >> target;

    distancia =  dijkstra(graf, source, target);

    if(distancia == -1){
        cout << "A distância entre os vertices é infinita" << endl;
    }
    else {
        cout << "A distância mínima entre " << source << " e " << target << " é " << distancia << endl;
    }

    return 0;




}
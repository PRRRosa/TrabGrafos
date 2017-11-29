#include "vertice.h"

void inicializaVertices(Vertice *vertices, Grafo graf, int source){
    for(int indice = 0; indice < graf.numVertices; indice++){
        if(indice == source) {
            vertices[source].distanciaOrigem = 0;
            vertices[source].anterior = source;
        }
        else{
            vertices[indice].distanciaOrigem = distancia(graf, source, indice);
            vertices[indice].anterior = source;
        }

    }
}

//retorna a menor distanciaOrigem para o source
int verticeMenorDistancia(int source, int tamanho, Vertice *vertices){
    int menorDistancia = -1, menor = source, temp = 0;
    for(int indice = 0; indice < tamanho; indice++){
        temp = vertices[indice].distanciaOrigem;
        //se nao for a distanciaOrigem para um vertice ja nuvem
        //e nem a distanciaOrigem for de infinito
        if(vertices[indice].nuvem == false && temp != -1){
            if(menorDistancia == -1){
                menorDistancia = temp;
                menor = indice;
            }
            else if (temp < menorDistancia){
                        menorDistancia = temp;
                        menor = indice;
            }
        }
    }
    return menor;
}


void printVertices(Vertice *vertices, int tamanho){
    cout << "Vertices: {";
    for(int indice = 0; indice < tamanho; indice++){
        if(vertices[indice].distanciaOrigem == -1)
            cout << " ";
        else if(vertices[indice].distanciaOrigem < 10)
            cout << "  ";
        else
            cout << " ";
        cout << vertices[indice].distanciaOrigem;
    }
    cout << "}" << endl;
}

//atualiza as distancias entre as arestas e a aresta referencia
void atualizaDistancias(Vertice *vertices, Grafo graf, int source){
    int distanciaEntreVertices, distanciaAcumulada, distanciaVerticeOrigem;

    for(int indice = 0; indice < graf.numVertices; indice++){

        distanciaEntreVertices = graf.matrizAdjacencia[source][indice];
        //se houver uma aresta entre o source e o vertice atual

        if(distanciaEntreVertices != -1) {
            distanciaVerticeOrigem = vertices[indice].distanciaOrigem;
            distanciaAcumulada = vertices[source].distanciaOrigem + distanciaEntreVertices;
            //se a distanciaOrigem atual em vertices for maior que a
            //distanciaOrigem acumulada de source para atual + atual até a origem
            //atualiza a distanciaOrigem

            if(distanciaVerticeOrigem == -1){
                vertices[indice].anterior = source;
                vertices[indice].distanciaOrigem = distanciaAcumulada;
            }
            else if (distanciaVerticeOrigem > distanciaAcumulada){
                vertices[indice].anterior = source;
                vertices[indice].distanciaOrigem = distanciaAcumulada;
            }
        }
    }
}
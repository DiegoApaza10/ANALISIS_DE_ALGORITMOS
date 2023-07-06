#include <iostream>
#include <vector>
#include <algorithm>

// Clase para representar un grafo ponderado
class Grafo {
private:
    int numVertices;
    std::vector<std::vector<int>> matrizAdyacencia;

public:
    Grafo(int n) : numVertices(n) {
        matrizAdyacencia.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void agregarArista(int u, int v, int peso) {
        matrizAdyacencia[u][v] = peso;
        matrizAdyacencia[v][u] = peso;
    }

    void imprimirGrafo() {
        std::cout << "Grafo inicial:" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << matrizAdyacencia[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
	
    void imprimirTour(const std::vector<int>& tour) {
        std::cout << "Grafo del resultado obtenido:" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << matrizAdyacencia[tour[i]][tour[j]] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<int> tspVoraz() {
        std::vector<int> tour;
        std::vector<bool> visitado(numVertices, false);
        int verticeActual = 0; // Comenzar desde el vértice 0

        tour.push_back(verticeActual);
        visitado[verticeActual] = true;

        while (tour.size() < numVertices) {
            int siguienteVertice = -1;
            int distanciaMinima = INT_MAX;

            // Encontrar el vértice más cercano no visitado
            for (int i = 0; i < numVertices; i++) {
                if (!visitado[i] && matrizAdyacencia[verticeActual][i] < distanciaMinima) {
                    distanciaMinima = matrizAdyacencia[verticeActual][i];
                    siguienteVertice = i;
                }
            }

            if (siguienteVertice != -1) {
                tour.push_back(siguienteVertice);
                visitado[siguienteVertice] = true;
                verticeActual = siguienteVertice;
            }
        }

        return tour;
    }
};


int main() {
    // Crear un grafo de ejemplo
    Grafo grafo(5);
    grafo.agregarArista(0, 1, 10);
    grafo.agregarArista(0, 2, 15);
    grafo.agregarArista(0, 3, 20);
    grafo.agregarArista(0, 4, 25);
    grafo.agregarArista(1, 2, 35);
    grafo.agregarArista(1, 3, 45);
    grafo.agregarArista(1, 4, 55);
    grafo.agregarArista(2, 3, 30);
    grafo.agregarArista(2, 4, 40);
    grafo.agregarArista(3, 4, 50);

    // Mostrar el grafo inicial
    grafo.imprimirGrafo();

    // Obtener la ruta utilizando el algoritmo voraz
    std::vector<int> tour = grafo.tspVoraz();

    // Mostrar el grafo resultante
    grafo.imprimirTour(tour);

    return 0;
}


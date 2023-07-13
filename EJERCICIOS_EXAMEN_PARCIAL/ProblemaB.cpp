#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct Punto {
    int x;
    int y;
};

// Función de comparación para ordenar por coordenada X
bool compararPorX(const Punto& p1, const Punto& p2) {
    return p1.x < p2.x;
}

// Función de comparación para ordenar por coordenada Y
bool compararPorY(const Punto& p1, const Punto& p2) {
    return p1.y < p2.y;
}

// Función para calcular la distancia entre dos puntos
float distancia(const Punto& p1, const Punto& p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

//funcion recursiva para hallar la minima distancia
float distanciaMinimaRecursiva(vector<Punto>& puntos, int inicio, int fin) {
    // caso base
    if (fin - inicio <= 3) {//3 para la minima cantidad de puntos que pueden formar un triangulo
        float minDistancia = numeric_limits<float>::max();//garantiza que este sea maximo asi
        //al calcular la distancia este sera reemplazado
        for (int i = inicio; i < fin; i++) {
            for (int j = i + 1; j < fin; j++) {
                float dist = distancia(puntos[i], puntos[j]);
                minDistancia = min(minDistancia, dist);
            }
        }
        return minDistancia;
    }

    // divide el vector puntos
    int medio = (inicio + fin) / 2;
    Punto puntoMedio = puntos[medio];

    float distIzq = distanciaMinimaRecursiva(puntos, inicio, medio);
    float distDer = distanciaMinimaRecursiva(puntos, medio, fin);

    // Encuentra la distancia mínima entre las dos mitades
    float distanciaMinima = min(distIzq, distDer);

    // Crea un vector para almacenar los puntos cercanos al punto medio
    vector<Punto> puntosCerca;
    for (int i = inicio; i < fin; i++) {
        // Filtra los puntos que están a una distancia menor que distanciaMinima del punto medio en el eje X
        if (abs(puntos[i].x - puntoMedio.x) < distanciaMinima) {
            puntosCerca.push_back(puntos[i]);
        }
    }

    // Ordena los puntos cercanos por coordenada Y
    sort(puntosCerca.begin(), puntosCerca.end(), compararPorY);

    // Verifica las distancias entre los puntos cercanos en el eje Y
    for (int i = 0; i < puntosCerca.size(); i++) {
        for (int j = i + 1; j < puntosCerca.size() && (puntosCerca[j].y - puntosCerca[i].y) < distanciaMinima; j++) {
            float dist = distancia(puntosCerca[i], puntosCerca[j]);
            distanciaMinima = min(distanciaMinima, dist);
        }
    }

    return distanciaMinima;
}


float distanciaMinima(vector<Punto>& puntos) {
    // ordena los puntos por coordenada X
    sort(puntos.begin(), puntos.end(), compararPorX);
    // revursiva
    return distanciaMinimaRecursiva(puntos, 0, puntos.size());
}

int main() {
    int N;
    cin >> N;

    while (N != 0) {
        vector<Punto> puntos(N);
        for (int i = 0; i < N; i++) {
            cin >> puntos[i].x >> puntos[i].y;
        }

        // Calcula la distancia mínima entre los puntos
        float minDistancia = distanciaMinima(puntos);

        // Imprime el resultado de la distancia mínima
        if (minDistancia < 10000) {
            cout << fixed;
            cout.precision(4);
            cout << minDistancia << endl;
        } else {
            cout << "INFINITY" << endl;
        }

        cin >> N;
    }

    return 0;
}

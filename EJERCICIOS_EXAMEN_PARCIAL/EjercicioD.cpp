#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segmento {
    int izquierda;
    int derecha;
};

bool compararSegmentos(const Segmento& seg1, const Segmento& seg2) {
    return seg1.izquierda < seg2.izquierda; // Ordenar por coordenada izquierda
}

int seleccionarSegmentos(int M, vector<Segmento>& segmentos) {
    sort(segmentos.begin(), segmentos.end(), compararSegmentos); // Ordenar segmentos

    int contador = 0; //contador para el número de segmentos seleccionados
    int fin = 0; // extremo derecho actual del segmento seleccionado
    vector<Segmento> segmentosSeleccionados; // Segmentos seleccionados

    for (const Segmento& seg : segmentos) {
        if (seg.izquierda > fin) {
            // si hay un hueco sin cubrir entre los segmentos seleccionados y este segmento, no cubre el segmento
            return 0;
        }

        if (seg.derecha > fin) {
            // este segmento puede extender el alcance actual y cubrir más de [0, M]
            fin = seg.derecha;
            segmentosSeleccionados.push_back(seg);
            contador++;
        }
    }

    //segmentos seleccionados
    cout << contador << endl;
    for (const Segmento& seg : segmentosSeleccionados) {
        cout << seg.izquierda << " " << seg.derecha << endl;
    }

    return contador;
}

int main() {
    int numCasosPrueba;
    cin >> numCasosPrueba;

    for (int i = 0; i < numCasosPrueba; i++) {
        int M;
        cin >> M;

        vector<Segmento> segmentos;
        while (true) {
            int izq, der;
            cin >> izq >> der;
            if (izq == 0 && der == 0) {
                break;
            }

            segmentos.push_back({izq, der});
        }

        int resultado = seleccionarSegmentos(M, segmentos);

        if (i != numCasosPrueba - 1) {
            cout << endl; // Imprimir línea en blanco entre casos de prueba
        }
    }

    return 0;
}

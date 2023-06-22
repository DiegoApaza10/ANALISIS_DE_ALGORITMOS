#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& A, int num) {
    int pos_izq = 0;
    int pos_der = A.size() - 1;

    while (pos_izq <= pos_der) {
        int medio = pos_izq + (pos_der - pos_izq) / 2;

        if (A[medio] == num) {
            return medio;  // El elemento objetivo fue encontrado en la posición "mid"
        } else if (A[medio] < num) {
            pos_izq = medio + 1;  // El elemento objetivo está en la mitad derecha del subarreglo
        } else {
            pos_der = medio - 1;  // El elemento objetivo está en la mitad izquierda del subarreglo
        }
    }

    return -1;  // El elemento objetivo no se encuentra en la lista
}

int main() {
    vector<int> A = {1, 3, 5, 7, 9, 11, 13, 15};
    int num_a_buscar = 9;
    int pos = binarySearch(A, num_a_buscar);

    if (pos != -1) {
        cout << "El elemento " << num_a_buscar  << " se encuentra en la posicion " << pos << endl;
    } else {
        cout << "El elemento " << num_a_buscar  << " no se encuentra en la lista" << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;
// Funcion para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Funcion para seleccionar el pivote y realizar la partición
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Seleccionamos el último elemento como pivote
    int i = low - 1;  // Índice del elemento más pequeño
    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;  // Incrementamos el índice del elemento más pequeño
            swap(arr[i], arr[j]);  // Intercambiamos los elementos
        }
    }

    swap(arr[i + 1], arr[high]);  // Colocamos el pivote en su posición correcta
    return i + 1;  // Retornamos la posición del pivote
}

// Función recursiva para aplicar Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtenemos la posición del pivote después de la partición
        int pivot = partition(arr, low, high);

        // Ordenamos las subpartes izquierda y derecha del pivote de forma recursiva
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Función de utilidad para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Ejemplo de uso
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Arreglo original: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    std::cout << "Arreglo ordenado: ";
    printArray(arr, size);

    return 0;
}
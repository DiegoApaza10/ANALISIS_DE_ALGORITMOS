#include <iostream>
#include <vector>
using namespace std;
// Funcion para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int binarySearch(const vector<int>& A, int num) {
    int pos_izq = 0;
    int pos_der = A.size() - 1;

    while (pos_izq <= pos_der) {
        int medio = pos_izq + (pos_der - pos_izq) / 2;

        if (A[medio] == num) {
            return A[medio];  // El elemento objetivo fue encontrado en la posición "mid"
        } else if (A[medio] < num) {
            pos_izq = medio + 1;  // El elemento objetivo está en la mitad derecha del subarreglo
        } else {
            pos_der = medio - 1;  // El elemento objetivo está en la mitad izquierda del subarreglo
        }
    }

    return -1;  // El elemento objetivo no se encuentra en la lista
}

// Funcion para seleccionar el pivote y realizar la partición
int partition(vector<int>& arr, int low, int high) {
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
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Obtenemos la posición del pivote después de la partición
        int pivot = partition(arr, low, high);

        // Ordenamos las subpartes izquierda y derecha del pivote de forma recursiva
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Función de utilidad para imprimir el arreglo
void printArray(vector<int> arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int mediana(vector<int> arr, int size) 
{
	quickSort(arr, 0, arr.size() - 1);
	int tamanio=arr.size();
	if (tamanio%2 != 0) 
	{	
		return binarySearch(arr,arr[arr.size()/2]);
	}else
	{
		int tamanio_div=arr.size()/2;
		int x = binarySearch(arr,arr[arr.size()/2]);
		int y = binarySearch(arr,arr[arr.size()/2- 1]);
		return (x+y)/2;
	}
	
}
	


// Ejemplo de uso
int main() {
  	vector<int> B;
  	int x ;
  	while( cin>>x)
	{
		B.push_back(x);
		cout<<mediana(B,B.size())<<endl;
	}
  	

    return 0;
}
#include <iostream>

using namespace std;
//toma como parametro el arreglo , la posicion inicial
//la posicion media y la posicion final
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
	//se crean 2 subarreglos
    int leftArr[n1];
    int rightArr[n2];
	//se rellenan con los elementos
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;//recorre el arreglo izq
    int j = 0;//recorre el arreglo derecho
    int k = left;//recorre el arreglo original desde left
	
    while (i < n1 && j < n2){
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
//Toma como parametros el arreglo a ordenar
//El limite inicial 
//y el limite final
void mergeSort(int A[], int inicial, int final) {
    if (inicial < final) {
        int medio = inicial + (final - inicial) / 2; //redondea para abajo //2.5 = 2
		cout<<endl<<medio<<endl;
        mergeSort(A, inicial, medio);//Sub arreglo tomando la mitad izq
        mergeSort(A, medio + 1, final);//Sub arreglo tomando la mitad der

        merge(A, inicial, medio, final);//jutando ambos al final
    }
}

int main() {
    int A[] = {4, 2, 7, 1, 5, 3};
    int n = sizeof(A) / sizeof(A[0]); //numero de elementos
	cout<<endl<<n<<endl;
    mergeSort(A, 0, n - 1);

    cout << "Ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
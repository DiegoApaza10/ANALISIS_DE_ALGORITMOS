#include <iostream>
#include <vector>
using namespace std;

// Suma de dos matrices
vector<vector<int>> suma(const vector<vector<int>>& A,const vector<vector<int>>& B) {
    int n = A.size();//tamanio 
    //Matriz resultante nxn llena de ceros
    vector<vector<int>> resultado(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
    return resultado;
}
// Función para restar dos matrices
vector<vector<int>> resta(const vector<vector<int>>& A,const vector<vector<int>>& B) {
    int n = A.size();//tamanio 
    vector<vector<int>> resultado(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
    return resultado;
}

// Función para imprimir una matriz
void mostrar_matriz(const vector<vector<int>>& M) {
    int n = M.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para multiplicar matrices usando el algoritmo de Strassen
vector<vector<int>> multiplicar(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size(); //tamanio
    // Caso base: matrices 1x1
    if (n == 1) {
        vector<vector<int>> r(1, vector<int>(1, 0));//matriz 1x1
        r[0][0] = A[0][0] * B[0][0];
        return r;
    }
    //Se Dividen en submatrices mas pequeñas
    int mitad = n / 2; //matrices cuadradas de tamaño par 2,4,8,10,12,14...
    //matrices de tamaño mitad x mitad llena de 0's
    vector<vector<int>> A11(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A12(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A21(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A22(mitad, vector<int>(mitad, 0));

    vector<vector<int>> B11(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B12(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B21(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B22(mitad, vector<int>(mitad, 0));
	//SE EXTRAE LAS SUBMATRICES DE A Y B
    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mitad];
            A21[i][j] = A[i + mitad][j];
            A22[i][j] = A[i + mitad][j + mitad];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mitad];
            B21[i][j] = B[i + mitad][j];
            B22[i][j] = B[i + mitad][j + mitad];
        }
    }

    // Realiza las multiplicaciones recursivas de las submatrices

    vector<vector<int>> P1 = multiplicar(A11, resta(B12, B22));
    vector<vector<int>> P2 = multiplicar(suma(A11, A12), B22);
    vector<vector<int>> P3 = multiplicar(suma(A21, A22), B11);
    vector<vector<int>> P4 = multiplicar(A22, resta(B21, B11));
    vector<vector<int>> P5 = multiplicar(suma(A11, A22), suma(B11, B22));
    vector<vector<int>> P6 = multiplicar(resta(A12, A22), suma(B21, B22));
    vector<vector<int>> P7 = multiplicar(resta(A11, A21), suma(B11, B12));

    // Calcula las submatrices del resultado final

    vector<vector<int>> C11 = suma(resta(suma(P5, P4), P2), P6);
    vector<vector<int>> C12 = suma(P1, P2);
    vector<vector<int>> C21 = suma(P3, P4);
    vector<vector<int>> C22 = resta(resta(suma(P5, P1), P3), P7);

    // Combina las submatrices en la matriz resultante
    vector<vector<int>> resultado(n, vector<int>(n, 0));

    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            resultado[i][j] = C11[i][j];
            resultado[i][j + mitad] = C12[i][j];
            resultado[i + mitad][j] = C21[i][j];
            resultado[i + mitad][j + mitad] = C22[i][j];
        }
    }

    return resultado;
}


int main() {
    vector<vector<int>> A = { {4, 8}, {10, 4} };
    vector<vector<int>> B = { {6, 6}, {7, 12} };
 	cout<<"A: "<<endl;
    mostrar_matriz(A);
    cout<<"B: "<<endl;
    mostrar_matriz(B);
    vector<vector<int>> C = multiplicar(A, B);

    cout << "C =" << endl;
    mostrar_matriz(C);
  
   

    return 0;
}


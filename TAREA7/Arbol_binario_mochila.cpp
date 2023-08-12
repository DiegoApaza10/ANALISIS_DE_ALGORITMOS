#include <iostream>
#include <vector>

using namespace std;

int mochila_binaria(vector<int>& valores, vector<int>& pesos, int capacidad, int n, int indice) {
    if (indice >= n) {
        return 0;
    }
    
    // Excluimos el objeto actual y avanzamos al siguiente
    int sin_actual = mochila_binaria(valores, pesos, capacidad, n, indice + 1);
    
    if (pesos[indice] > capacidad) {
        return sin_actual;
    }
    
    // Incluimos el objeto actual y avanzamos al siguiente con capacidad reducida
    int con_actual = valores[indice] + mochila_binaria(valores, pesos, capacidad - pesos[indice], n, indice + 1);
    
    // Retornamos la opción con mayor valor
    return max(sin_actual, con_actual);
}

int main() {
    vector<int> valores = {10, 4, 7, 3};
    vector<int> pesos = {5, 3, 2, 1};
    int capacidad = 5;
    int n = valores.size();
    
    int max_valor = mochila_binaria(valores, pesos, capacidad, n, 0);
    cout << "Valor máximo: " << max_valor << endl;
    
    return 0;
}

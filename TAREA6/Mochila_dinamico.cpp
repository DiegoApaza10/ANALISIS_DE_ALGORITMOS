#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para resolver el Problema de la mochila utilizando programación dinámica
int mochila(int capacidad_mochila, const vector<int>& pesos, const vector<int>& valores) {
    int n = pesos.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacidad_mochila + 1, 0));

    // Llenar la tabla dp con los valores óptimos
    for (int i = 1; i <= n; i++) {
        for (int capacidad_actual = 1; capacidad_actual <= capacidad_mochila; capacidad_actual++) {
            // Verificar si el objeto actual puede ser incluido en la mochila
            if (pesos[i - 1] <= capacidad_actual) {
                // Si el objeto puede ser incluido, decidir si es mejor incluirlo o no
                dp[i][capacidad_actual] = max(valores[i - 1] + dp[i - 1][capacidad_actual - pesos[i - 1]], dp[i - 1][capacidad_actual]);
            } else {
                // Si el objeto no puede ser incluido, tomar el valor del objeto anterior
                dp[i][capacidad_actual] = dp[i - 1][capacidad_actual];
            }
        }
    }

    // El valor máximo en la última celda de la tabla representa la solución óptima
    return dp[n][capacidad_mochila];
}

int main() {
    int capacidad_mochila = 10;
    vector<int> pesos = {2, 3, 4, 5};
    vector<int> valores = {3, 4, 5, 6};

    int maxValor = mochila(capacidad_mochila, pesos, valores);
    cout << "Valor maximo en la mochila: " << maxValor << endl;

    return 0;
}
